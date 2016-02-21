/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tboos <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/09 14:30:52 by tboos             #+#    #+#             */
/*   Updated: 2016/02/09 17:57:27 by tboos            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "get_next_line.h"

static t_line	*ft_create_line(int ret, char *tmp, int fd)
{
	t_line			*new;

	if (!(new = (t_line *)malloc(sizeof(t_line))))
		return (NULL);
	new->ret = ret;
	new->fd = fd;
	new->data[ret] = '\0';
	while (ret > 0)
	{
		ret--;
		(new->data)[ret] = tmp[ret];
	}
	new->next = NULL;
	return (new);
}

static void		ft_dupline(char **line, char *str);
{
	char			*tmp;

	if (!(*line))
		return (&(ft_strdup(str)));
	tmp = *line;
	*line = (char *)malloc(ft_strlen(tmp) + ft_strlen(str) + 1);
	*line = ft_strcpy(*line, tmp);
	free(tmp);
	*line = ft_strcat(*line, str);
}

static int		ft_retromove(char **line, t_line *rabbit)
{
	int				i;
	int				j;

	i = 0;
	while (i < rabbit->ret && rabbit->data[i] != '\n')
		i++;
	rabbit->data[i] = '\0';
	ft_dupline(line, rabbit->data);
	j = 0;
	while (i <= rabbit->ret)
	{
		rabbit->data[j] = rabbit->data[i];
		i++;
		j++;
	}
	rabbit->ret = rabbit->ret - i;
	if (!(rabbit->ret))
		return (1);
	return (0);
}

static int		*ft_fill(t_line **begin, t_line *rabbit, int fd, char **line)
{
	t_line			*memo;
	int				i;

	memo = *begin;
	if (!(rabbit->ret))
	{
		if (*begin == rabbit)
		{
			*begin = (*begin)->next;
			free(memo);
			return (0);
		}
		while (memo->next != rabbit)
			memo = memo->next;
		memo->next = rabbit->next;
		free(rabbit);
		return (0);
	}
	*line = NULL;
	while ((i = ft_retromove(line, rabbit)))
	{
		rabbit->ret = read(fd, rabbit->data, BUF_SIZE);
		rabbit->data[BUF_SIZE] = '\0';
	}
	return (1);
}

int				get_next_line(int fd , char **line)
{
	static t_line	*begin = NULL;
	t_line			*rabbit;
	char			tmp[BUF_SIZE];

	if (fd < 0 || (!begin
		&& !(begin = ft_create_line(read(fd, tmp, BUF_SIZE), tmp, fd))))
		return (-1);
	rabbit = begin;
	if (rabbit->fd != fd)
	{
		while (rabbit->next && rabbit->next->fd != fd)
			rabbit = rabbit->next;
		if (!(rabbit->next))
			if (!(rabbit->next = ft_create_line(read(fd, tmp, BUF_SIZE), tmp, fd)))
				return (-1);
		rabbit = rabbit->next;
	}
	return (ft_fill(&begin, rabbit, fd, line);
}
