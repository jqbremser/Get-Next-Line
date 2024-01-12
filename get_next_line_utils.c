/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   get_next_line_utils.c							  :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: jbremser <jbremser@student.42.fr>		  +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2023/12/28 16:00:44 by jbremser		  #+#	#+#			 */
/*   Updated: 2024/01/07 11:56:50 by jbremser		 ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "get_next_line.h"

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

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*n;
	size_t	len;
	size_t	i;

	if ((!s1) || (!s2))
		return (NULL);
	len = (ft_strlen(s1) + ft_strlen(s2) + 1);
	n = ft_calloc(len, sizeof(char));
	if (n == NULL)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		n[i] = s1[i];
		i++;
	}
	ft_strlcat(n, s2, len);
	return (n);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*dst;
	size_t	j;

	j = 0;
	if (start > ft_strlen(s))
		return ((char *)ft_calloc(1, 1));
	if (len > (ft_strlen(s + start)))
		len = (ft_strlen(s + start));
	dst = (char *)ft_calloc((len + 1), sizeof(char));
	if (!dst)
		return (NULL);
	while (s[start] && j < len)
		dst[j++] = s[start++];
	return (dst);
}

char	*ft_strchr(const char *s, int c)
{
	int		len;
	char	ch;

	len = 0;
	ch = (char)c;
	if (!s)
		return (NULL);
	while (s[len] != '\0')
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

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;

	if ((count > 0) && (size > 0))
		if ((count * size) % size != 0 \
			|| (count * size) % count != 0)
			return (NULL);
	ptr = (void *)malloc (sizeof(char) * count * size);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, count * size);
	return (ptr);
}
void	ft_bzero(void *s, size_t n)
{
	size_t	i;
	char	*ptr;

	i = 0;
	ptr = (char *)s;
	while (i < n)
		ptr[i++] = 0;
}
// void	ft_bzero(void *s, size_t n)
// {
// 	size_t	i;
// 	char	*ptr;

// 	i = 0;
// 	ptr = (char *)s;
// 	while (i < n)
// 		ptr[i++] = 0;
// }

// char	*ft_strrchr(const char *s, int c)
// {
// 	int		i;
// 	char	ch;

// 	i = ft_strlen((char *)s);
// 	ch = (char)c;
// 	while (i >= 0)
// 	{
// 		if (s[i] == ch)
// 			return ((char *)&s[i]);
// 		else
// 			i--;
// 	}
// 	if (c == 0)
// 		return ((char *)&s[i]);
// 	return (0);
// }