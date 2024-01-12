/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbremser <jbremser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 12:54:36 by jbremser          #+#    #+#             */
/*   Updated: 2024/01/09 10:41:56 by jbremser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void	freenull(void *ptr)
{
	free(ptr);
	ptr = NULL;
}

static char	*ft_trimsuffix(char *stash, t_my_gnl *gnl)
{
	if (!gnl->line)
	{
		freenull(stash);
		return (NULL);
	}
	gnl->strchrresult = (ft_strchr(stash, '\n'));
	if (!gnl->strchrresult)
	{
		freenull(stash);
		return (NULL);
	}
	else if (ft_strchr(stash, '\n') && ft_strlen(gnl->strchrresult) == 1)
	{
		freenull(stash);
		return (NULL);
	}
	gnl->ptr_parking = stash;
	stash = ft_substr(stash, (gnl->strchrresult - stash) + 1, ft_strlen(stash));
	free(gnl->ptr_parking);
	gnl->ptr_parking = NULL;
	return (stash);
}

static char	*ft_trimprefix(char *stash, t_my_gnl *gnl)
// {
// 	if (!stash)
// 		return (NULL);
// 	gnl->i = 0;
// 	while (stash[gnl->i] != '\0' && stash[gnl->i] != '\n')
// 		gnl->i++;
// 	if (stash[gnl->i] == '\n')
// 		gnl->i++;
// 	gnl->line = malloc(gnl->i + 1);
// 	if (gnl->line == NULL)
// 	{
// 		return (NULL);
// 	}
// 	gnl->k = 0;
// 	while (gnl->k < gnl->i)
// 	{
// 		gnl->line[gnl->k] = stash[gnl->k];
// 		gnl->k++;
// 	}
// 	gnl->line[gnl->k] = '\0';
// 	return (gnl->line);
// }

{
	if (!stash)
		return (NULL);
	gnl->i = 0;
	while (stash[gnl->i] != '\n' && stash[gnl->i] != '\0')
		gnl->i++;
	if (stash[gnl->i] == '\n')
		gnl->i++;
	gnl->trim_prefix = malloc(gnl->i + 1);
	if (gnl->trim_prefix == NULL)
		return (NULL);
	gnl->k = 0;
	while (gnl->k < gnl->i)
	{
		gnl->trim_prefix[gnl->k] = stash[gnl->k];
		gnl->k++;
	}
		gnl->trim_prefix[gnl->k] = '\0';
	return (gnl->trim_prefix);
}

//empty the stash before copying
static char	*line_read(int fd, char *stash, t_my_gnl *gnl)
{
	while (!ft_strchr(stash, '\n') && gnl->bytes_read != 0)
	{
		gnl->bytes_read = read(fd, gnl->str_buf, BUFFER_SIZE);
		if (gnl->bytes_read == 0 || gnl->bytes_read == -1)
		{
			if (gnl->bytes_read == -1)
				freenull(stash);
			if (gnl->bytes_read == 0)
				return(stash);
			return (NULL);
		}
		gnl->str_buf[gnl->bytes_read] = '\0';
		if (stash == NULL)
		{
			stash = malloc(1);
			if (!stash)
				return (NULL);
			stash[0] = '\0';
		}
		gnl->ptr_parking = stash;
		stash = ft_strjoin(stash, gnl->str_buf);
		freenull(gnl->ptr_parking);
	}
	return (stash);
}

// add trimmed prefix to final line
//	gnl.line = 
//trim the suffix off the end of the stash
char	*get_next_line(int fd)
{
	static char	*stash;
	t_my_gnl	gnl;

	if (fd < 0 || fd > 1023 || BUFFER_SIZE <= 0)
		return (NULL);
	gnl.ptr_parking = NULL;
	gnl.bytes_read = 1;
	if (!ft_strchr(stash, '\n'))  
	{
		gnl.str_buf = malloc(BUFFER_SIZE + 1);
		if (!gnl.str_buf)
		{
			if (stash != NULL)
				freenull(stash);
			return (NULL);
		}
		stash = line_read(fd, stash, &gnl);
		freenull(gnl.str_buf);
	}
	gnl.line = ft_trimprefix(stash, &gnl);
	stash = ft_trimsuffix(stash, &gnl);
	return (gnl.line);
}
// #include <fcntl.h>
// #include <stdio.h>
// #include "get_next_line.h"

// int main() {
// 	int fd;

// 	fd = open("text.txt", O_RDONLY);
// 	printf("%s\n", get_next_line(fd));
// 	printf("%s\n", get_next_line(fd));
// 	printf("%s\n", get_next_line(fd));
// 	printf("%s\n", get_next_line(fd));
// 	// char *line = get_next_line(fd);
// 	// printf("%s\n", line);
// 	// while (line) 
// 	// {
// 	// 	 printf("%s.\n", line);
// 	// 	 if (line)
// 	// 		 free(line);
// 	// 	 line = get_next_line(fd);
// 	// }

// 	close(fd);

// 	return 0;   
// }
