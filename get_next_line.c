#include "get_next_line.h"
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
			return (NULL);
		buffer[amount] = '\0';
		holder = ft_strjoin_v2(holder, buffer);
	}
	free (buffer);
	return (holder);
}

char	*get_next_line(int fd)
{
	static char	*holder;
	char		*result;

	if (fd < 0 && BUFFER_SIZE <= 0)
		return (NULL);
	holder = read_line(fd, holder);
	if (!holder)
		return (NULL);
	result = till_next_line(holder);
	holder = after_next_line(holder);
	return (result);
}

int main()
{
	int fd = open("test2.txt", O_RDONLY);

	char *line;
	line = get_next_line(fd);
	printf("%s", line);

	line = get_next_line(fd);
	//printf("*%03hhu*", line[5]);
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
}