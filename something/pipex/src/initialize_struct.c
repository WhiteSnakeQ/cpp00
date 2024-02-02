#include "../pipex.h"

t_pipex	*initialize_struct(void)
{
	t_pipex	*new_struct;

	new_struct = (t_pipex *)malloc(sizeof(t_pipex));
	printf("(initialize_struct) allocated memory: %p\n", new_struct);
	if (!new_struct)
		return (NULL);
	new_struct -> argc_st = 0;
	new_struct -> argv_st = NULL;
	new_struct -> envp_st = NULL;
	new_struct -> input_fd = 0;
	new_struct -> input_fd = 0;
	new_struct -> output_fd = 0;
	new_struct -> here_doc = 0;
	new_struct -> is_invalid_infile = 0;
	new_struct -> cmd_paths = NULL;
	new_struct -> command_args = NULL;
	new_struct -> command_count = 0;
	return (new_struct);
}
