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

t_line	*ft_create_line(int ret, char *tmp, int fd)
{
	t_line			*new;

	if (!ret || !(new = (t_line *)malloc(sizeof(t_line))))
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

void	ft_retromove(t_line *rabbit)
{

}

char	*ft_dupcat(char *tab, char *str)
{
	
}

char	*ft_check_backn(t_line **begin, t_line *rabbit, int fd, char *result)
{
	int		i;

	i = 0;
	while (i < rabbit->ret && rabbit->data[i] != '\n')
		i++;
	result = ft_dupcat(

}

char	*get_next_line(int fd)
{
	static t_line	*begin = NULL;
	char			tmp[BUF_SIZE];
	t_line			*rabbit;
	char			*result;
	
	result = NULL;
	if (fd < 0)
		return (NULL);
	else if (!begin)
		if (!(begin = ft_create_line(read(fd, tmp, BUF_SIZE), tmp, fd)))
			return (NULL);
	rabbit = begin;
	if (rabbit->fd != fd)
	{
		while (rabbit->pfd && rabbit->pfd->fd != fd)
			rabbit = rabbit->pfd;
		if (!(rabbit->pfd)
			if (!(rabbit->pfd = ft_create_line(read(fd, tmp, BUF_SIZE), tmp, fd)))
				return (NULL);
		rabbit = rabbit->pfd;
	}
	return (ft_check_backn(&begin, rabbit, fd, result);
}
