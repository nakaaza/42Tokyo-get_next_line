/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnakaza <tnakaza@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 16:10:44 by tnakaza           #+#    #+#             */
/*   Updated: 2024/06/23 19:17:16 by tnakaza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
	return ;
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*res;

	if (size != 0 && SIZE_MAX / size < count)
		return (NULL);
	res = malloc(count * size);
	if (res == NULL)
		return (NULL);
	ft_bzero(res, count * size);
	return (res);
}

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*tmp;

	tmp = (unsigned char *) b;
	while (0 < len--)
		tmp[len] = (unsigned char) c;
	return (b);
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

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*res;
	size_t	n;
	int		l;

	if (!s)
		return (NULL);
	n = ft_strlen(s);
	if (n <= start)
		l = 0;
	else if (n - start > len)
		l = len;
	else
		l = n - start;
	res = (char *)malloc((l + 1) * (int) sizeof(char));
	if (res == NULL)
		return (NULL);
	res[l] = '\0';
	while (0 <= --l)
		res[l] = s[start + l];
	return (res);
}

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (*s++ != '\0')
		len++;
	return (len);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	src_len;
	size_t	cpy_len;

	src_len = ft_strlen(src);
	if (dstsize == 0)
		return (src_len);
	if (dstsize - 1 < src_len)
		cpy_len = dstsize - 1;
	else
		cpy_len = src_len;
	ft_memcpy(dst, src, cpy_len);
	dst[cpy_len] = '\0';
	return (src_len);
}

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dst_len;
	size_t	src_len;
	size_t	cat_len;

	src_len = ft_strlen(src);
	if (dstsize == 0)
		return (dstsize + src_len);
	dst_len = ft_strlen(dst);
	if (dstsize <= dst_len)
		return (dstsize + src_len);
	if (dstsize - dst_len - 1 < src_len)
		cat_len = dstsize - dst_len - 1;
	else
		cat_len = src_len;
	ft_memcpy(dst + dst_len, src, cat_len);
	dst[dst_len + cat_len] = '\0';
	return (dst_len + src_len);
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
