#include "pipex.h"

#include <stdio.h>
#include <unistd.h>

enum e_args
{
	INFILE = 1,
	CMD1,
	CMD2,
	OUTFILE,
};

int	main(int argc, char *argv[])
{
	// char	*file;

	(void)argc;
	// printf("file1: %s\ncmd1: %s\ncmd2: %s\nfile2: %s\n",
	// 	argv[INFILE], argv[CMD1], argv[CMD2], argv[OUTFILE]);
	redirect_in(argv[INFILE]);
	redirect_out(argv[OUTFILE]);
	execve("/bin/cat", NULL, NULL);
}
