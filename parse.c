#include "headers/cub3d.h"
#include "libft/libft.h"

int	ft_parse_str_colour(char **res, char *line)
{
	int	r;
	int	g;
	int	b;
	int	i;

	r = ft_atoi(res[0]);
	g = ft_atoi(res[1]);
	b = ft_atoi(res[2]);
	i = 0;
	while (res[i])
		free(res[i++]);
	if (res)
		free(res);
	if (r > 255 || r < 0 || g > 255 || g < 0 || b > 255 || b < 0)
	{
		free(line);
		ft_exit("Error: wrong color format\n");
	}
	return (0 | (r << 16) | (g << 8) | (b << 0));
}

int	ft_parse_colour(char *line, int *colour)
{
	char	**res;
	int		i;

	if (*colour > -1)
		ft_exit("Error: double colour param\n");
	i = 2;
	while (line[i] && line[i] == ' ')
		i++;
	res = ft_split(&line[i], ',');
	if (ft_comcount(&line[i]) > 2 || !(res[0]) || !(res[1]) || !(res[2])
		|| res[3] != NULL || !(ft_str_isdigit(res[0]))
		|| !(ft_str_isdigit(res[1])) || !(ft_str_isdigit(res[2])))
	{
		free(line);
		i = 0;
		while (res[i])
			free(res[i++]);
		if (res)
			free(res);
		ft_exit("Error: wrong color format\n");
	}
	*colour = ft_parse_str_colour(res, line);
	free(line);
	return (1);
}

int	ft_res_valid(char *line)
{
	int	i;

	i = 0;
	while (line[i] != ' ')
	{
		if (!ft_isdigit(line[i]))
			return (-1);
		++i;
	}
	while (line[i] && line[i] == ' ')
		i++;
	while (line[i] != ' ' && line[i])
	{
		if (!ft_isdigit(line[i]))
			return (-1);
		++i;
	}
	while (line[i])
	{
		if (line[i] != ' ')
			return (-1);
		++i;
	}
	return (1);
}

void	ft_max_res(t_all *conf)
{
	int	max_resx;
	int	max_resy;

	max_resx = 0;
	max_resy = 0;
	mlx_get_screen_size(conf->win->mlx, &max_resx, &max_resy);
	if (max_resx && max_resy)
	{
		if (max_resx < conf->resx || conf->resx < 0)
			conf->resx = max_resx;
		if (max_resy < conf->resy || conf->resy < 0)
			conf->resy = max_resy;
	}
	else
		ft_exit("Error: mlx_get_screen_size error\n");
}

int	ft_parse_resolution(char *line, t_all *conf)
{
	int	i;

	i = 2;
	while (line[i] && line[i] == ' ')
		i++;
	if (!line[i] || !ft_isdigit(line[i]) || conf->resx > -1 || conf->resy > -1
		|| ft_res_valid(&line[i]) != 1)
	{
		free(line);
		ft_exit("Error: invalid resolution\n");
	}
	conf->resx = ft_atoi(&line[i]);
	i += ft_nblen(conf->resx) + 1;
	while (line[i] && line[i] == ' ')
		i++;
	conf->resy = ft_atoi(&line[i]);
	if (conf->resx == 0 || conf->resy == 0)
	{
		free(line);
		ft_exit("Error: invalid resolution\n");
	}
	free(line);
	ft_max_res(conf);
	return (1);
}
