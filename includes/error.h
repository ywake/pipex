#ifndef ERROR_H
# define ERROR_H

void	pexit(char *str);
int		catch_err(int status, char *msg);
void	*catch_nul(void *ptr, char *msg);

#endif
