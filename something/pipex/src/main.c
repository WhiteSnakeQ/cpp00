#include "../pipex.h"

// ./pipex input_file.txt "cat /dev/urandom" "head -n 5" output_file.txt
// ./pipex input_file.txt "cat" "head -n 5" output_file.txt

pid_t	child_process(int process_number, t_pipex *structure,
		char **envp, int *pipe_fd)
{
	pid_t	process_id;

	process_id = fork();
	if (process_id == -1)
		return (0);
	if (process_id == 0)
	{
		dup2(structure -> input_fd, STDIN_FILENO);
		dup2(pipe_fd[1], STDOUT_FILENO);
		close(pipe_fd[0]);
		close(pipe_fd[1]);
		execve((structure->cmd_paths)[process_number],
			(structure->command_args)[process_number], envp);
	}
	else
	{
		return (process_id);
	}
	return (0);
}

pid_t	second_child_process(int process_number, t_pipex *structure,
		char **envp, int *pipe_fd)
{
	pid_t	process_id;

	process_id = fork();
	if (process_id == -1)
		return (0);
	if (process_id == 0)
	{
		dup2(pipe_fd[0], STDIN_FILENO);
		dup2(structure -> output_fd, STDOUT_FILENO);
		close(pipe_fd[1]);
		close(pipe_fd[0]);
		execve((structure->cmd_paths)[process_number],
			(structure->command_args)[process_number], envp);
	}
	else
	{
		return (process_id);
	}
	return (0);
}

void	pipex(t_pipex *structure)
{
	int	process_number;
	int	fd[2];
	int	child_process_id;
	int	second_child_process_id;

	process_number = 0;
	if (pipe(fd) == -1)
		return ;
	child_process_id = child_process(process_number, structure,
			structure->envp_st, fd);
	process_number++;
	second_child_process_id = second_child_process(process_number, structure,
			structure->envp_st, fd);
	close(fd[0]);
	close(fd[1]);
	waitpid(child_process_id, NULL, 0);
	waitpid(second_child_process_id, NULL, 0);
}

int	main(int argc, char **argv, char **envp)
{
	t_pipex	*structure;

	if (argc <= 4)
		return (0);										//выход при отстутствии параметров
	structure = initialize_struct();
	if (!(check_arguments(argc, argv, envp, structure)))
		return (free(structure), 0);				//  Это все тоже чистить надо!
	if (!(parse_arguments(structure)))
		return (free(structure), 0);			//  Это все тоже чистить надо!			
	if (!(parse_commands(structure)))
		return (free(structure), 0);			//чистим структуру при выходе, ток чистить нужно все(внутриности++)
	// structure_status(structure);
	pipex(structure);
	clean_the_struct(structure);
	return (0);
}
