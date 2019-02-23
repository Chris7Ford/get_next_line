/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chford <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 09:59:02 by chford            #+#    #+#             */
/*   Updated: 2019/02/22 17:26:32 by chford           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "get_next_line.h"

int		fill_list(const int fd, t_list **list)
{
	char	buffer[BUF_SIZE + 1];
	int		new_line_found;
	int		ret;
	int		i;

	new_line_found = 0;
	while ((ret = read(fd, buffer, BUF_SIZE)) && !new_line_found)
	{
		buffer[ret] = '\0';
		ft_lstpush(list, (void *)buffer, ret);
		i = 0;
		while (buffer[i])
		{
			if (buffer[i] == '\n')
			{
				new_line_found = 1;
				break ;
			}
			i++;
		}
	}
	if (ret == -1)
		return (0);
	return (1);
}

t_position	get_index_and_link(t_list **list, int pos)
{
	t_position	position_data;
	t_list		*elem;
	int			char_count;

	char_count = 0;
	position_data.link = 0;
	while (char_count + BUF_SIZE < pos && elem)
	{
		char_count += BUF_SIZE;
		elem = elem->next;
		position_data.link++;
	}
	position_data.i = pos - char_count;
	return (position_data);
}

int		count_line_chars(t_list **list, int pos)
{
	t_position		position_data;
	t_list			*elem;
	int				count;

	elem = *list;
	count = 0;
	position_data = get_index_and_link(list, pos);
	while (elem)
	{
		while (((char *)(elem->content))[position_data.i])
		{
			if (((char *)(elem->content))[position_data.i] == '\n')
				return (count);
			position_data.i++;
			count++;
		}
		position_data.i = 0;
		elem = elem->next;
	}
	return (count);
}

int		fill_string(char ** line, t_list **list, int pos)
{
	t_position		position_data;
	t_list			*elem;
	int				link;
	int				j;

	elem = *list;
	link = -1;
	j = 0;
	position_data = get_index_and_link(list, pos);
	while (++link < position_data.link && elem)
		elem = elem->next;
	while (elem)
	{
		while (((char *)(elem->content))[position_data.i])
		{
			if (((char *)(elem->content))[position_data.i] == '\n')
			{
				(*line)[j] = '\0';
				return (1);
			}
			(*line)[j++] = ((char *)(elem->content))[position_data.i++];
		}
		position_data.i = 0;
		elem = elem->next;
	}
	(*line)[j] = '\0';
	return (1);
}

int		get_next_line(const int fd, char **line)
{
	static t_cursor	fd_store[FD_MAX + 1];
	t_list			*list;
	int				length;
	int				pos;

	list = 0;
	if ((fd_store[fd]).touched == 1)
		pos = (fd_store[fd]).value;
	else
	{
		pos = 0;
		(fd_store[fd]).value = 0;
		(fd_store[fd]).touched = 1;
	}
	if (!(fill_list(fd, &list)))
		return (-1);
	length = count_line_chars(&list, pos);
	(fd_store[fd]).value += length + 1;
	*line = (char *)malloc(sizeof(char) * (length + 1));
	fill_string(line, &list, pos);
	return (0);
}
