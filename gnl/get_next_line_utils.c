/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcarry <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/29 21:32:06 by lcarry            #+#    #+#             */
/*   Updated: 2021/01/29 21:32:07 by lcarry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "../libft/libft.h"
size_t	ft_strlen(const char *str)
{
	size_t	count;

	count = 0;
	if (!(str))
		return (0);
	while (str[count])
		count++;
	return (count);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*res;
	size_t	len;
	size_t	l1;
	size_t	l2;

	if (!s1 && !s2)
		return (NULL);
	l1 = ft_strlen((char *)s1);
	l2 = ft_strlen((char *)s2);
	len = (l1 + l2) + 1;
	res = (char *)malloc(sizeof(char) * len);
	if (res == NULL)
		return (NULL);
	ft_memmove((char *)res, (char *)s1, l1);
	ft_memmove((char *)res + l1, (char *)s2, l2);
	res[len - 1] = '\0';
	free((char *)s1);
	return (res);
}

void	*ft_memmove(void *destination, void *source, size_t n)
{
	unsigned char	*dest;
	unsigned char	*src;

	dest = (unsigned char *)destination;
	src = (unsigned char *)source;
	if (!dest && !src)
		return (dest);
	if (src < dest)
		while (n-- > 0)
			dest[n] = src[n];
	else
	{
		while (n--)
			*dest++ = *src++;
	}
	return (dest);
}
