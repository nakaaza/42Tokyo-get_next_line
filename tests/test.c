/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnakaza <tnakaza@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 14:45:04 by tnakaza           #+#    #+#             */
/*   Updated: 2024/06/25 16:00:56 by tnakaza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../get_next_line.h"
#include <stdio.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>

#define DEF_COLOR	"\033[0;39m"
#define GRAY		"\033[0;90m"
#define RED			"\033[0;91m"
#define GREEN		"\033[0;92m"
#define YELLOW		"\033[0;93m"
#define BLUE		"\033[0;94m"
#define MAGENTA		"\033[0;95m"
#define CYAN		"\033[0;96m"
#define WHITE		"\033[0;97m"

int	main(int argc, char **argv)
{
	int		fd;
	char	*str;
	size_t	l;

	errno = 0;
	l = 1;
	if (argc == 1)
		fd = STDIN_FILENO;
	else if (argc == 2)
		fd = open(argv[1], O_RDONLY);
	else
		return (0);
	setvbuf(stdout, NULL, _IONBF, 0);
	printf(DEF_COLOR);
	str = get_next_line(fd);
	while (str)
	{
		printf(YELLOW "%3zu | " DEF_COLOR "%s", l++, str);
		free(str);
		str = get_next_line(fd);
	}
	if (errno == 0)
		printf(GRAY "[End of file]\n" DEF_COLOR);
	else
		printf(RED "ERROR!: %s\n" DEF_COLOR, strerror(errno));
	free(str);
	close(fd);
	return (0);
}
