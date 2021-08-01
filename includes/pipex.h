#ifndef PIPEX_H
# define PIPEX_H

void	redirect_in(char *filename);
void	redirect_out(char *filename);
void	exec_cmd(char *argv[], char *envp[], int index);

#endif
