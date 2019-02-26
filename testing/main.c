/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chford <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 19:59:04 by chford            #+#    #+#             */
/*   Updated: 2019/02/25 20:08:28 by chford           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../get_next_line/libft/libft.h"
#include "../get_next_line/get_next_line.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int		main(void)
{
	char	*string;
	int		fd;

	fd = open ("book", O_RDONLY);
	if (fd == -1)
		ft_putstr("OPENING FAILED BOI");
	while (get_next_line(fd, &string) == 1)
	{
		ft_putstr(string);
		ft_putchar('\n');
		free(string);
	}
	return (0);
}
