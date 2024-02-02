#include "../pipex.h"

int	parse_arguments(t_pipex *structure)
{	
	int		counter;
	int		array_counter;
	char	***commands;

	counter = 2;
	array_counter = 0;
	commands = malloc(sizeof(char **) * ((structure -> argc_st) - 2));
	printf("(parse_arguments) allocated memory: %p\n", commands);
	if (!commands)
		return (0);
	while (counter < (structure -> argc_st - 1))
	{
		commands[array_counter] = ft_split((structure -> argv_st)
			[counter], ' ');
		if (!(commands[array_counter]))
			return (0);
		counter++;
		array_counter++;
	}
	commands[array_counter] = 0;
	structure -> command_args = commands;
	return (1);
}
