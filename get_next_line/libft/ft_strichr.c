/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strichr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chford <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/24 19:24:36 by chford            #+#    #+#             */
/*   Updated: 2019/02/27 17:47:26 by chford           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strichr(const char *s, int c, int start)
{
	char	*str;
	char	ch;

	if ((size_t)start >= ft_strlen(s))
		return (0);
	str = (char *)s;
	ch = (char)c;
	while (str[start] != ch)
	{
		if (str[start] == '\0')
			return (0);
		start++;
	}
	return (str + start);
}
