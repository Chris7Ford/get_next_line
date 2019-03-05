/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chford <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 19:59:04 by chford            #+#    #+#             */
/*   Updated: 2019/03/05 13:33:12 by chford           ###   ########.fr       */
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
	char	*str;
	int		fd;

	fd = open ("book", O_WRONLY);
	if (fd == -1)
		ft_putstr("OPENING FAILED\n");
	write(fd, "abcdefghijklmnop\n", 17);
	write(fd, "qrstuvwxyzabcdef\n", 17);
	write(fd, "ghijklmnopqrstuv\n", 17);
	write(fd, "wxyzabcdefghijkl\n", 17);
	write(fd, "mnopqrstuvwxyzab\n", 17);
	write(fd, "cdefghijklmnopqr\n", 17);
	write(fd, "stuvwxzabcdefghi\n", 17);
	if (close(fd) == -1)
		ft_putstr("Cant close\n");
	fd = open ("book", O_RDONLY);
	if (fd == -1)
		ft_putstr("OPENING FAILED\n");
	while (get_next_line(fd, &str) == 1)
	{
		ft_putstr(str);
		ft_putchar('\n');
	}
	return (0);


}
