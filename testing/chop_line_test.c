/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chop_line_test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chford <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 10:41:40 by chford            #+#    #+#             */
/*   Updated: 2019/03/05 11:17:09 by chford           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../libft/libft.h"
#include "../get_next_line/get_next_line.h"

char	*chop_line(char **string)
{
	char	*new;
	int		length;
	int		i;

	length = 0;
	i = -1;
	while ((*string)[length] != '\0' && (*string)[length] != '\n')
		length++;
	if (!(new = (char *)malloc(sizeof(char) * (length + 1))))
		return (0);
	while (++i < length)
		new[i] = (*string)[i];
	i = 0;
	length++;
	if ((*string)[length - 1] == '\n')
	{
		while ((*string)[length] != '\0')
			(*string)[i++] = (*string)[length++];
	}
	(*string)[i] = '\0';
	return (new);
}

int		main(void)
{
	char	*string;
	char	*new;

	string = (char *)malloc(sizeof(char) * 13);
	string[0] = 'I';
	string[1] = ' ';
	string[2] = 'a';
	string[3] = 'm';
	string[4] = '\n';
	string[5] = 't';
	string[6] = 'e';
	string[7] = 's';
	string[8] = 't';
	string[9] = 'i';
	string[10] = 'n';
	string[11] = 'g';
	string[12] = '\0';
	new = chop_line(&string);
	if (strcmp(new, "I am"))
		printf("FAILED on return value of function chop_line\n");
	else
		printf("return value in function chop_line SUCCESS\n");
	printf("expected: I am\n");
	printf("returned: %s\n", new);
	if (strcmp(string, "testing"))
		printf("Failed on string modification in function chop_line\n");
	else
		printf("String modification in chop_line function SUCCESS");
	printf("expected: testing\n");
	printf("returned: %s\n", string);
	return (0);
}
