#include "get_next_line.h"

void	copy_buf(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s2[i])
	{
		s1[i] = s2[i];
		i++;
	}
	s1[i] = '\0';
}

int	find_line(char *buf, char **line)
{
	int	i;
	int	j;
	int	newline_or_eof;
	char	*find_line;

	i = 0;
	j = 0;
	newline_or_eof = 0;
	while(buf[i] && buf[i] != '\n') // i++ while buffer reach end or \n
		i++;
	if (buf[i] == '\n')
		newline_or_eof = 1; // we are at the end of the line
	find_line = malloc(i + newline_or_eof + 1); // asking for memory
	if (!find_line)
		return(-1);
	while(j < i + newline_or_eof) // while have chars to write
	{
		find_line[j] = buf[j];
		j++;
	}
	*line = ft_strjoin(*line, find_line); // добавляем к текущей
	if (!line)
		return(-1);
	copy_buf(buf, &buf[i + newline_or_eof]); // записываем в буфер что осталось
	//ft_strlcpy(buf, &buf[i + newline_or_flag], i);
	return (newline_or_eof);
}

char *free_line(char **line)
{
	if (*line)
		free(*line);
	return(0);
}

char *get_next_line(int fd)
{
	static char buf[BUFFER_SIZE + 1];
	char	*line;
	int	count_byte;
	int	newline_or_eof;

	line = 0;
	newline_or_eof = 0;

	while (newline_or_eof == 0)
	{
		newline_or_eof = find_line(buf, &line); // ищем текст и добавляем в строку по кругу пока есть буфер
		if (newline_or_eof == -1)
			return(free_line(&line));
		if (newline_or_eof == 0)
		{
			count_byte = read(fd, buf, BUFFER_SIZE); // сколько байт считал, заполняем буфер
			if(count_byte == 0 && *line) // если дошел до конца и строка не пустая
				newline_or_eof = 1;
			else if (count_byte <= 0) // если ошибка или пусто
				return(free_line(&line));
			buf[count_byte] = '\0'; // конец строки
		}
	}
	return(line);

}

// int	main()
// {
// 	int	fd;
// 	char *p;
// 	//static char test1;
// 	static char test2[] = "line5678130000";
// 	//p = test2;
// 	//test1 = "test123412\0";
// 	//test2[] = "line567813";
// 	//copy_buf(test1, test2);

// 	// fd = open("text.txt", O_RDONLY);
// 	//test =  get_next_line(fd);

// 	//	printf("%s", get_next_line(fd));/
// 	//printf("%s", test1);
// 	copy_buf(&test2[0], &test2[10]);

// 	printf("%s", &test2[0]);

// 	return (0);
// }
