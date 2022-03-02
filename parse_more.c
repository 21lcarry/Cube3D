#include "headers/cub3d.h"
#include "libft/libft.h"

int	ft_check_duble(t_all conf, char *id)
{
	if (ft_strncmp(id, "NO", 2) == 0 && conf.no->height > 0)
		return (1);
	else if (ft_strncmp(id, "WE", 2) == 0 && conf.we->height > 0)
		return (1);
	else if (ft_strncmp(id, "EA", 2) == 0 && conf.ea->height > 0)
		return (1);
	else if (ft_strncmp(id, "SO", 2) == 0 && conf.so->height > 0)
		return (1);
	else if (ft_strncmp(id, "SP", 2) == 0 && conf.sprite->height > 0)
		return (1);
	return (0);
}

void	ft_parse_texture2(char *line, t_all *conf, t_img *img, int i)
{
	img->ptr = mlx_xpm_file_to_image(conf->win->mlx, &line[i],
			&(img->width), &(img->height));
	if (img->ptr == NULL)
	{
		free(line);
		ft_exit("Error: invalid texture file\n");
	}
	img->addr = (int *)mlx_get_data_addr(img->ptr, &(img->btp),
			&(img->s_line), &(img->endian));
	if (img->addr == NULL)
	{
		free(line);
		ft_exit("Error: invalid texture file\n");
	}
	if ((img->width) != 64 || (img->height) != 64)
		ft_exit("Error: invalid texture resolution\n");
}

int	ft_parse_texture(char *line, t_all *conf, char *id, t_img *img)
{
	int	i;

	i = 2;
	while (line[i] && line[i] == ' ')
		i++;
	if (ft_strlen(line) < 7)
	{
		free(line);
		ft_exit("Error: invalid config\n");
	}
	if (ft_check_duble(*conf, id))
	{
		free(line);
		ft_exit("Error: duble param\n");
	}
	ft_parse_texture2(line, conf, img, i);
	free(line);
	return (1);
}

int	ft_str_isdigit(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (!(ft_isdigit(str[i])))
			return (0);
		++i;
	}
	return (1);
}

size_t	ft_comcount(const char *str)
{
	size_t	count;
	char	tmp;
	int		i;

	tmp = *str;
	count = 0;
	i = 0;
	while (tmp != '\0')
	{
		if (tmp == ',')
			count++;
		++i;
		tmp = *(str + i);
	}
	return (count);
}
