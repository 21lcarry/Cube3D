#include "headers/cub3d.h"
#include "libft/libft.h"

static int	ft_value(int rgb, int comp, int oper)
{
	if (oper == 0)
	{
		if (rgb < comp)
			return (0);
		else
			return (rgb);
	}
	if (oper == 1)
	{
		if (rgb > comp)
			return (comp);
		else
			return (rgb);
	}
	return (1);
}

int	ft_darker_sprite (float dst, int colour)
{
	int	r;
	int	g;
	int	b;

	if (dst > (double)V_RANGE)
	{
		r = (colour & R);
		g = (colour & G) >> 8;
		b = (colour & B) >> 16;
		r -= dst * SHADOW_S;
		g -= dst * SHADOW_S;
		b -= dst * SHADOW_S;
		r = ft_value(r, 0, 0);
		g = ft_value(g, 0, 0);
		b = ft_value(b, 0, 0);
		return (0 | (b << 16) | (g << 8) | (r << 0));
	}
	return (colour);
}

int	ft_darker(float dst, int colour)
{
	int	r;
	int	g;
	int	b;

	if (dst > (double)V_RANGE)
	{
		r = (colour & R);
		g = (colour & G) >> 8;
		b = (colour & B) >> 16;
		r -= dst * SHADOW_W;
		g -= dst * SHADOW_W;
		b -= dst * SHADOW_W;
		r = ft_value(r, 0, 0);
		g = ft_value(g, 0, 0);
		b = ft_value(b, 0, 0);
		return (0 | (b << 16) | (g << 8) | (r << 0));
	}
	return (colour);
}

int	ft_darker_ceil(int i, t_all *conf)
{
	int	r;
	int	g;
	int	b;

	r = (conf->colour_c & R);
	g = (conf->colour_c & G) >> 8;
	b = (conf->colour_c & B) >> 16;
	r -= i * SHADOW_C;
	g -= i * SHADOW_C;
	b -= i * SHADOW_C;
	r = ft_value(r, 0, 0);
	g = ft_value(g, 0, 0);
	b = ft_value(b, 0, 0);
	return (0 | (b << 16) | (g << 8) | (r << 0));
}

int	ft_darker_floor(int i, t_all *conf)
{
	int	r;
	int	g;
	int	b;

	r = (conf->colour_f & R);
	g = (conf->colour_f & G) >> 8;
	b = (conf->colour_f & B) >> 16;
	conf->cam->oldr = r;
	conf->cam->oldg = g;
	conf->cam->oldb = b;
	r = 0 + (i / SHADOW_F);
	g = 0 + (i / SHADOW_F);
	b = 0 + (i / SHADOW_F);
	r = ft_value(r, conf->cam->oldr, 1);
	g = ft_value(g, conf->cam->oldg, 1);
	b = ft_value(b, conf->cam->oldb, 1);
	return (0 | (b << 16) | (g << 8) | (r << 0));
}
