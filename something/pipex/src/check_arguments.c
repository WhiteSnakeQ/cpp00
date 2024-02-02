#include "../pipex.h"

char	*create_file_path(char *file_name)
{
	return (ft_strjoin("", file_name));
}

int	check_arguments(int argc, char **argv, char **envp, t_pipex *structure)
{
	int	fd_input;
	int	fd_output;

	fd_output = 0;
	fd_input = open(argv[1], O_RDONLY, 0644);
	if (fd_input == (-1) || argc > 5)
		return (0);
	fd_output = open(argv[argc - 1],
			O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd_output == (-1))
		return (close(fd_input), 0);					///////close if return
	structure -> input_fd = fd_input;
	structure -> output_fd = fd_output;
	structure -> argc_st = argc;
	structure -> argv_st = argv;
	structure -> envp_st = envp;
	return (1);
}
