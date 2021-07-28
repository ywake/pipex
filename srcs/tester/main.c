#include "tester.h"

#include <unistd.h>
#include "libft.h"

int	main(int argc, char *argv[])
{
	char	*line;
	int		num;

	num = 0;
	while (num < argc)
	{
		ft_putstr_fd("arg: ", 1);
		ft_putendl_fd(argv[num], 1);
		num++;
	}
	line = NULL;
	while (set_rtn_int(&num, get_next_line(STDIN_FILENO, &line)))
	{
		if (num == -1 || line == NULL)
			return (1);
		ft_putstr_fd("stdin: ", 1);
		ft_putendl_fd(line, 1);
		free_set((void **)&line, NULL);
	}
	free_set((void **)&line, NULL);
}
