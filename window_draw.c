#include "headers/cub3d.h"
#include "libft/libft.h"

void	ft_draw_text(t_all *conf, t_img *img)
{
	int	y;

	y = conf->cam->draws - 1;
	conf->draw->t_step = 1.0 * img->height / conf->cam->line_h;
	conf->draw->t_x = (int)(conf->draw->wall * (double)img->width);
	if (conf->cam->side == 0 && conf->cam->raydirx > 0)
		conf->draw->t_x = img->width - conf->draw->t_x - 1;
	if (conf->cam->side == 1 && conf->cam->raydiry < 0)
		conf->draw->t_x = img->width - conf->draw->t_x - 1;
	conf->draw->t_pos = (conf->cam->draws - conf->resy / 2
			+ conf->cam->line_h / 2) * conf->draw->t_step;
	while (++y <= conf->cam->drawe)
	{
		conf->draw->t_y = (int)conf->draw->t_pos & (img->height - 1);
		conf->draw->t_pos += conf->draw->t_step;
		if (y < conf->resy && conf->cam->x < conf->resx)
			conf->win->img1->addr[y * conf->win->img1->s_line / 4
				+ conf->cam->x] = ft_darker(conf->cam->p_wall_dst,
					img->addr[conf->draw->t_y
					* img->s_line / 4 + conf->draw->t_x]);
	}
}

void	ft_select_text(t_all *conf)
{
	if (conf->cam->side == 0 && conf->cam->raydirx < 0)
		ft_draw_text(conf, conf->no);
	if (conf->cam->side == 0 && conf->cam->raydirx >= 0)
		ft_draw_text(conf, conf->so);
	if (conf->cam->side == 1 && conf->cam->raydiry < 0)
		ft_draw_text(conf, conf->we);
	if (conf->cam->side == 1 && conf->cam->raydiry >= 0)
		ft_draw_text(conf, conf->ea);
}

void	ft_background(t_all *conf)
{
	int	i;

	i = -1;
	conf->cam->drawe = conf->resy - conf->cam->draws;
	while (++i < conf->cam->draws)
		conf->win->img1->addr[i * conf->win->img1->s_line / 4
			+ conf->cam->x] = ft_darker_ceil(i, conf);
	if (i <= conf->cam->drawe)
	{
		if (conf->cam->side == 0)
			conf->draw->wall = conf->plr->y + conf->cam->p_wall_dst
				* conf->cam->raydiry;
		else
			conf->draw->wall = conf->plr->x + conf->cam->p_wall_dst
				* conf->cam->raydirx;
		conf->draw->wall -= floor((conf->draw->wall));
		ft_select_text(conf);
	}
	i = conf->cam->drawe;
	while (++i < conf->resy)
		conf->win->img1->addr[i * conf->win->img1->s_line / 4
			+ conf->cam->x] = ft_darker_floor(i, conf);
}

void	ft_bonus_sprite(t_all *conf)
{
	char	*bonus;

	if (SPRITE_COLLISION == '0')
	{
		ft_remove_sprite(conf);
		bonus = ft_print_score(conf);
		mlx_string_put(conf->win->mlx, conf->win->win, 32, 24, 16711680,
			bonus);
		free(bonus);
	}
}
