/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chford <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 19:59:04 by chford            #+#    #+#             */
/*   Updated: 2019/02/27 08:45:54 by chford           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../get_next_line/libft/libft.h"
#include "../../get_next_line/get_next_line.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>

int		main(void)
{
	char	*str;
	int		result;
	int		fd2;
	int		fd;

	fd2 = open ("output.txt", O_WRONLY);
	if (fd2 == -1)
		ft_putstr("OPENING FAILED BOI");
	fd = open ("Test_file.txt", O_RDONLY);
	if (fd == -1)
		ft_putstr("OPENING FAILED BOI");
	result = get_next_line(fd, &str);
	ft_putstr_fd(str, fd2);
	ft_putchar_fd('\n', fd2);
	free(str);
	while (result == 1)
	{
		result = get_next_line(fd, &str);
		ft_putstr_fd(str, fd2);
		if (result == 1)
			ft_putchar_fd('\n', fd2);
		free(str);
	}
	
	if (close(fd) == -1)
		ft_putstr("Cant close");
	return (0);
}
