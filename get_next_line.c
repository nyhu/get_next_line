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

#include "get_next_line.h"

t_list	*ft_create_elem(int ret, char *tmp, int fd)
{
	t_list			*new;

	if (!ret || !(new = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	new->ret = ret;
	new->fd = fd;
	while (ret >= 0)
	{
		ret--;
		(new->data)[ret] = tmp[ret];
	}
	new->next = NULL;
	new->pfd = NULL;
	return (new);
}

char	*get_next_line(int fd)
{
	static t_list	*begin = NULL;
	char			tmp[BUF_SIZE];
	t_list			*rabbit;
	
	if (fd < 0)
		return (NULL)
	if (!begin)
		if (!(begin = ft_create_elem(read(fd, tmp, BUF_SIZE), tmp, fd)))
			return (NULL);
	rabbit = begin;
	if (rabbit->fd != fd)
	{
		while (rabbit->pfd && rabbit->pfd->fd != fd)
			rabbit = rabbit->pfd;
		if (!rabbit)
			if (!(rabbit = ft_create_elem(read(fd, tmp, BUF_SIZE), tmp, fd)))
				return (NULL);
	}
	while ((rabbit->next = ft_create_elem(read(fd, tmp, BUF_SIZE), tmp, fd)))
		rabbit = rabbit->next;
		
	

}
