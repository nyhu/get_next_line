/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tboos <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/09 14:23:09 by tboos             #+#    #+#             */
/*   Updated: 2016/02/09 17:57:29 by tboos            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#define BUF_SIZE 512
#define TMP_READ read(fd, tmp, BUF_SIZE)
#define STRUCT_READ read(fd, begin->data, BUF_SIZE)
#define MALLOC (t_line *)ft_memalloc(sizeof(t_line))
#define RET begin->ret
#define DATA begin->data
#define NCHR ((char *)(ft_memchr(DATA, '\n', RET)) - DATA)

typedef struct		s_line
{
	char			*data;
	int				ret;
	int				fd;
	struct s_line	*next;
}					t_line;

#endif
