#include <fcntl.h>
#include <stdio.h>
#include "get_next_line.h"

// int main() {
// 	int fd;

// 	fd = open("text.txt", O_RDONLY);
// 	// printf("%s\n", get_next_line(fd));
// 	// printf("%s\n", get_next_line(fd));
// 	// printf("%s\n", get_next_line(fd));
// 	// printf("%s\n", get_next_line(fd));
// 	char *line = get_next_line(fd);
// 	// printf("line:%s", line);
// 	while (line) 
// 	{
// 		 printf("%s", line);
// 		 if (line)
// 			 free(line);
// 		 line = get_next_line(fd);
// 	}

// 	close(fd);

// 	return 0;   
// }

int main()
{
    int fd1, fd2, fd3;
	char	*str;
	int i = 1;

    fd1 = open("wind_in_the_willows.txt", O_RDONLY);
    fd2 = open("text.txt", O_RDONLY);
    fd3 = 1;
	str = get_next_line(fd1);

	if (!fd1|| !fd2|| !fd3)
		return (-1);
	while (i < 15)
	{
	str = get_next_line(fd1);
	printf("1:Line#%d, %s\n", i, str);
    free(str);
	str = get_next_line(fd2);
	printf("2:Line#%d, %s\n", i, str);
	free(str);
	str = get_next_line(fd3);
	printf("3:Line#%d, %s\n", i, str);
	free(str);
	i++;
}

	close(fd1);
	close(fd2);
	close(fd3);
	// char *line =  get_next_line(fd);
    // while(line)
    // {
    //     printf("%s", line);
    //     line = get_next_line(fd);
    // }

    // close(fd);

    return 0;
}