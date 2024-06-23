/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnakaza <tnakaza@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 16:08:20 by tnakaza           #+#    #+#             */
/*   Updated: 2024/06/23 19:45:38 by tnakaza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	ssize_t			bytes_read;
	char			*ptr_eol;
	static char		*buff = NULL;
	static size_t	pos = 0;
	static char		*res;
	char			*tmp;
	char			*tmp2;

	if (!buff)
		(char *)ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	buff[BUFFER_SIZE] = '\0';
	if (pos == 0)
	{
		bytes_read = read(fd, buff, BUFFER_SIZE);
		if (bytes_read == 0 || bytes_read == -1)
			return (NULL);
	}
	ptr_eol = ft_strchr(buff + pos, '\n');
	if (ptr_eol)
	{
		pos += ptr_eol - (buff + pos);
		if (!tmp)
			return (ft_substr(buff, pos, ptr_eol - (buff + pos)));
		else
		{
			res = (char *)ft_calloc(ft_strlen(res) + ptr_eol - (buff + pos) + 1, sizeof(char));
			ft_strlcpy(res, tmp, ft_strlen(tmp) + 1);
			ft_strlcat(res, buff + pos, ft_strlen(res) + ptr_eol - (buff + pos) + 1);
			return (tmp2);
		}
	}
	else
	return (res);
}
