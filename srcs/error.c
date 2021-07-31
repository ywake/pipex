#include "error.h"

#include <stdio.h>
#include <stdlib.h>

void	pexit(char *str)
{
	perror(str);
	exit(1);
}

void	exit_if_err(int status, char *msg)
{
	if (status == -1)
		pexit(msg);
}
