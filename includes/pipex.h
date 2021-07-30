#ifndef PIPEX_H
# define PIPEX_H

# define BUFSIZE	(1)

char	*readfile(char *filename);
void	redirect_in(char *filename);
void	redirect_out(char *filename);

#endif
