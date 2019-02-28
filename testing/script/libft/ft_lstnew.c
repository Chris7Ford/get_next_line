/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chford <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/16 19:24:45 by chford            #+#    #+#             */
/*   Updated: 2019/02/19 17:08:56 by chford           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*link;

	link = (t_list *)malloc(sizeof(t_list));
	if (link)
	{
		if (content)
		{
			link->content = (void *)malloc(content_size);
			ft_memcpy(link->content, content, content_size);
			link->content_size = content_size;
			link->next = 0;
		}
		else
		{
			link->content = 0;
			link->content_size = 0;
			link->next = 0;
		}
	}
	else
		return (0);
	return (link);
}
