#ifndef SUHONG_H
# define SUHONG_H

# include "head.h"
# include <string.h>

# define REDIRECTION_ERROR 258

int	ft_execve(t_built *built, t_list *env_list);
int	check_file_exist(char *name);
void	ft_del_blank3(t_built *built);
int	ft_subshell(t_built *built, t_list *env_list, int **fd, int order);

int	ft_shell(t_built *built, t_list *env_list);

int	**free_pipe(int ***pipe, int size);
int	count_pipe(t_built *built);
int	**init_pipe(int size);
int	get_pipe_size(int **pipe);

void	ft_perror(char *filename, char *message);
void	ft_error(char *Str);

char	*ft_itoa(int n);

int	ft_subshell2(t_built *built, t_list *env_list, int *fd, int *mini);

#endif
