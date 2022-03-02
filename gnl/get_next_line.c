/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcarry <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/29 21:31:38 by lcarry            #+#    #+#             */
/*   Updated: 2021/01/29 21:31:40 by lcarry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_f_newline(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == '\n')
			return (1);
		++i;
	}
	return (0);
}

void	ft_until_nl(int *i, char *str)
{
	while (str[*i] && str[*i] != '\n')
		++*i;
}

char	*ft_remain(char *remain)
{
	char	*res;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!remain)
		return (NULL);
	ft_until_nl(&i, remain);
	if (!remain[i])
	{
		free(remain);
		return (0);
	}
	res = (char *)malloc(sizeof(char) * (ft_strlen(remain) - i) + 1);
	if (res == NULL)
		return (NULL);
	++i;
	while (remain[i])
		res[j++] = remain[i++];
	res[j] = '\0';
	free(remain);
	return (res);
}

char	*ft_next_line(char *str)
{
	char	*res;
	int		i;

	i = 0;
	if (!str)
		return (NULL);
	ft_until_nl(&i, str);
	res = (char *)malloc(sizeof(char) * (i + 1));
	if (res == NULL)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		res[i] = str[i];
		++i;
	}
	res[i] = '\0';
	return (res);
}

int	get_next_line(int fd, char **line)
{
	static char	*remain;
	ssize_t		bytes;
	char		*buff;

	if (!line || (int)BUFFER_SIZE <= 0 || read(fd, *line, 0) < 0)
		return (-1);
	buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (buff == NULL)
		return (-1);
	bytes = 1;
	while ((ft_f_newline(remain) == 0) && bytes != 0)
	{
		bytes = read(fd, buff, BUFFER_SIZE);
		buff[bytes] = '\0';
		remain = ft_strjoin(remain, buff);
	}
	free(buff);
	if (bytes < 0)
		return (-1);
	*line = ft_next_line(remain);
	remain = ft_remain(remain);
	if (bytes == 0)
		return (0);
	else
		return (1);
}
