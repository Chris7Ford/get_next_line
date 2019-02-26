/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strichr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chford <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/24 19:24:36 by chford            #+#    #+#             */
/*   Updated: 2019/02/24 19:28:24 by chford           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strichr(const char *s, int c, int start)
{
	char	*str;
	char	ch;

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
