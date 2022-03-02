#include "headers/cub3d.h"
#include "libft/libft.h"

int	ft_close(t_all *conf)
{
	if (conf->win->img1->ptr)
		mlx_destroy_image(conf->win->mlx, conf->win->img1->ptr);
	if (conf->win->img2->ptr)
		mlx_destroy_image(conf->win->mlx, conf->win->img2->ptr);
	if (conf->no->ptr)
		mlx_destroy_image(conf->win->mlx, conf->no->ptr);
	if (conf->so->ptr)
		mlx_destroy_image(conf->win->mlx, conf->so->ptr);
	if (conf->we->ptr)
		mlx_destroy_image(conf->win->mlx, conf->we->ptr);
	if (conf->ea->ptr)
		mlx_destroy_image(conf->win->mlx, conf->ea->ptr);
	if (conf->sprite->ptr)
		mlx_destroy_image(conf->win->mlx, conf->sprite->ptr);
	if (conf->win->win)
		mlx_destroy_window(conf->win->mlx, conf->win->win);
	exit(0);
}

int	ft_press(int keycode, t_all *conf)
{
	if (keycode == KEY_LEFT)
		conf->key->left = 1;
	if (keycode == KEY_RIGHT)
		conf->key->right = 1;
	if (keycode == KEY_W)
		conf->key->w = 1;
	if (keycode == KEY_A)
		conf->key->a = 1;
	if (keycode == KEY_S)
		conf->key->s = 1;
	if (keycode == KEY_D)
		conf->key->d = 1;
	if (keycode == KEY_ESC)
		ft_close(conf);
	return (0);
}

int	ft_release(int keycode, t_all *conf)
{
	if (keycode == KEY_LEFT)
		conf->key->left = 0;
	if (keycode == KEY_RIGHT)
		conf->key->right = 0;
	if (keycode == KEY_W)
		conf->key->w = 0;
	if (keycode == KEY_A)
		conf->key->a = 0;
	if (keycode == KEY_S)
		conf->key->s = 0;
	if (keycode == KEY_D)
		conf->key->d = 0;
	return (0);
}

void	ft_remove_sprite(t_all *conf)
{
	int	i;

	i = 0;
	while (i < conf->sp_c)
	{
		if ((int)conf->plr->x == (int)conf->spr->x[i] && (int)conf->plr->y
			== (int)conf->spr->y[i])
		{
			conf->spr->x[i] = -1;
			conf->spr->y[i] = -1;
			--conf->sp_c;
			++conf->bonusc;
		}
		++i;
	}
}

char	*ft_print_score(t_all *conf)
{
	char	*tmp;
	char	*tmp2;
	char	*res;
	int		i;
	int		j;

	i = -1;
	res = (char *)malloc(sizeof(char) * (13 + ft_nblen(conf->bonusc)) + 1);
	if (res == NULL)
		ft_exit("Error: memory allocate error\n");
	tmp = ft_itoa(conf->bonusc);
	tmp2 = ft_strdup("Total score: ");
	while (++i < (int)ft_strlen(tmp2))
		res[i] = tmp2[i];
	free(tmp2);
	j = 0;
	while (j < (int)ft_strlen(tmp))
		res[i++] = tmp[j++];
	free(tmp);
	res[i] = '\0';
	return (res);
}
