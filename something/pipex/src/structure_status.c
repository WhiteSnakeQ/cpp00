#include "../pipex.h"

void structure_status(t_pipex *structure){
	printf("\n\n\nStructure status:\n");
	printf("argc_st = %d\n", structure -> argc_st);
	printf("argv_st = ");
	int counter = 0;
	int counter_2 = 0;
	while(counter < structure -> argc_st)
	{
		printf("%s ", (structure -> argv_st)[counter]);
		counter++;
	}
	counter = 0;
	printf("\n");
	printf("input_fd = %d\n", structure -> input_fd);
	printf("output_fd = %d\n", structure -> output_fd);
	printf("here_doc = %d\n", structure -> here_doc);
	printf("is_invalid_infile = %d\n", structure -> is_invalid_infile);
	printf("cmd_paths = ");
	if((structure -> cmd_paths))
	{
		while((structure -> cmd_paths)[counter])
		{
			printf("%s ", (structure -> cmd_paths)[counter]);
			counter++;
		}
	}
	counter = 0;
	printf("\n");
	// printf("\n");
	// printf("envp_st:\n");
	// if((structure -> envp_st))
	// {
	// 	while((structure -> envp_st)[counter])
	// 	{
	// 		printf("%s\n", (structure -> envp_st)[counter]);
	// 		counter++;
	// 	}
	// }
	// counter = 0;
	// printf("\n");
	// printf("\n");
	printf("command_args = ");
	if((structure -> command_args))
	{
		while((structure -> command_args)[counter])
		{
			printf(" [");
			while ((structure -> command_args)[counter][counter_2])
			{
				printf(" [%s] ", (structure -> command_args)[counter][counter_2]);
				counter_2++;
			}
			counter_2 = 0;
			counter++;
			printf("] ");
		}
	}
	printf("\n");
	counter = 0;
	printf("command_count = %d\n\n\n", structure -> command_count);
}