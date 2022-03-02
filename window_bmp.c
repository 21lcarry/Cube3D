#include "headers/cub3d.h"
#include "libft/libft.h"

void	ft_write_header(t_all *conf)
{
	int	temp;

	write(conf->fd, "BM", 2);
	temp = 14 + 40 + 4 * conf->resx * conf->resy;
	write(conf->fd, &temp, 4);
	temp = 0;
	write(conf->fd, &temp, 2);
	write(conf->fd, &temp, 2);
	temp = 54;
	write(conf->fd, &temp, 4);
	temp = 40;
	write(conf->fd, &temp, 4);
	write(conf->fd, &conf->resx, 4);
	write(conf->fd, &conf->resy, 4);
	temp = 1;
	write(conf->fd, &temp, 2);
	write(conf->fd, &conf->win->img1->btp, 2);
	temp = 0;
	write(conf->fd, &temp, 4);
	write(conf->fd, &temp, 4);
	write(conf->fd, &temp, 4);
	write(conf->fd, &temp, 4);
	write(conf->fd, &temp, 4);
	write(conf->fd, &temp, 4);
}

void	ft_save_screen(t_all *conf)
{
	int	x;
	int	y;

	y = conf->resy;
	conf->fd = open("./screenshot.bmp", O_RDWR |O_CREAT, CHMOD);
	if (conf->fd == -1)
		ft_exit("Error: create .bmp file error\n");
	ft_write_header(conf);
	while (y >= 0)
	{
		x = 0;
		while (x < conf->resx)
		{
			write(conf->fd, &conf->win->img1->addr[y * conf->win->img1->s_line
				/ 4 + x], 4);
			++x;
		}
		--y;
	}
	write(1, "./screenshot.bmp created\n", 26);
	ft_close(conf);
}
