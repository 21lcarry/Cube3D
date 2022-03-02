#include "headers/cub3d.h"
#include "libft/libft.h"

void	ft_exit(char *str)
{
	int	len;

	len = ft_strlen(str);
	if (str)
		write(2, str, len);
	exit(1);
}

int	ft_nblen(int nb)
{
	int	len;

	len = 1;
	if (nb < 0)
		++len;
	nb /= 10;
	while (nb)
	{
		nb /= 10;
		++len;
	}
	return (len);
}
