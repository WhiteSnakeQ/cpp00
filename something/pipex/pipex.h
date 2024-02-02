#ifndef PIPEX_H
# define PIPEX_H
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <stdio.h>
# include <sys/wait.h>
# include <fcntl.h>

typedef struct s_pipex
{
	int		argc_st;
	char	**argv_st;
	char	**envp_st;
	int		input_fd;
	int		output_fd;
	int		here_doc;
	int		is_invalid_infile;
	char	**cmd_paths;
	char	***command_args;
	int		command_count;
}	t_pipex;

t_pipex	*initialize_struct(void);
int		clean_the_struct(t_pipex *structure);
int		check_arguments(int argc, char **argv, char **envp, t_pipex *structure);
int		parse_commands(t_pipex *structure);
int		parse_arguments(t_pipex *structure);
char	**ft_split(char const *str, char c);
void	structure_status(t_pipex *structure);
size_t	ft_strlen(const char *str);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
char	*ft_strjoin(char const *s1, char const *s2);
#endif