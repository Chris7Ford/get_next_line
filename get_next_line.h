/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chford <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 09:42:05 by chford            #+#    #+#             */
/*   Updated: 2019/02/24 20:15:47 by chford           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define	FD_MAX 1023
# define	BUFF_SIZE 4
typedef struct s_cursor		t_cursor;

struct						s_cursor
{
	int						value;
	char					touched;
	char					s[BUFF_SIZE];
};

int			count_line_chars(char *string, int i);
int			get_next_line(const int fd, char **line);
#endif
