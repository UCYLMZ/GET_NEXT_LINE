#include "get_next_line_bonus.h"
#include <fcntl.h>
#include <stdio.h>

char	*read_line(int fd, char *holder)
{
	char	*buffer;
	int		amount;

	amount = 1;
	buffer = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	while (nl_checker(holder) && amount != 0)
	{
		amount = read(fd, buffer, BUFFER_SIZE);
		if (amount == -1)
		{
			free (buffer);
			return (NULL);
		}
		buffer[amount] = '\0';
		holder = ft_strjoin_v2(holder, buffer);
	}
	free (buffer);
	return (holder);
}

char	*get_next_line(int fd)
{
	static char	*holder[1024];
	char		*result;

	if (fd < 0 && BUFFER_SIZE <= 0)
		return (NULL);
	holder[fd] = read_line(fd, holder[fd]);
	if (!holder[fd])
		return (NULL);
	result = till_next_line(holder[fd]);
	holder[fd] = after_next_line(holder[fd]);
	return (result);
}

/*int main()
{
	int fd3 = open("test2.txt", O_RDONLY);
	int fd4 = open("test.txt", O_RDONLY);

	char *line;
	int i = 3;
	int j = 0;
	while (j < 10)
	{
		i = 3;
		while (i <= 4)
		{
			line = get_next_line_bonus(i);
			printf("%s", line);
			i++;
		}
		j++;
	}
	line = get_next_line(fd);
	printf("%s", line);

	line = get_next_line(fd);
	printf("*%03hhu*", line[5]);
	printf("%s", line);

	line = get_next_line(fd);
	printf("%s", line);

	line = get_next_line(fd);
	printf("%s", line);

	line = get_next_line(fd);
	printf("%s", line);

	line = get_next_line(fd);
	printf("%s", line);

	line = get_next_line(fd);
	printf("%s", line);
}*/