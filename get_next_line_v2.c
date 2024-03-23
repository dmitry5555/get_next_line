/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmitrylarionov <dmitrylarionov@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 19:09:33 by dmitrylario       #+#    #+#             */
/*   Updated: 2023/04/30 16:08:11 by dmitrylario      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
				free(word);
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
		{
			if (word[0])
				return(word);
			free(word);
			return (void *)0;
		}
		
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
	if (j == 0 && b[i] == '\n')
	{
		free(word);
		word = malloc(2);
		word[0] = '\n';
		word[1] = '\0';
	}
	if (word[0])
		return (word);
	free(word);
	return (void *)0;
}

int	main()
{
	//char	*line;
	int		fd;
	char	*a;
	int	BUFFER_SIZE = 100;
	
	//line = "hello world";
	//fd = open("text.txt", O_RDONLY);
	fd = open("gnlTester/files/alternate_line_nl_with_nl", O_RDONLY);
	//get_next_line(fd, &line);
	// printf("%s\n", get_next_line(fd));
	// printf("%s\n", get_next_line(fd));
	// printf("%s\n", get_next_line(fd));
	// printf("%s\n", get_next_line(fd));
	// printf("%s\n", get_next_line(fd));
	// printf("%s\n", get_next_line(fd));
	// printf("%s\n", get_next_line(fd));
	// printf("%s\n", get_next_line(fd));
	// printf("%s\n", get_next_line(fd));
	// printf("%s\n", get_next_line(fd));
	// printf( get_next_line();)
	a = get_next_line(fd);
	while (a)
	{
		printf("%s", a);
		a = get_next_line(fd);
	}
	close(fd);
	return(0);
}