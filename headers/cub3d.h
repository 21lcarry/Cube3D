#ifndef CUB3D_H
# define CUB3D_H
# include "../gnl/get_next_line.h"
# include <stdio.h>
# include "../mlx_linux/mlx.h"
# include "../libft/libft.h"
# include <math.h>
# define MOVE_SPEED 0.001
# define ROT_SPEED 0.0004
# define SPRITE_COLLISION '0'
# define R 0xFF
# define G 0xFF00
# define B 0xFF0000
# define V_RANGE 2
# define SHADOW_W 6
# define SHADOW_S 0.9
# define SHADOW_C 0.25
# define SHADOW_F 12
# define	CHMOD 0766
# define KEY_LEFT 65361
# define KEY_RIGHT 65363
# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100
# define KEY_ESC 65307
# define SCALE 16

typedef struct s_point
{
	int			x;
	int			y;
}				t_point;

typedef struct s_plr
{
	double		x;
	double		y;
	double		dirx;
	double		diry;
	double		olddirx;
	double		start;
	double		end;
	double		mov_s;
	double		rot_s;
}				t_plr;

typedef struct s_img
{
	void		*ptr;
	int			*addr;
	int			width;
	int			height;
	int			btp;
	int			s_line;
	int			endian;
}				t_img;

typedef struct s_win
{
	void		*mlx;
	void		*win;
	t_img		*img1;
	t_img		*img2;
}				t_win;

typedef struct s_key
{
	int			left;
	int			right;
	int			w;
	int			a;
	int			s;
	int			d;
}				t_key;

typedef struct s_sp
{
	double		*x;
	double		*y;
	double		*z_buf;
	int			*s_ord;
	double		*s_dst;
	double		spx;
	double		spy;
	double		invdet;
	double		trans_x;
	double		trans_y;
	int			s_scr_x;
	int			s_h;
	int			s_w;
	int			drawsx;
	int			drawsy;
	int			drawex;
	int			drawey;
	int			strp;
	int			t_x;
	int			t_y;
}				t_sp;

typedef struct s_cam
{
	double		planex;
	double		planey;
	double		oldplanex;
	double		camx;
	double		raydirx;
	double		raydiry;
	int			mapx;
	int			mapy;
	double		sidedstx;
	double		sidedsty;
	double		deltadstx;
	double		deltadsty;
	double		p_wall_dst;
	int			stepx;
	int			stepy;
	int			hit;
	int			side;
	int			line_h;
	int			draws;
	int			drawe;
	int			x;
	int			flag[50];
	int			oldr;
	int			oldg;
	int			oldb;
}				t_cam;

typedef struct s_drw
{
	int			t_x;
	int			t_y;
	int			t_dir;
	double		wall;
	double		t_step;
	double		t_pos;
}				t_drw;

typedef struct s_all
{
	t_win		*win;
	t_plr		*plr;
	t_img		*no;
	t_img		*so;
	t_img		*we;
	t_img		*ea;
	t_img		*sprite;
	t_key		*key;
	t_cam		*cam;
	t_drw		*draw;
	t_sp		*spr;	
	int			resx;
	int			resy;
	char		**map;
	int			map_size;
	int			colour_c;
	int			colour_f;
	int			fd;
	char		player;
	int			screen;
	int			sp_c;
	int			bonusc;
}				t_all;

int		ft_parse_resolution(char *line, t_all *conf);
int		ft_nblen(int nb);
int		ft_parse_colour(char *line, int *colour);
int		ft_str_isdigit(char *str);
int		ft_parse_str_colour(char **res, char *line);
int		ft_parse_texture(char *line, t_all *conf, char *id, t_img *img);
void	ft_parse_texture2 (char *line, t_all *conf, t_img *img, int i);
int		ft_check_duble(t_all conf, char *id);
void	ft_cube_init(char *path, int screen);
int		gnl_parse(char *line, t_all *conf, int count);
void	ft_init_conf(t_all *conf, int screen);
void	ft_exit(char *str);
int		ft_screen(char *arg, char *param);
int		ft_extension(char *arg, char *ext);
void	ft_init_textures(t_all *conf);
void	ft_conf_start(t_all *conf, int screen);
void	ft_start_img(t_img *img);
void	ft_start_win(t_win *window);
size_t	ft_comcount(const char *str);
int		ft_res_valid(char *line);
void	ft_start_key(t_key *key);
void	ft_start_plr(t_plr *plr);
void	ft_start_drw(t_drw *draw);
int		ft_find_first(t_all *conf);
int		ft_find_last(t_all *conf);
void	gnl_parse_map(t_all *conf, char *oldline);
int		ft_linemap_valid(char *line);
char	**ft_make_map(t_list **head, int size);
void	ft_zero(void *str);
void	ft_map_validation(t_all *conf);
void	ft_map_closed(char *line);
void	ft_check_cell2(char c);
void	ft_save_map(t_all *conf, int i, int j);
void	ft_sprite_init(t_all *conf);
void	ft_sprite_alloc(t_all *conf);
void	ft_validation_line(t_all *conf, int i);
void	ft_check_cell(t_all *conf, int i, int j);
void	ft_window_init(t_all *conf);
int		ft_close(t_all *conf);
int		ft_press(int keycode, t_all *conf);
int		ft_release(int keycode, t_all *conf);
void	ft_remove_sprite(t_all *conf);
char	*ft_print_score(t_all *conf);
void	ft_save_screen(t_all *conf);
void	ft_write_header(t_all *conf);
void	ft_process_key(t_all *conf);
void	ft_camera_left(t_all *conf);
void	ft_camera_right(t_all *conf);
void	ft_key_a_d(t_all *conf);
void	ft_key_w_s(t_all *conf);
int		ft_darker_sprite (float dst, int colour);
int		ft_darker(float dst, int colour);
int		ft_darker_ceil(int i, t_all *conf);
int		ft_darker_floor(int i, t_all *conf);
void	ft_bonus_sprite(t_all *conf);
void	ft_sort(t_all *conf);
void	ft_order(t_all *conf);
void	ft_draw_sprite(t_all *conf, int i);
void	ft_sprite(t_all *conf);
void	ft_sprite_process(t_all *conf, int i);
void	ft_process(t_all *conf);
void	ft_process_sidedst(t_all *conf);
void	ft_process_wall(t_all *conf);
void	ft_select_text(t_all *conf);
void	ft_draw_text(t_all *conf, t_img *img);
void	ft_background(t_all *conf);

#endif