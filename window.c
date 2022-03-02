#include "headers/cub3d.h"
#include "libft/libft.h"

void	ft_frame_swap(t_all *conf)
{
	void	*tmp;

	tmp = conf->win->img1->ptr;
	conf->win->img1->ptr = conf->win->img2->ptr;
	conf->win->img2->ptr = tmp;
	tmp = conf->win->img1->addr;
	conf->win->img1->addr = conf->win->img2->addr;
	conf->win->img2->addr = tmp;
}

int	ft_raycast(t_all *conf)
{
	conf->cam->x = -1;
	while (++conf->cam->x < conf->resx)
	{
		ft_process(conf);
		ft_process_sidedst(conf);
		ft_process_wall(conf);
		if (conf->cam->draws < 0)
			conf->cam->draws = 0;
		conf->cam->drawe = (conf->cam->line_h / 2) + (conf->resy / 2);
		if (conf->cam->drawe >= conf->resy || conf->cam->drawe < 0)
			conf->cam->drawe = conf->resy - 1;
		ft_background(conf);
		conf->spr->z_buf[conf->cam->x] = conf->cam->p_wall_dst;
	}
	ft_sprite(conf);
	if (conf->screen == 1)
		ft_save_screen(conf);
	mlx_put_image_to_window(conf->win->mlx, conf->win->win,
		conf->win->img1->ptr, 0, 0);
	ft_process_key(conf);
	ft_frame_swap(conf);
	ft_bonus_sprite(conf);
	return (1);
}

void	ft_init_player(t_all *conf)
{
	if (conf->player == 'E')
		conf->cam->planex = 0.66;
	if (conf->player == 'W')
		conf->cam->planex = -0.66;
	if (conf->player == 'N')
		conf->cam->planey = 0.66;
	if (conf->player == 'S')
		conf->cam->planey = -0.66;
	if (conf->player == 'E')
		conf->plr->diry = 1;
	if (conf->player == 'W')
		conf->plr->diry = -1;
	if (conf->player == 'N')
		conf->plr->dirx = -1;
	if (conf->player == 'S')
		conf->plr->dirx = 1;
	conf->plr->mov_s = MOVE_SPEED * ((conf->resx + conf->resy) / 64);
	conf->plr->rot_s = ROT_SPEED * ((conf->resx + conf->resy) / 64);
}

void	ft_init_raycast(t_all *conf)
{
	conf->win->img1->ptr = mlx_new_image(conf->win->mlx, conf->resx,
			conf->resy);
	conf->win->img1->addr = (int *)mlx_get_data_addr(conf->win->img1->ptr,
			&(conf->win->img1->btp), &(conf->win->img1->s_line),
			&(conf->win->img1->endian));
	conf->win->img2->ptr = mlx_new_image(conf->win->mlx, conf->resx,
			conf->resy);
	conf->win->img2->addr = (int *)mlx_get_data_addr(conf->win->img2->ptr,
			&(conf->win->img2->btp), &(conf->win->img2->s_line),
			&(conf->win->img2->endian));
	ft_init_player(conf);
}

void	ft_window_init(t_all *conf)
{
	conf->win->win = mlx_new_window(conf->win->mlx, conf->resx, conf->resy,
			"Cube3D lcarry");
	if (conf->win->win == NULL)
		ft_exit("Error: mlx_new_window error\n");
	ft_init_raycast(conf);
	mlx_hook(conf->win->win, 2, 1L << 0, ft_press, conf);
	mlx_hook(conf->win->win, 3, 1L << 1, ft_release, conf);
	mlx_hook(conf->win->win, 33, 1L << 17, ft_close, conf);
	mlx_loop_hook(conf->win->mlx, ft_raycast, conf);
	mlx_loop(conf->win->mlx);
}
