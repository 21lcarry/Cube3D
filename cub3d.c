#include "headers/cub3d.h"
#include "libft/libft.h"

int	ft_extension(char *arg, char *ext)
{
	int	i;
	int	j;

	i = 0;
	while (arg[i] && arg[i] != '.')
		++i;
	j = 0;
	while (arg[i] && ext[j])
	{
		if (arg[i] == ext[j])
		{
			++i;
			++j;
		}
		else
			return (0);
	}
	if (j == 4)
		return (1);
	else
		return (0);
}

int	ft_screen(char *arg, char *param)
{
	int	i;

	i = 0;
	while (arg[i] == param[i])
	{
		if (!arg[i] && !param[i])
			return (1);
		++i;
	}
	return (0);
}

int	gnl_parse(char *line, t_all *conf, int count)
{
	if (line[0] == 'N' && line[1] == 'O' && line[2] == ' ')
		return (ft_parse_texture(line, conf, "NO", conf->no));
	else if (line[0] == 'W' && line[1] == 'E' && line[2] == ' ')
		return (ft_parse_texture(line, conf, "WE", conf->we));
	else if (line[0] == 'E' && line[1] == 'A' && line[2] == ' ')
		return (ft_parse_texture(line, conf, "EA", conf->ea));
	else if (line[0] == 'S' && line[1] == 'O' && line[2] == ' ')
		return (ft_parse_texture(line, conf, "SO", conf->so));
	else if (line[0] == 'S' && line[1] == ' ')
		return (ft_parse_texture(line, conf, "SP", conf->sprite));
	else if (line[0] == 'F' && line[1] == ' ')
		return (ft_parse_colour(line, &conf->colour_f));
	else if (line[0] == 'C' && line[1] == ' ')
		return (ft_parse_colour(line, &conf->colour_c));
	else if (line[0] == 'R' && line[1] == ' ')
		return (ft_parse_resolution(line, conf));
	else if (line[0] == '\0')
		return (0);
	else if (count < 8)
		ft_exit("Error: not enough param\n");
	return (0);
}

void	ft_cube_init(char *path, int screen)
{
	t_all	*conf;
	char	*line;
	int		count;

	count = 0;
	conf = (t_all *)malloc(sizeof(t_all));
	if (conf == NULL)
		ft_exit("Error: init memory error\n");
	ft_init_conf(conf, screen);
	conf->fd = open(path, O_RDONLY);
	if (conf->fd < 0 || (open(path, O_DIRECTORY) >= 0))
		ft_exit("Error: open file error\n");
	while (((get_next_line(conf->fd, &line)) > 0) && count < 8)
		count += gnl_parse(line, conf, count);
	if (count < 8)
		count += gnl_parse(line, conf, count);
	else
		gnl_parse_map(conf, line);
	ft_window_init(conf);
}

int	main(int ac, char **av)
{
	if (ac == 2 && ft_extension(av[1], ".cub"))
		ft_cube_init(av[1], 0);
	else if (ac == 3 && ft_screen(av[2], "--save")
		&& ft_extension(av[1], ".cub"))
		ft_cube_init(av[1], 1);
	else
		ft_exit("Error: invalid arguments\n");
	return (0);
}
