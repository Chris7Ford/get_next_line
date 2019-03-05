/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chford <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 09:59:02 by chford            #+#    #+#             */
/*   Updated: 2019/03/05 12:06:02 by chford           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "get_next_line.h"

char	*chop_line(char **string)
{
	char	*new;
	int		length;
	int		i;

	length = 0;
	i = -1;
	while ((*string)[length] != '\0' && (*string)[length] != '\n')
		length++;
	if (!(new = (char *)malloc(sizeof(char) * (length + 1))))
		return (0);
	while (++i < length)
		new[i] = (*string)[i];
	new[i] = '\0';
	i = 0;
	length++;
	if ((*string)[length - 1] == '\n')
	{
		while ((*string)[length] != '\0')
			(*string)[i++] = (*string)[length++];
	}
	(*string)[i] = '\0';
	return (new);
}

int		read_file(const int fd, char **fd_store, int *ret)
{
	char			buffer[BUFF_SIZE];
	char			*hold;

	while (!(ft_strchr(*fd_store, '\n')) && (*ret = read(fd, buffer, BUFF_SIZE)) > 0)
	{
		buffer[*ret] = '\0';
		hold = *fd_store;
		*fd_store = ft_strjoin(*fd_store, buffer);
		free(hold);
	}
	if (*ret == -1)
		return (0);
	return (1);
}

int		get_next_line(const int fd, char **line)
{
	static char		*fd_store[FD_MAX + 1];
	int				ret;

	if (!(fd_store[fd]))
		fd_store[fd] = ft_strnew(1);
	if (!(fd_store[fd]) || !(read_file(fd, &(fd_store[fd]), &ret)))
		return (-1);
	if (fd_store[fd][0] == '\0' && ret == 0)
		return (0);
	if (!(*line = chop_line(&(fd_store[fd]))))
		return (-1);
	return (1);
}
