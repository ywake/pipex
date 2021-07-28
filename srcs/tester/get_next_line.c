#include "tester.h"

#include "libft.h"
#define BUFFER_SIZE (1000)

int	myabort(char *rdbuf, char **line, char **remain)
{
	free_set((void **)&rdbuf, NULL);
	free_set((void **)line, NULL);
	free_set((void **)remain, NULL);
	return (-1);
}

int	ret(ssize_t rdrtn, char *rdbuf, char **line, char **remain)
{
	free_set((void **)&rdbuf, NULL);
	if (rdrtn > 0)
		rdrtn = 1;
	if (*line == NULL || (*remain == NULL && rdrtn != 0))
		rdrtn = myabort(rdbuf, line, remain);
	return (rdrtn);
}

int	get_next_line(int fd, char **line)
{
	char		*rdbuf;
	static char	*remain[1];
	char		*ptr;
	ssize_t		rtn;

	if (line == NULL)
		return (-1);
	if (set_rtn(&rdbuf, malloc(BUFFER_SIZE + 1)) == NULL)
		return (myabort(rdbuf, NULL, NULL));
	*line = *remain;
	*remain = NULL;
	while (set_rtn_long(&rtn, read(fd, rdbuf, BUFFER_SIZE)) >= 0)
	{
		rdbuf[rtn] = '\0';
		free_set((void **)line, ft_strjoin(*line, (char *)rdbuf));
		if (*line != NULL && set_rtn(&ptr, ft_strchr(*line, '\n')) != NULL)
		{
			*remain = ft_strdup(ptr + 1);
			free_set((void **)line, ft_strndup(*line, ptr - *line));
			return (ret(1, rdbuf, line, remain));
		}
		if (rtn == 0 || *line == NULL)
			return (ret(0, rdbuf, line, remain));
	}
	return (myabort(rdbuf, line, remain));
}
