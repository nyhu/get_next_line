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

#include <unistd.h>
#include <stdlib.h>
#define BUF_SIZE 512

typedef struct		s_line
{
	char			data[BUF_SIZE + 1];
	int				ret;
	int				fd;
	struct s_line	*next;
}					t_line;

#endif
