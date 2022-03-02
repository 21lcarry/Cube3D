#include "headers/cub3d.h"
#include "libft/libft.h"

int	ft_linemap_valid(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] == ' ' || line[i] == '1' || line[i] == '2'
			|| line[i] == '0' || line[i] == 'N' || line[i] == 'S'
			|| line[i] == 'E' || line[i] == 'W')
			++i;
		else
		{
			free(line);
			ft_exit("Error: incorrect map\n");
		}
	}
	return (1);
}

void	ft_zero(void *str)
{
	int				i;
	unsigned char	*tmp;

	tmp = (unsigned char *)str;
	i = 0;
	if (!tmp)
		return ;
	while (tmp[i])
		tmp[i++] = 0;
	free(str);
}

char	**ft_make_map(t_list **head, int size)
{
	char	**map;
	int		i;
	t_list	*tmp;

	i = 0;
	tmp = *head;
	map = (char **)malloc((sizeof(char *) * size) + 1);
	if (map == NULL)
		ft_exit("Error: map memory allocation error\n");
	while (tmp)
	{
		map[i++] = ft_strdup(tmp->content);
		tmp = tmp->next;
	}
	ft_lstclear(head, ft_zero);
	map[i] = NULL;
	return (map);
}

void	gnl_parse_map(t_all *conf, char *oldline)
{
	t_list	*head;
	char	*line;

	line = NULL;
	head = NULL;
	if (ft_linemap_valid(oldline))
		ft_lstadd_back(&head, ft_lstnew(oldline));
	while (get_next_line(conf->fd, &line) > 0)
	{
		if (ft_linemap_valid(line))
			ft_lstadd_back(&head, ft_lstnew(line));
	}
	ft_lstadd_back(&head, ft_lstnew(line));
	conf->map_size = ft_lstsize(head);
	conf->map = ft_make_map(&head, conf->map_size);
	ft_map_validation(conf);
}
