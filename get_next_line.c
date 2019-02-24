/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chford <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 09:59:02 by chford            #+#    #+#             */
/*   Updated: 2019/02/24 13:39:37 by chford           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "get_next_line.h"

int		count_line_chars(char *string, int i)
{
	int				count;

	count = 0;
	while (string[i])
	{
		if (string[i] == '\n')
			return (count * -1);
		i++;
		count++;
	}
	return (count);
}

char	*ft_strjoin_nl(char *s1, char *s2)
{
	int		i;
	int		j;
	int		l;
	char	*string;

	if (!s1 || !s2)
		return (0);
	i = count_line_chars(s1, 0);
	j = count_line_chars(s2, 0);
	i = (i < 0) ? (i * -1) : i;
	j = (j < 0) ? (j * -1) : j;
	string = (char *)malloc(sizeof(char) * (i + j));
	if (!string)
		return (0);
	i = 0;
	j = 0;
	l = 0;
	while (s1[l] != '\0')
		string[i++] = s1[l++];
	l = 0;
	while (s2[l] != '\0')
		string[i + j++] = s2[l++];
	string[i + j] = '\0';
	return (string);
}

char	*prepare_s1(t_cursor fd_store, int length)
{
	int				i;
	int				j;
	char			*s1;

	i = fd_store.value;
	j = 0;
	length = (length < 0) ? length * -1 : length;
	s1 = (char *)malloc(sizeof(char) * (length + 1));
	while (j < length)
	{
		s1[j] = fd_store.last[j + i];
		j++;
	}
	s1[j] = '\0';
	return (s1);
}

char	*prepare_s2(t_cursor *fd_store, int fd)
{
	char	buffer[BUFF_SIZE + 1];
	char	*tmp;
	char	*s2;
	int		length;
	int		ret;

	s2 = (char *)malloc(sizeof(char) * 1);
	s2[0] = '\0';
	while ((ret = read(fd, buffer, BUFF_SIZE)) && buffer[ret - 1] != '\n')
	{
		buffer[ret] = '\0';
		tmp = ft_strdup(s2);
		ft_strcpy(fd_store->last, buffer);
		length = count_line_chars(buffer, 0);
		length = (length < 0) ? (length * -1) : length;
		free (s2);
		s2 = ft_strjoin_nl(tmp, buffer);
		free(tmp);
		tmp = 0;
	}
	fd_store->value += length;
	return (s2);
}

int		get_next_line(const int fd, char **line)
{
	static t_cursor	fd_store[FD_MAX + 1];
	char			*s1;
	char			*s2;
	int				length;

	s1 = 0;
	if ((fd_store[fd]).touched == 1)
	{
		length = count_line_chars((fd_store[fd]).last, (fd_store[fd]).value);
		s1 = prepare_s1(fd_store[fd], length);
		if (length < 0)
		{
			fd_store[fd].value += (length * -1);
			*line = s1;
			return (1);
		}
	}
	else
		(fd_store[fd]).value = 0;
	(fd_store[fd]).touched = 1;
	s2 = prepare_s2(&(fd_store[fd]), fd);
	length = count_line_chars(s2, 0);
	*line = (s1 && s2) ? ft_strjoin(s1, s2) : ft_strdup(s2);
	free(s1);
	free(s2);
	(fd_store[fd]).value += length + 1;
	return (0);
}
