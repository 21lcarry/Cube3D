#include "headers/cub3d.h"
#include "libft/libft.h"

void	ft_init_textures(t_all *conf)
{
	conf->no = (t_img *)malloc(sizeof(t_img));
	if (conf->no == NULL)
		ft_exit("Error: memory allocation error\n");
	ft_start_img(conf->no);
	conf->so = (t_img *)malloc(sizeof(t_img));
	if (conf->so == NULL)
		ft_exit("Error: memory allocation error\n");
	ft_start_img(conf->so);
	conf->we = (t_img *)malloc(sizeof(t_img));
	if (conf->we == NULL)
		ft_exit("Error: memory allocation error\n");
	ft_start_img(conf->we);
	conf->ea = (t_img *)malloc(sizeof(t_img));
	if (conf->ea == NULL)
		ft_exit("Error: memory allocation error\n");
	ft_start_img(conf->ea);
	conf->sprite = (t_img *)malloc(sizeof(t_img));
	if (conf->sprite == NULL)
		ft_exit("Error: memory allocation error\n");
	ft_start_img(conf->sprite);
	conf->draw = (t_drw *)malloc(sizeof(t_drw));
	if (conf->draw == NULL)
		ft_exit("Error: memory allocation error\n");
	ft_start_drw(conf->draw);
}

void	ft_start_cam(t_cam *cam)
{
	cam->planex = 0;
	cam->planey = 0;
	cam->oldplanex = 0;
	cam->camx = 0;
	cam->raydirx = 0;
	cam->raydiry = 0;
	cam->mapx = 0;
	cam->mapy = 0;
	cam->sidedstx = 0;
	cam->sidedsty = 0;
	cam->deltadstx = 0;
	cam->deltadsty = 0;
	cam->p_wall_dst = 0;
	cam->stepx = 0;
	cam->stepy = 0;
	cam->hit = 0;
	cam->side = 0;
	cam->line_h = 0;
	cam->draws = 0;
	cam->drawe = 0;
	cam->flag[0] = -1;
	cam->flag[1] = -1;
	cam->flag[2] = -1;
}

void	ft_init_struct(t_all *conf)
{
	conf->win = (t_win *)malloc(sizeof(t_win));
	if (conf->win == NULL)
		ft_exit("Error: memory allocation error(init struct)\n");
	ft_start_win(conf->win);
	conf->key = (t_key *)malloc(sizeof(t_key));
	if (conf->key == NULL)
		ft_exit("Error: memory allocation error(init struct)\n");
	ft_start_key(conf->key);
	conf->plr = (t_plr *)malloc(sizeof(t_plr));
	if (conf->plr == NULL)
		ft_exit("Error: memory allocation error(init struct)\n");
	ft_start_plr(conf->plr);
	conf->cam = (t_cam *)malloc(sizeof(t_cam));
	if (conf->cam == NULL)
		ft_exit("Error: memory allocation error(init struct)\n");
	ft_start_cam(conf->cam);
	conf->win->img1 = (t_img *)malloc(sizeof(t_img));
	if (conf->win->img1 == NULL)
		ft_exit("Error: memory allocation error(init struct)\n");
	ft_start_img(conf->win->img1);
	conf->win->img2 = (t_img *)malloc(sizeof(t_img));
	if (conf->win->img2 == NULL)
		ft_exit("Error: memory allocation error(init struct)\n");
	ft_start_img(conf->win->img2);
}

void	ft_start_win(t_win *window)
{
	window->mlx = NULL;
	window->win = NULL;
	window->img1 = NULL;
	window->img2 = NULL;
}

void	ft_init_conf(t_all *conf, int screen)
{
	ft_conf_start(conf, screen);
	ft_init_textures(conf);
	ft_init_struct(conf);
	conf->win->mlx = mlx_init();
	if (conf->win->mlx == NULL)
		ft_exit("Error: mlx_init error\n");
}
