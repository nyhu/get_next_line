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

static int			ft_find_fd(t_line **begin, int fd)
{
	char			tmp[BUF_SIZE];
	int				ret;
	t_line			*next;

	next = *begin;
	while (begin && (*begin)->fd != fd && (*begin)->next != next)
		*begin = (*begin)->next;
	if ((*begin) && (*begin)->fd == fd)
		return (1);
	if (!(ret = READ))
		return (0);
	if (!(*begin) && !(*begin = MALLOC))
		return (-1);
	else if ((*begin)->fd != fd && !((*begin)->next = MALLOC))
		return (-1);
	if (next)
		*begin = (*begin)->next;
	(*begin)->data = ft_memcpy((*begin)->data, tmp, BUF_SIZE);
	(*begin)->ret = ret;
	(*begin)->fd = fd;
	(*begin)->cur = 0;
	(*begin)->next = (next ? next : *begin);
	return (1);
}

int				get_next_line(int fd , char **line)
{
	static t_line	*begin = NULL;
	int				test;

	if (fd < 0 || (test = ft_findfd(&begin, fd)) <= 0)
		return ((fd < 0 ? -1 : test));
	
