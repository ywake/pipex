#include "error.h"

#include <stdio.h>
#include <stdlib.h>

void	pexit(char *str)
{
	perror(str);
	exit(1);
}
