#include "../pipex.h"

char	**find_paths(t_pipex *structure)
{
	char	*path_element;
	char	**splitted_paths;

	path_element = (structure -> envp_st)[4] + 5;
	splitted_paths = ft_split(path_element, ':');
	if (!splitted_paths)
		return (NULL);
	return (splitted_paths);
}

char	*does_it_exist(char **splitted_paths, char *it)
{
	int		iter;
	char	*path;
	char	*str_join;

	iter = 0;
	while (splitted_paths[iter])
	{
		str_join = ft_strjoin(splitted_paths[iter], "/\0");			//  Это все тоже чистить надо!
		path = ft_strjoin(str_join, it);			//  Это все тоже чистить надо!
		if (access(path, R_OK) != -1)
		{
			free(str_join);		//  Это все тоже чистить надо!
			return (path);
		}
		free(path);		//  Это все тоже чистить надо!
		free(str_join);		//  Это все тоже чистить надо!
		iter++;
	}
	return (NULL);
}

void free_directories(char **directories)
{
	int i;

	i = 0;
	while(directories[i])
	{
		free(directories[i]);
		i++;
	}
	free(directories);
}

int	parse_commands(t_pipex *structure)
{
	int		i;
	char	*path;
	char	**command_paths;
	char	**directories;

	i = 0;
	command_paths = malloc(sizeof(char *) * (structure -> argc_st - 1));
	printf("(parse_commands) allocated memory: %p\n", command_paths);
	directories = find_paths(structure);
	if (!command_paths || !directories)
		return (0);
	while ((structure -> command_args)[i])
	{
		path = does_it_exist(directories, (structure -> command_args)[i][0]);
		// if (path)
		// {
			command_paths[i] = path;
			i++;
		// }
		// else
		// 	return (0);			//это я для себя убрал
	}
	int d = 0;
	while (directories[d])
		free(directories[d++]);		//  Это все тоже чистить надо!
	free(directories);			//clean
	command_paths[i] = 0;
	structure -> cmd_paths = command_paths;
	structure -> command_count = i;
	return (1);
}
