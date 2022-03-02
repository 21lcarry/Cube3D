#include "headers/cub3d.h"
#include "libft/libft.h"

void	ft_key_w_s(t_all *conf)
{
	if (conf->key->w == 1)
	{
		if (conf->map[(int)(conf->plr->x + (conf->plr->dirx
					* conf->plr->mov_s * 2))][(int)conf->plr->y] == '0')
			conf->plr->x += conf->plr->dirx * conf->plr->mov_s;
		if (conf->map[(int)conf->plr->x][(int)(conf->plr->y
			+ (conf->plr->diry * conf->plr->mov_s * 2))] == '0')
			conf->plr->y += conf->plr->diry * conf->plr->mov_s;
	}
	if (conf->key->s == 1)
	{
		if (conf->map[(int)(conf->plr->x - (conf->plr->dirx
					* conf->plr->mov_s * 2))][(int)conf->plr->y] == '0')
			conf->plr->x -= conf->plr->dirx * conf->plr->mov_s;
		if (conf->map[(int)conf->plr->x][(int)(conf->plr->y
			- (conf->plr->diry * conf->plr->mov_s * 2))] == '0')
			conf->plr->y -= conf->plr->diry * conf->plr->mov_s;
	}
}

void	ft_key_a_d(t_all *conf)
{
	if (conf->key->d == 1)
	{
		if (conf->map[(int)(conf->plr->x + conf->plr->diry
				* (conf->plr->mov_s * 2))][(int)conf->plr->y] == '0')
			conf->plr->x += conf->plr->diry * conf->plr->mov_s;
		if (conf->map[(int)conf->plr->x][(int)(conf->plr->y
			- conf->plr->dirx * (conf->plr->mov_s * 2))] == '0')
			conf->plr->y -= conf->plr->dirx * conf->plr->mov_s;
	}
	if (conf->key->a == 1)
	{
		if (conf->map[(int)(conf->plr->x - conf->plr->diry
				* (conf->plr->mov_s * 2))][(int)conf->plr->y] == '0')
			conf->plr->x -= conf->plr->diry * conf->plr->mov_s;
		if (conf->map[(int)conf->plr->x][(int)(conf->plr->y
			+ conf->plr->dirx * (conf->plr->mov_s * 2))] == '0')
			conf->plr->y += conf->plr->dirx * conf->plr->mov_s;
	}
}

void	ft_camera_right(t_all *conf)
{
	if (conf->key->right == 1)
	{
		conf->plr->olddirx = conf->plr->dirx;
		conf->plr->dirx = conf->plr->dirx * cos(-conf->plr->rot_s)
			- conf->plr->diry * sin(-conf->plr->rot_s);
		conf->plr->diry = conf->plr->olddirx * sin(-conf->plr->rot_s)
			+ conf->plr->diry * cos(-conf->plr->rot_s);
		conf->cam->oldplanex = conf->cam->planex;
		conf->cam->planex = conf->cam->planex * cos(-conf->plr->rot_s)
			- conf->cam->planey * sin(-conf->plr->rot_s);
		conf->cam->planey = conf->cam->oldplanex * sin(-conf->plr->rot_s)
			+ conf->cam->planey * cos(-conf->plr->rot_s);
	}
}

void	ft_camera_left(t_all *conf)
{
	if (conf->key->left == 1)
	{
		conf->plr->olddirx = conf->plr->dirx;
		conf->plr->dirx = conf->plr->dirx * cos(conf->plr->rot_s)
			- conf->plr->diry * sin(conf->plr->rot_s);
		conf->plr->diry = conf->plr->olddirx * sin(conf->plr->rot_s)
			+ conf->plr->diry * cos(conf->plr->rot_s);
		conf->cam->oldplanex = conf->cam->planex;
		conf->cam->planex = conf->cam->planex * cos(conf->plr->rot_s)
			- conf->cam->planey * sin(conf->plr->rot_s);
		conf->cam->planey = conf->cam->oldplanex * sin(conf->plr->rot_s)
			+ conf->cam->planey * cos(conf->plr->rot_s);
	}
}

void	ft_process_key(t_all *conf)
{
	ft_key_w_s(conf);
	ft_key_a_d(conf);
	ft_camera_left(conf);
	ft_camera_right(conf);
}
