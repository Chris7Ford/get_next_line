/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chford <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/17 09:31:37 by chford            #+#    #+#             */
/*   Updated: 2019/02/20 10:12:06 by chford           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*link;
	t_list	*next;

	if (!alst)
		return ;
	link = *alst;
	while (link)
	{
		next = link->next;
		del(link->content, link->content_size);
		free(link);
		link = next;
	}
	*alst = 0;
	return ;
}
