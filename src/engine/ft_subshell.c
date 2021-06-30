#include "head.h"

static void	close_pip_parent(int **fd, int order)
{
	int	i;
	int	size;

	i = 0;
	size = get_pipe_size(fd);
	while (i <= order && i < size)
	{
		ft_close(fd[i][1]);
		i++;
	}
	i = 0;
	while (i < order && i < size)
	{
		ft_close(fd[i][0]);
		i++;
	}
}

static void	close_pip_child(int **fd, int in_index, int out_index)
{
	int	i;
	int	size;

	i = 0;
	size = get_pipe_size(fd);
	while (i < size)
	{
		if (i == in_index)
			ft_close(fd[i][1]);	
		else if (i == out_index)
			ft_close(fd[i][0]);
		else
		{
			ft_close(fd[i][0]);
			ft_close(fd[i][1]);
		}
		i++;
	}
}

static void	do_piping(int pip_in, int pip_out)
{
	if (pip_in != -1)
	{
		if (dup2(pip_in, STDIN) < 0)
			ft_error("pipe_in: dup2 error");
		if (pip_in > 0)
			close(pip_in);
	}
	if (pip_out != -1)
	{
		if (dup2(pip_out, STDOUT) < 0)
			ft_error("pipe_in: dup2 error");
		if (pip_out == 0 || pip_out > 1)
			close(pip_out);
	}
}

static void	do_pipe_by_order(int order, int **fd)
{
	int	size;

	size = get_pipe_size(fd);
	if (order == 0)
		do_piping(-1, fd[order][1]);
	else if (order == size)
		do_piping(fd[order - 1][0], -1);
	else
		do_piping(fd[order - 1][0], fd[order][1]);
}

int	ft_subshell(t_built *built, t_list *env_list, int **fd, int order)
{
	int	w_status;
	pid_t	pid;
	pid_t	w_pid;

	pid = fork();
	if (pid < 0)
		ft_error("Fork error");
	if (pid == 0) //자식
	{
		g_mini.pip[0] = dup(STDIN);//init global pipe for redirection
		g_mini.pip[1] = dup(STDOUT);
		do_pipe_by_order(order, fd);
		close_pip_child(fd, order - 1, order);
		exit(ft_execute(built, env_list));
	}
	else 
	{
		close_pip_parent(fd, order);
		w_pid = waitpid(pid, &w_status, WUNTRACED);
		while (!WIFEXITED(w_status) && !WIFSIGNALED(w_status))
			w_pid = waitpid(pid, &w_status, WUNTRACED);
	}
	return (WEXITSTATUS(w_status));
}
