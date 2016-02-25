/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tboos <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/09 14:23:09 by tboos             #+#    #+#             */
/*   Updated: 2016/02/25 06:26:40 by tboos            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "libft/libft.h"
# define BUFF_SIZE 2
# define MALLOC (t_line *)ft_memalloc(sizeof(t_line))
# define RET begin->ret
# define DATA begin->data
# define READ 0
# define FIND 1

typedef struct		s_line
{
	char			*data;
	int				ret;
	int				fd;
	struct s_line	*next;
}					t_line;

int					get_next_line(int const fd, char **line);
int					get_next_line(int const fd, char **line);
#endif
