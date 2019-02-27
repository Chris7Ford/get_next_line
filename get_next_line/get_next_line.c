/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chford <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 09:59:02 by chford            #+#    #+#             */
/*   Updated: 2019/02/26 18:53:56 by chford           ###   ########.fr       */
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
	free(s1);
	l = 0;
	while (s2[l] != '\0' && s2[l] != '\n')
		string[i + j++] = s2[l++];
	string[i + j] = '\0';
	return (string);
}

char	*prepare_s1(t_cursor *fd_s, int *length, char **line)
{
	int				j;
	char			*s1;

	if (!(s1 = (char *)malloc(sizeof(char) * 1)))
		return (0);
	s1[0] = '\0';
	*length = count_line_chars(fd_s->s, fd_s->value);
	*length = (*length < 0) ? (*length) * -1 : *length;
	if (fd_s->complete && fd_s->value != 0 && fd_s->s[(fd_s->value)] == '\0')
		return (s1);
	j = -1;
	free(s1);
	if (!(s1 = (char *)malloc(sizeof(char) * (*length + 1))))
		return (0);
	while (++j < *length)
		s1[j] = (fd_s->s)[j + fd_s->value];
	s1[j] = '\0';
	fd_s->value += *length + 1;
	if ((fd_s->s)[fd_s->value - 1] == '\n')
	{
		*length = -1;
		*line = s1;
	}
	return (s1);
}

char	*prepare_s2(t_cursor *f, int fd, int *return_val, int i)
{
	char	*s2;
	int		length;
	int		r;

	s2 = (char *)ft_memalloc(sizeof(char) * 1);
	i = f->value;
	while (!(ft_strichr(f->s, '\n', i)) && (r = read(fd, f->s, BUFF_SIZE)) > 0)
	{
		((f)->s)[r] = '\0';
		length = count_line_chars(f->s, 0);
		length = (length < 0) ? (length * -1) : length;
		i = 0;
		if (!(s2 = ft_strjoin_nl(s2, f->s)))
			return ("");
		f->value = length + 1;
	}
	f->touched = 1;
	*return_val = (r == 0) ? 0 : 1;
	if (r == -1)
		*return_val = -1;
	if (r < BUFF_SIZE && ft_strlen(f->s) == (size_t)(length + 1))
		*return_val = 0;
	f->complete = (r < BUFF_SIZE) ? 1 : 0;
	return (s2);
}

int		get_next_line(const int fd, char **line)
{
	static t_cursor	fd_store[FD_MAX + 1];
	char			*s1;
	char			*s2;
	int				length;

	if (fd < 0 || !line)
		return (-1);
	s1 = 0;
	if ((fd_store[fd]).touched == 1)
	{
		if (!(s1 = prepare_s1(&(fd_store[fd]), &length, line)))
			return (-1);
		if (length < 0)
			return (1);
	}
	else
		(fd_store[fd]).value = 0;
	s2 = prepare_s2(&(fd_store[fd]), fd, &length, 0);
	if (!(*line = (s1 && s2) ? ft_strjoin(s1, s2) : ft_strdup(s2)))
		return (-2);
	free(s1);
	free(s2);
	return (length);
}
