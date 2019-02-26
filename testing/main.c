/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chford <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 19:59:04 by chford            #+#    #+#             */
/*   Updated: 2019/02/26 10:04:51 by chford           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../get_next_line/libft/libft.h"
#include "../get_next_line/get_next_line.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>

int		main(void)
{
	char	*string;
	int		fd;

/*	fd = open ("book", O_WRONLY);
	if (fd == -1)
		ft_putstr("OPENING FAILED BOI");
	write(fd, "abcd", 4);
	if (close(fd) == -1)
		ft_putstr("Cant close");
*/	fd = open ("book", O_RDONLY);
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
