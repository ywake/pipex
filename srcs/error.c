#include "error.h"

#include <stdio.h>
#include <stdlib.h>

void	pexit(char *str)
{
	perror(str);
	exit(1);
}

int	catch_err(int status, char *msg)
{
	if (status == -1)
		pexit(msg);
	return (status);
}

void	*catch_nul(void *ptr, char *msg)
{
	if (ptr == NULL)
		pexit(msg);
	return (ptr);
}
