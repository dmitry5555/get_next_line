#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

char	*get_next_line(int fd);
int	main(int ac, char **av)
{
	char	*gnl;
	int	fd;

	if (ac != 2) {
		printf("Invalid number of arguments");
		return (1);
	}
	fd = open(av[1], O_RDONLY);
	gnl = get_next_line(fd);
	printf("first read = %s", gnl);
	gnl = get_next_line(fd);
	printf("second read = %s", gnl);
	return (0);
}	
