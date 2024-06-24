/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnakaza <tnakaza@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 16:10:44 by tnakaza           #+#    #+#             */
/*   Updated: 2024/06/24 16:14:18 by tnakaza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*tmp;

	tmp = (unsigned char *) s;
	while (0 < n--)
		tmp[n] = 0;
	return ;
}

char	*ft_strchr(const char *s, int c)
{
	while (*s != '\0')
	{
		if (*s == (char) c)
			return ((char *) s);
		s++;
	}
	if ((char) c == '\0')
		return ((char *) s);
	return (NULL);
}

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (*s++ != '\0')
		len++;
	return (len);
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*tmp;

	if (!dst && !src)
		return (NULL);
	tmp = (unsigned char *) dst;
	while (tmp < (unsigned char *)dst + n)
		*tmp++ = *(unsigned char *)src++;
	return (dst);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*res;
	size_t	l1;
	size_t	l2;

	if (!s1 || !s2)
		return (NULL);
	l1 = ft_strlen(s1);
	l2 = ft_strlen(s2);
	res = (char *)malloc((l1 + l2 + 1) * (int)(sizeof(char)));
	if (res == NULL)
		return (NULL);
	ft_memcpy(res, s1, l1);
	ft_memcpy(res + l1, s2, l2);
	res[l1 + l2] = '\0';
	return (res);
}
