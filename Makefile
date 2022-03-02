CC = gcc -Wall -Wextra -Werror

CCD = gcc -g -Wall -Wextra -Werror

NAME = cub3D

SRCS = cub3d.c cub3d_utils.c parse.c parse_more.c cube_init.c cube_init_more.c map.c map_validation.c map_valid_utils.c window.c window_utils.c window_key.c window_bmp.c window_bonus.c window_sprite.c window_process.c window_draw.c ./gnl/get_next_line.c ./gnl/get_next_line_utils.c

OBJS = $(SRCS:.c=.o)

DEPENDS = ${OBJS:.o=.d} 

HEAD = -I./gnl/

ifeq ($(OS),Windows_NT)
	detected_OS := Windows
else
	detected_OS := $(shell uname)
endif
ifeq ($(detected_OS),Linux)
	MAKES := ./libft/libft.a  mlx_linux/libmlx.a
	LIBMAKE := ./mlx_linux
	LIB :=  -L libft -lft -L ./mlx_linux -lmlx_Linux -lXext -lX11 -lm
	HEAD += -I./mlx_linux/
endif
#ifeq ($(detected_OS),Darwin) 
#	MAKES = ./libs/libft.a ./libs/minilibx_macos/libmlx.a 
#	LIBMAKE := libs/minilibx_macos
#	LIB := -L libft -lft -L libs/minilibx_macos -lmlx -framework OpenGL -framework Appkit
#	HEAD += -I./libs/minilibx_macos/
#endif

all: $(NAME) 

#%.o: %.c
#	$(CC) -c  $(HEAD) $<

$(MAKES):
	make -C  ./libft bonus
	make -sC  $(LIBMAKE)

-include ${DEPENDS}

$(NAME): $(MAKES) $(OBJS)
	$(CC) $(OBJS)  $(LIB) $(HEAD)  -o $(NAME)

debug: $(MAKES) $(OBJS)
	$(CCD) $(OBJS) $(LIB) $(HEAD) -o $(NAME)

clean:
	rm -f $(OBJS)
	rm -f *.d
	make -C libft clean

fclean: clean
	rm -f $(NAME)
	make -C libft fclean
	make -C $(LIBMAKE) clean

re: fclean all

red: fclean debug

.PHONY: clean fclean re
