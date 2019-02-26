/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chford <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 18:47:04 by chford            #+#    #+#             */
/*   Updated: 2019/02/19 19:28:24 by chford           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		count_words(char const *string, char c)
{
	int			i;
	int			count;

	i = 0;
	count = 0;
	while (string[i] == c)
		i++;
	if (string[i] != '\0')
		count++;
	while (string[i] != '\0')
	{
		if (string[i] == c && string[i + 1] != c && string[i + 1] != '\0')
			count++;
		i++;
	}
	return (count);
}

static void		make_space_for_words(char **array, char const *string, char c)
{
	int			i;
	int			j;
	int			l;

	i = 0;
	j = 0;
	l = 0;
	while (string[i] == c)
		i++;
	while (string[i] != '\0')
	{
		if (string[i] != c)
			j++;
		if ((string[i] == c && string[i + 1] != c && string[i] != '\0') ||
				string[i + 1] == '\0')
		{
			array[l] = (char *)malloc(sizeof(char) * j + 1);
			if (!array[l])
				return ;
			l++;
			j = 0;
		}
		i++;
	}
	return ;
}

static void		fill_it_up(char **array, char const *string, char c)
{
	int			i;
	int			j;
	int			l;

	i = 0;
	j = 0;
	l = 0;
	while (string[i] == c)
		i++;
	while (string[i] != '\0')
	{
		if (string[i] != c)
		{
			array[l][j++] = string[i];
		}
		if ((string[i] == c && string[i + 1] != c && string[i] != '\0') ||
				string[i + 1] == '\0')
		{
			array[l][j] = '\0';
			l++;
			j = 0;
		}
		i++;
	}
	array[l] = 0;
}

char			**ft_strsplit(char const *s, char c)
{
	char		**array;
	int			size;

	if (!s)
		return (0);
	size = count_words(s, c);
	array = (char **)malloc(sizeof(char *) * size + 1);
	if (!array)
		return (0);
	if (size == 0)
	{
		array[0] = 0;
		return (array);
	}
	make_space_for_words(array, s, c);
	fill_it_up(array, s, c);
	return (array);
}
