/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chford <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 09:59:02 by chford            #+#    #+#             */
/*   Updated: 2019/02/24 20:19:36 by chford           ###   ########.fr       */
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
	string = (char *)malloc(sizeof(char) * (i + j + 1));
	if (!string)
		return (0);
	i = 0;
	j = 0;
	l = 0;
	while (s1[l] != '\0' && s1[l] != '\n')
		string[i++] = s1[l++];
	l = 0;
	while (s2[l] != '\0' && s2[l] != '\n')
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
	if(!(s1 = (char *)malloc(sizeof(char) * (length + 1))))
		return (0);
	while (j < length)
	{
		s1[j] = (fd_store.s)[j + i];
		j++;
	}
	s1[j] = '\0';
	return (s1);
}

char	*prepare_s2(t_cursor *f, int fd, int *return_val)
{
	char	*tmp;
	char	*s2;
	int		length;
	int		ret;

	s2 = (char *)malloc(sizeof(char) * 1);
	s2[0] = '\0';
	while (!(ft_strichr(f->s, '\n', f->value)) && (ret = read(fd, f->s, BUFF_SIZE)))
	{
		((f[fd]).s)[ret] = '\0';
		if (!(tmp = ft_strdup(s2)))
			return (0);
		length = count_line_chars(f->s, 0);
		length = (length < 0) ? (length * -1) : length;
		free (s2);
		f->value = 0;
		if (!(s2 = ft_strjoin_nl(tmp, f->s)))
			return (0);
		free(tmp);
		tmp = 0;
	}
	f->touched = 1;
	*return_val = (ret == 0) ? 0 : 1;
	f->value = length + 1;
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
		length = count_line_chars((fd_store[fd]).s, (fd_store[fd]).value);
		if (!(s1 = prepare_s1(fd_store[fd], length)))
			return (-1);
		if (length < 0)
		{
			*line = s1;
			return (1);
		}
	}
	else
		(fd_store[fd]).value = 0;
	s2 = prepare_s2(&(fd_store[fd]), fd, &length);
	if (!(*line = (s1 && s2) ? ft_strjoin(s1, s2) : ft_strdup(s2)))
		return (-1);
	free(s1);
	free(s2);
	return (length);
}
