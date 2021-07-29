#include "pipex.h"

#include <stdio.h>

enum e_args
{
	FILE1 = 1,
	CMD1,
	CMD2,
	FILE2,
};

int	main(int argc, char *argv[])
{
	char	*file;

	(void)argc;
	printf("file1: %s\ncmd1: %s\ncmd2: %s\nfile2: %s\n",
		argv[FILE1], argv[CMD1], argv[CMD2], argv[FILE2]);
	file = readfile(argv[FILE1]);
	printf("%s\n", file);
}
