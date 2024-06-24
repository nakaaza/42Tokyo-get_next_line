/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnakaza <tnakaza@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 16:08:20 by tnakaza           #+#    #+#             */
/*   Updated: 2024/06/24 15:22:03 by tnakaza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char static	*read_line(int fd, char *s);

char	*get_next_line(int fd)
{
	return (read_line(fd, ""));
}

char static	*read_line(int fd, char *s)
{
	static char	buff[BUFFER_SIZE + 1];
	char		*tmp;
	char		*res;
	char		*ptr_eol;

	if (ft_strlen(buff) == 0)
	{
		if (read(fd, buff, BUFFER_SIZE) <= 0)
		{
			if (ft_strlen(buff) == 0 && ft_strlen(s) == 0)
				return (NULL);
			res = ft_strjoin(s, buff);
			return (res);
		}
	}
	ptr_eol = ft_strchr(buff, '\n');
	if (!ptr_eol)
	{
		tmp = ft_strjoin(s, buff);
		ft_bzero(buff, BUFFER_SIZE + 1);
		res = read_line(fd, tmp);
		free(tmp);
		return (res);
	}
	else
	{
		tmp = ft_substr(buff, 0, ptr_eol - buff + 1);
		ft_memcpy(buff, ptr_eol + 1, ft_strlen(buff) + 1 - (ptr_eol - buff));
		ft_bzero(buff + ft_strlen(buff), BUFFER_SIZE - ft_strlen(buff));
		res = ft_strjoin(s, tmp);
		free(tmp);
		return (res);
	}
}
