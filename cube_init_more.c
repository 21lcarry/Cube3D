#include "headers/cub3d.h"
#include "libft/libft.h"

void	ft_conf_start(t_all *conf, int screen)
{
	conf->win = NULL;
	conf->plr = NULL;
	conf->no = NULL;
	conf->so = NULL;
	conf->we = NULL;
	conf->ea = NULL;
	conf->sprite = NULL;
	conf->key = NULL;
	conf->resx = -1;
	conf->resy = -1;
	conf->map = NULL;
	conf->colour_c = -1;
	conf->colour_f = -1;
	conf->fd = -1;
	conf->player = '\0';
	conf->screen = screen;
	conf->sp_c = 0;
	conf->bonusc = 0;
}

void	ft_start_img(t_img *img)
{
	img->ptr = NULL;
	img->addr = NULL;
	img->width = -1;
	img->height = -1;
	img->btp = -1;
	img->s_line = -1;
	img->endian = -1;
}

void	ft_start_drw(t_drw *draw)
{
	draw->t_x = 0;
	draw->t_y = 0;
	draw->t_dir = 0;
	draw->wall = 0;
	draw->t_step = 0;
	draw->t_pos = 0;
}

void	ft_start_key(t_key *key)
{
	key->left = -1;
	key->right = -1;
	key->w = -1;
	key->a = -1;
	key->s = -1;
	key->d = -1;
}

void	ft_start_plr(t_plr *plr)
{
	plr->x = 0;
	plr->y = 0;
	plr->dirx = 0;
	plr->diry = 0;
	plr->olddirx = 0;
	plr->start = 0;
	plr->end = 0;
	plr->mov_s = 0;
	plr->rot_s = 0;
}
