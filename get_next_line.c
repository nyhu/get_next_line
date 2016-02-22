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

static int			ft_initl(t_line **begin, t_line *next, int fd)
{
	char			tmp[BUF_SIZE];
	int				ret;

	if (!(ret = READ))
		return (0);
	if (!(*begin) && !(*begin = (t_line *)ft_memalloc(sizeof(t_line))))
		return (-1);
	(*begin)->data = ft_memcpy((*begin)->data, tmp, BUF_SIZE);
	(*begin)->ret = ret;
	(*begin)->fd = fd;
	(*begin)->next = (next ? next : *begin);
	return (1);
}

static int			ft_findfd(t_line **begin, int fd)
{
	int				test;
	t_line			*next;

	next = *begin;
	if (!(*begin) && (test = ft_initl(begin, NULL, fd)) <= 0)
		return (test);
	while ((*begin)->fd != fd && (*begin)->next != next)
		*begin = (*begin)->next;
	if ((*begin)->fd != fd && (test = ft_initl(begin)
}

int				get_next_line(int fd , char **line)
{
	static t_line	*begin = NULL;
	int				test;

	if (fd < 0 || (test = ft_findfd(&begin, fd)) <= 0)
		return ((fd < 0 ? -1 : test));
	
