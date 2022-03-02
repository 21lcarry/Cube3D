#include "headers/cub3d.h"
#include "libft/libft.h"

void	ft_sprite_process(t_all *conf, int i)
{
	conf->spr->spx = conf->spr->x[conf->spr->s_ord[i]] - conf->plr->x;
	conf->spr->spy = conf->spr->y[conf->spr->s_ord[i]] - conf->plr->y;
	conf->spr->invdet = 1.0 / (conf->cam->planex * conf->plr->diry
			- conf->plr->dirx * conf->cam->planey);
	conf->spr->trans_x = conf->spr->invdet * (conf->plr->diry
			* conf->spr->spx - conf->plr->dirx * conf->spr->spy);
	conf->spr->trans_y = conf->spr->invdet * (-conf->cam->planey
			* conf->spr->spx + conf->cam->planex * conf->spr->spy);
	conf->spr->s_scr_x = (int)((conf->resx / 2) * (1 + conf->spr->trans_x
				/ conf->spr->trans_y));
	conf->spr->s_h = abs((int)(conf->resy / conf->spr->trans_y));
	conf->spr->drawsy = -conf->spr->s_h / 2 + conf->resy / 2;
	if (conf->spr->drawsy < 0)
		conf->spr->drawsy = 0;
	conf->spr->drawey = conf->spr->s_h / 2 + conf->resy / 2;
	if (conf->spr->drawey >= conf->resy)
		conf->spr->drawey = conf->resy;
	conf->spr->s_w = abs((int)(conf->resy / conf->spr->trans_y));
	conf->spr->drawsx = -conf->spr->s_w / 2 + conf->spr->s_scr_x;
	if (conf->spr->drawsx < 0)
		conf->spr->drawsx = 0;
	conf->spr->drawex = conf->spr->s_w / 2 + conf->spr->s_scr_x;
	if (conf->spr->drawex >= conf->resx)
		conf->spr->drawex = conf->resx;
}

void	ft_sprite(t_all *conf)
{
	int	i;

	ft_sort(conf);
	i = 0;
	while (i < conf->sp_c)
	{
		ft_sprite_process(conf, i);
		conf->spr->strp = conf->spr->drawsx;
		while (conf->spr->strp < conf->spr->drawex)
		{
			conf->spr->t_x = (int)(256 * (conf->spr->strp - (-conf->spr->s_w / 2
							+ conf->spr->s_scr_x)) * conf->sprite->width
					/ conf->spr->s_w) / 256;
			if (conf->spr->trans_y > 0 && conf->spr->strp >= 0
				&& conf->spr->strp < conf->resx && conf->spr->trans_y
				< conf->spr->z_buf[conf->spr->strp])
				ft_draw_sprite(conf, i);
			++conf->spr->strp;
		}
		++i;
	}
}

void	ft_draw_sprite(t_all *conf, int i)
{
	int	y;
	int	d;

	y = conf->spr->drawsy;
	while (y < conf->spr->drawey)
	{
		d = (y) * 256 - conf->resy * 128 + conf->spr->s_h * 128;
		conf->spr->t_y = ((d * conf->sprite->height) / conf->spr->s_h) / 256;
		if (conf->sprite->addr[conf->spr->t_y * conf->sprite->s_line / 4
				+ conf->spr->t_x] != 0)
			conf->win->img1->addr[y * conf->win->img1->s_line / 4
				+ conf->spr->strp] = ft_darker_sprite(conf->spr->s_dst[i],
					conf->sprite->addr[conf->spr->t_y * conf->sprite->s_line
					/ 4 + conf->spr->t_x]);
		++y;
	}
}

void	ft_order(t_all *conf)
{
	int		i;
	int		j;
	double	temp;

	i = 0;
	while (i < conf->sp_c)
	{
		j = 0;
		while (j < conf->sp_c - 1)
		{
			if (conf->spr->s_dst[j] < conf->spr->s_dst[j + 1])
			{
				temp = conf->spr->s_dst[j];
				conf->spr->s_dst[j] = conf->spr->s_dst[j + 1];
				conf->spr->s_dst[j + 1] = temp;
				temp = conf->spr->s_ord[j];
				conf->spr->s_ord[j] = conf->spr->s_ord[j + 1];
				conf->spr->s_ord[j + 1] = (int)temp;
			}
			++j;
		}
		++i;
	}
}

void	ft_sort(t_all *conf)
{
	int	i;

	i = 0;
	while (i < conf->sp_c)
	{
		conf->spr->s_ord[i] = i;
		conf->spr->s_dst[i] = ((conf->plr->x - conf->spr->x[i]) * (conf->plr->x
					- conf->spr->x[i]) + (conf->plr->y - conf->spr->y[i])
				* (conf->plr->y - conf->spr->y[i]));
		++i;
	}
	ft_order(conf);
}
