/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnakaza <tnakaza@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 14:45:04 by tnakaza           #+#    #+#             */
/*   Updated: 2024/06/25 16:01:01 by tnakaza          ###   ########.fr       */
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
	int		fd1, fd2, fd3;
	char	*str1, *str2, *str3;
	size_t	l = 1;

	errno = 0;
	if (argc != 4)
	{
		printf(RED "Argument Error\n" DEF_COLOR);
		return (0);
	}
	fd1 = open(argv[1], O_RDONLY);
	fd2 = open(argv[2], O_RDONLY);
	fd3 = open(argv[3], O_RDONLY);
	setvbuf(stdout, NULL, _IONBF, 0);
	printf(DEF_COLOR "Applying get_next_line() for 3 fds: " GREEN "A - %s" DEF_COLOR ", " YELLOW "B - %s" DEF_COLOR ", "  CYAN "C - %s\n" DEF_COLOR, argv[1], argv[2], argv[3]);
	str1 = get_next_line(fd1);
	str2 = get_next_line(fd2);
	str3 = get_next_line(fd3);
	while (str1 || str2 || str3)
	{
		if(str1)
		{
			printf(GREEN  "A-%03zu | " DEF_COLOR "%s", l, str1);
			if(!strchr(str1, '\n'))
				printf(GRAY "[no \\n]\n" DEF_COLOR);
		}
		if(str2)
		{
			printf(YELLOW "B-%03zu | " DEF_COLOR "%s", l, str2);
			if(!strchr(str2, '\n'))
				printf(GRAY "[no \\n]\n" DEF_COLOR);
		}
		if(str3)
		{
			printf(CYAN   "C-%03zu | " DEF_COLOR "%s", l, str3);
			if(!strchr(str3, '\n'))
				printf(GRAY "[no \\n]\n" DEF_COLOR);
		}
		free(str1); free(str2); free(str3);
		str1 = get_next_line(fd1);
		str2 = get_next_line(fd2);
		str3 = get_next_line(fd3);
		l++;
	}
	if (errno == 0)
		printf(GRAY "[End of output]\n" DEF_COLOR);
	else
		printf(RED "ERROR!: %s\n" DEF_COLOR, strerror(errno));
	free(str1); free(str2); free(str3);
	close(fd1); close(fd2); close(fd3);
	return (0);
}
