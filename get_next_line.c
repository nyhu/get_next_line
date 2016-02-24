/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tboos <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/09 14:30:52 by tboos             #+#    #+#             */
/*   Updated: 2016/02/25 00:21:54 by tboos            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int			ft_free_line(t_line **begin, t_line *next)
{
	while ((*begin)->next != next)
		*begin = (*begin)->next;
	if (next == *begin)
	{
		free(next->data);
		free(next);
		*begin = NULL;
	}
	else
	{
		(*begin)->next = next->next;
		free(next->data);
		free(next);
	}
	return (0);
}

static int			ft_find_fd(t_line **begin, t_line *next, int fd)
{
	char			tmp[BUFF_SIZE + 1];
	int				ret;

	while (begin && (*begin)->fd != fd && (*begin)->next != next)
		*begin = (*begin)->next;
	if ((*begin) && (*begin)->fd == fd)
		return (1);
	if (!(ret = TMP_READ))
		return (0);
	tmp[ret] = '\0';
	if (!(*begin) && !(*begin = MALLOC))
		return (-1);
	else if ((*begin)->fd != fd && !((*begin)->next = MALLOC))
		return (-1);
	if (next)
		*begin = (*begin)->next;
	(*begin)->data = ft_memcpy(ft_memalloc(BUFF_SIZE + 1), tmp, BUFF_SIZE);
	(*begin)->ret = ret;
	(*begin)->fd = fd;
	(*begin)->next = (next ? next : *begin);
	return (1);
}

int					get_next_line(int const fd, char **line)
{
	static t_line	*begin = NULL;
	int				test;
	char			*tmp;

	if (fd < 0 || (test = read(fd, *line, 0)) < 0
		|| (test = ft_find_fd(&begin, begin, fd)) <= 0)
		return ((fd < 0 ? -1 : test));
	test = NCHR;
	*line = ft_strdup(DATA);
	ft_bzero(DATA, BUFF_SIZE + 1);
	tmp = *line;
	while (test < 0 && (RET = STRUCT_READ)
		&& (test = NCHR) < 0
		&& (tmp = *line)
		&& (*line = ft_strjoin(*line, DATA)))
		free(tmp);
	DATA[(test < 0 ? RET : test)] = '\0';
	if (!(*line))
		return (-1);
	if (RET && test > 0
		&& (DATA = ft_memmove(DATA, DATA + test, RET + 1 - test)))
		RET = RET - test;
	return ((RET ? 1 : ft_free_line(&begin, begin)));
}
