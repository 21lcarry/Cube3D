#include "headers/cub3d.h"
#include "libft/libft.h"

void	ft_process(t_all *conf)
{
	conf->cam->hit = 0;
	conf->cam->p_wall_dst = 0;
	conf->cam->camx = 2 * conf->cam->x / (double)conf->resx - 1;
	conf->cam->raydirx = conf->plr->dirx + conf->cam->planex
		* conf->cam->camx;
	conf->cam->raydiry = conf->plr->diry + conf->cam->planey
		* conf->cam->camx;
	conf->cam->mapx = conf->plr->x;
	conf->cam->mapy = conf->plr->y;
	if (conf->cam->raydiry == 0)
		conf->cam->deltadstx = 0;
	else if (conf->cam->raydirx == 0)
		conf->cam->deltadstx = 1;
	else
		conf->cam->deltadstx = sqrt(1 + (conf->cam->raydiry
					* conf->cam->raydiry) / (conf->cam->raydirx
					* conf->cam->raydirx));
	if (conf->cam->raydirx == 0)
		conf->cam->deltadsty = 0;
	else if (conf->cam->raydiry == 0)
		conf->cam->deltadsty = 1;
	else
		conf->cam->deltadsty = sqrt(1 + (conf->cam->raydirx
					* conf->cam->raydirx) / (conf->cam->raydiry
					* conf->cam->raydiry));
}

void	ft_process_sidedst(t_all *conf)
{
	if (conf->cam->raydirx < 0)
	{
		conf->cam->stepx = -1;
		conf->cam->sidedstx = (conf->plr->x - conf->cam->mapx)
			* conf->cam->deltadstx;
	}
	else
	{
		conf->cam->stepx = 1;
		conf->cam->sidedstx = (conf->cam->mapx + 1.0 - conf->plr->x)
			* conf->cam->deltadstx;
	}
	if (conf->cam->raydiry < 0)
	{
		conf->cam->stepy = -1;
		conf->cam->sidedsty = (conf->plr->y - conf->cam->mapy)
			* conf->cam->deltadsty;
	}
	else
	{
		conf->cam->stepy = 1;
		conf->cam->sidedsty = (conf->cam->mapy + 1.0 - conf->plr->y)
			* conf->cam->deltadsty;
	}
}

void	ft_process_wall(t_all *conf)
{
	while (conf->cam->hit == 0)
	{
		if (conf->cam->sidedstx < conf->cam->sidedsty)
		{
			conf->cam->sidedstx += conf->cam->deltadstx;
			conf->cam->mapx += conf->cam->stepx;
			conf->cam->side = 0;
		}
		else
		{
			conf->cam->sidedsty += conf->cam->deltadsty;
			conf->cam->mapy += conf->cam->stepy;
			conf->cam->side = 1;
		}
		if (conf->map[conf->cam->mapx][conf->cam->mapy] == '1')
			conf->cam->hit = 1;
	}
	if (conf->cam->side == 0)
		conf->cam->p_wall_dst = ((double)conf->cam->mapx - conf->plr->x
				+ (1 - (double)conf->cam->stepx) / 2) / conf->cam->raydirx;
	else
		conf->cam->p_wall_dst = ((double)conf->cam->mapy - conf->plr->y
				+ (1 - (double)conf->cam->stepy) / 2) / conf->cam->raydiry;
	conf->cam->line_h = (int)(conf->resy / conf->cam->p_wall_dst);
	conf->cam->draws = -conf->cam->line_h / 2 + conf->resy / 2;
}
