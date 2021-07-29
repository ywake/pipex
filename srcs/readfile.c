#include "pipex.h"

#include <stdlib.h>
#include <fcntl.h>
#include "libft.h"
#include "error.h"

char	*readfile(char *filename)
{
	int		fd;
	char	*rdbuf;
	int		rdrtn;
	char	*content;

	fd = open(filename, O_RDONLY);
	rdbuf = malloc(BUFSIZE + 1);
	if (fd < 0 || rdbuf == NULL)
		pexit("Error");
	content = NULL;
	while (1)
	{
		rdrtn = read(fd, rdbuf, BUFSIZE);
		if (rdrtn <= 0)
			break ;
		rdbuf[rdrtn] = '\0';
		free_set((void **)&content, ft_strjoin(content, rdbuf));
		if (content == NULL)
			pexit("Error");
	}
	close(fd);
	free(rdbuf);
	if (rdrtn == -1)
		pexit("Error");
	return (content);
}
