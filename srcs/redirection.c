#include "pipex.h"

#include <fcntl.h>
#include <unistd.h>
#include "error.h"

void	redirect_in(char *filename)
{
	int	fd;

	fd = open(filename, O_RDONLY);
	catch_err(fd, filename);
	catch_err(dup2(fd, STDIN_FILENO), "dup2");
	catch_err(close(fd), "close");
}

void	redirect_out(char *filename)
{
	int	fd;

	fd = open(filename, O_RDWR | O_CREAT | O_TRUNC, 0644);
	catch_err(fd, filename);
	catch_err(dup2(fd, STDOUT_FILENO), "dup2");
	catch_err(close(fd), "close");
}
