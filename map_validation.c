#include "headers/cub3d.h"
#include "libft/libft.h"

void	ft_check_cell(t_all *conf, int i, int j)
{
	int	next;
	int	prev;

	next = ft_strlen(conf->map[i + 1]);
	prev = ft_strlen(conf->map[i - 1]);
	if (j > next - 1 || j > prev - 1)
		ft_exit("Error: map is not closed( > next prev)\n");
	else
	{
		ft_check_cell2(conf->map[i - 1][j - 1]);
		ft_check_cell2(conf->map[i - 1][j]);
		ft_check_cell2(conf->map[i - 1][j + 1]);
		ft_check_cell2(conf->map[i][j - 1]);
		ft_check_cell2(conf->map[i][j + 1]);
		ft_check_cell2(conf->map[i + 1][j - 1]);
		ft_check_cell2(conf->map[i + 1][j]);
		ft_check_cell2(conf->map[i + 1][j + 1]);
	}
	ft_save_map(conf, i, j);
}

void	ft_validation_line(t_all *conf, int i)
{
	int	j;

	j = 1;
	if (conf->map[i][0] && conf->map[i][0] != '1' && conf->map[i][0] != ' ')
		ft_exit("Error: map is not closed(begin line)\n");
	while (conf->map[i][j])
	{
		if (conf->map[i][j] == '2' || conf->map[i][j] == '0'
				|| conf->map[i][j] == 'N' || conf->map[i][j] == 'S'
				|| conf->map[i][j] == 'E' || conf->map[i][j] == 'W')
			ft_check_cell(conf, i, j);
		++j;
	}
}

void	ft_sprite_alloc(t_all *conf)
{
	conf->spr = (t_sp *)malloc(sizeof(t_sp));
	if (conf->spr == NULL)
		ft_exit("Error: memory allocate error(sprite init)\n");
	conf->spr->x = (double *)malloc(sizeof(double) * conf->sp_c);
	if (conf->spr->x == NULL)
		ft_exit("Error: memory allocate error(sprite init)\n");
	conf->spr->y = (double *)malloc(sizeof(double) * conf->sp_c);
	if (conf->spr->y == NULL)
		ft_exit("Error: memory allocate error(sprite init)\n");
	conf->spr->z_buf = (double *)malloc(sizeof(double) * conf->resx);
	if (conf->spr->z_buf == NULL)
		ft_exit("Error: memory allocate error(sprite init)\n");
	conf->spr->s_ord = (int *)malloc(sizeof(int) * conf->sp_c);
	if (conf->spr->s_ord == NULL)
		ft_exit("Error: memory allocate error(sprite init)\n");
	conf->spr->s_dst = (double *)malloc(sizeof(double) * conf->sp_c);
	if (conf->spr->s_dst == NULL)
		ft_exit("Error: memory allocate error(sprite init)\n");
}

void	ft_sprite_init(t_all *conf)
{
	int	i;
	int	j;
	int	k;

	ft_sprite_alloc(conf);
	i = 0;
	k = 0;
	while (conf->map[i])
	{
		j = 0;
		while (conf->map[i][j])
		{
			if (conf->map[i][j] == '2')
			{
				conf->spr->x[k] = i + 0.5;
				conf->spr->y[k] = j + 0.5;
				conf->map[i][j] = SPRITE_COLLISION;
				++k;
			}
			++j;
		}
		++i;
	}
}

void	ft_map_validation(t_all *conf)
{
	int	i;
	int	start;
	int	end;

	start = ft_find_first(conf);
	end = ft_find_last(conf);
	i = start + 1;
	ft_map_closed(conf->map[start]);
	ft_map_closed(conf->map[end]);
	while (i < end)
	{
		if (conf->map[i][0] == '\0')
			ft_exit("Error: empty line in map\n");
		ft_validation_line(conf, i);
		++i;
	}
	if (!(conf->player))
		ft_exit("Error: no player\n");
	ft_sprite_init(conf);
}
