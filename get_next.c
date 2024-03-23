
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#ifndef BUFFER_SIZE
#	define BUFFER_SIZE 100
#endif

// int	print_line(char *buf)
// {
// 	char	*line;
// 	int		i;
// 	static	char	*current_pos;

// 	i = 0;
// 	//line = ft_calloc(10,1);
// 	//line = ft_strdup(buf);
// 	while (buf[i])
// 	{
// 		write(1,&buf[i],1);
// 		i++;
// 	}

// 	return(0);
// }

char *get_next_line(int fd)
{
	static int	i;
	int		j;
	static int	count_lines;
	static char	b[BUFFER_SIZE + 1];
	char	*word;
	char	*word2;
	char	*word3;
	long	count;

	// if (read(fd, (void *)0, 0) != 0 || BUFFER_SIZE <= 0)
	// 	return (void *)0;
	word = malloc(1);
	word[0] = '\0';
	if (b[i] == '\n')
		i++;
	j = 0;
	while (count_lines == 0 || b[i] != '\n')
	{
		if (b[i] == '\0')
		{
			count = read(fd, b, BUFFER_SIZE);
			if (count <= 0)
			{
				if (word[0])
					return (word);
				else
					return (void *)0;
			}
			b[count] = '\0';
			i = 0;
		}
		j = 0;
		while (b[i + j] && b[i + j] != '\n')
			j++;
		word2 = malloc(j + 1 + (b[i + j] == '\n'));
		if (!word2)
			return (word);
		j = 0;
		while (b[i] && b[i] != '\n')
		{
			word2[j] = b[i];
			i++;
			j++;
		}
		if (b[i] == '\n')
		{
			count_lines++;
			word2[j++] = '\n';
		}
		word2[j] = '\0';
		word3 = ft_strjoin(word, word2);
		free(word);
		free(word2);
		word = word3;
	}
	if (word[0])
		return (word);
	return (void *)0;



}

int	main()
{
	char	*line;
	int		fd;
	
	//line = "hello world";
	fd = open("text.txt", O_RDONLY);
	//get_next_line(fd, &line);
	printf("%s\n", get_next_line(fd));
	printf("%s\n", get_next_line(fd));
	printf("%s\n", get_next_line(fd));
	printf("%s\n", get_next_line(fd));
	printf("%s\n", get_next_line(fd));
	printf("%s\n", get_next_line(fd));
	printf("%s\n", get_next_line(fd));
	printf("%s\n", get_next_line(fd));
	printf("%s\n", get_next_line(fd));
	printf("%s\n", get_next_line(fd));
	// printf( get_next_line();)
	return(0);
}