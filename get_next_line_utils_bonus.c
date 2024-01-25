/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbremser <jbremser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 11:52:55 by jbremser          #+#    #+#             */
/*   Updated: 2024/01/25 10:53:24 by jbremser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_strchr(const char *s, int c)
{
	int		len;
	char	ch;

	len = 0;
	ch = (char)c;
	if (!s)
		return (NULL);
	while (s[len])
	{
		if (s[len] == ch)
			return ((char *)&s[len]);
		else
			len++;
	}
	if (ch == 0)
		return ((char *)&s[len]);
	return (0);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*n;
	size_t	len;
	size_t	i;

	if ((!s1) || (!s2))
		return (NULL);
	len = (ft_strlen(s1) + ft_strlen(s2) + 1);
	n = malloc(len);
	if (n == NULL)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		n[i] = s1[i];
		i++;
	}
	n[i] = '\0';
	ft_strlcat(n, s2, len);
	return (n);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	slen;
	size_t	dlen;
	size_t	tlen;

	slen = 0;
	if (dstsize == 0)
		return (ft_strlen(src));
	dlen = (ft_strlen(dst));
	tlen = (ft_strlen(dst) + ft_strlen(src));
	if (dstsize < dlen || dstsize == 0)
		return (ft_strlen(src) + dstsize);
	while (src[slen] && (dlen < (dstsize - 1)))
		dst[dlen++] = src[slen++];
	dst[dlen] = '\0';
	return (tlen);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*dst;
	size_t	j;

	j = 0;
	if (start > ft_strlen(s) || s[0] == '\0' || len == 0)
	{
		dst = malloc(1);
		dst[0] = '\0';
		return (dst);
	}
	if (len > (ft_strlen(s + start)))
		len = (ft_strlen(s + start));
	dst = malloc(len + 1);
	if (!dst)
		return (NULL);
	while (s[start] && j < len)
		dst[j++] = s[start++];
	dst[j] = '\0';
	return (dst);
}
