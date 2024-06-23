/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnakaza <tnakaza@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 14:45:04 by tnakaza           #+#    #+#             */
/*   Updated: 2024/06/23 18:59:48 by tnakaza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>

int	main(int argc, char **argv)
{
	int		fd;
	char	*str;

	errno = 0;
	if (argc == 1)
		fd = STDIN_FILENO;
	else if (argc == 2)
		fd = open(argv[1], O_RDONLY);
	else
		return (0);
	setvbuf(stdout, NULL, _IONBF, 0);
	str = get_next_line(fd);
	while (str)
	{
		printf("%s", str);
		free(str);
		str = get_next_line(fd);
	}
	if (errno == 0)
		printf("\033[0;90m[End of file]\033[0;90m\n");
	else
		printf("\033[0;91m%s\033[0;39m\n", strerror(errno));
	free(str);
	close(fd);
	return (0);
}
