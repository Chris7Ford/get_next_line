/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chford <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 09:42:05 by chford            #+#    #+#             */
/*   Updated: 2019/02/22 17:27:34 by chford           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define	FD_MAX 1024
# define	BUF_SIZE 1
typedef struct s_cursor		t_cursor;
typedef struct s_position	t_position;

struct						s_cursor
{
	int						value;
	char					touched;
	char					*last;
};

struct						s_position
{
	int						i;
	int						link;
};

t_position	get_index_and_link(t_list **list, int pos);
int			fill_list(const int fd, t_list **list);
int			count_line_chars(t_list **list, int pos);
int			fill_string(char ** line, t_list **list, int pos);
int			get_next_line(const int fd, char **line);
#endif
