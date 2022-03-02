#include "headers/cub3d.h"
#include "libft/libft.h"

int	ft_find_first(t_all *conf)
{
	int	i;
	int	j;

	j = 0;
	while (conf->map[j])
	{
		i = 0;
		while (conf->map[j][i] && conf->map[j][i] == ' ')
			++i;
		if (conf->map[j][i] && conf->map[j][i] != ' ')
			return (j);
		++j;
	}
	ft_exit("Error: invalid map(first line)\n");
	return (10);
}

int	ft_find_last(t_all *conf)
{
	int	i;
	int	j;

	j = conf->map_size - 1;
	while (conf->map[j])
	{
		i = 0;
		while (conf->map[j][i] && conf->map[j][i] == ' ')
			++i;
		if (conf->map[j][i] && conf->map[j][i] != ' ')
			return (j);
		--j;
	}
	ft_exit("Error: invalid map(last line)\n");
	return (0);
}

void	ft_map_closed(char *line)
{
	int	i;

	i = 0;
	while (line[i])
		if (line[i] == ' ' || line[i] == '1')
			++i;
	else
		ft_exit("Error: invalid map(check first or last line)\n");
}

void	ft_check_cell2(char c)
{
	if (c == '1' || c == '2' || c == '0' || c == 'N' || c == 'S' || c == 'E'
		|| c == 'W')
		return ;
	else
		ft_exit("Error: map is not closed(final check)\n");
}

void	ft_save_map(t_all *conf, int i, int j)
{
	char	c;

	c = conf->map[i][j];
	if (c == '2')
		++conf->sp_c;
	if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
	{
		if (!(conf->player))
		{
			conf->player = c;
			conf->plr->x = (double)i + 0.5;
			conf->plr->y = (double)j + 0.5;
			conf->map[i][j] = '0';
		}
		else
			ft_exit("Error: duble player\n");
	}
}
