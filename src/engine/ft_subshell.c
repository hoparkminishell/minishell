
#include "head.h"

static void	close_pip(int pip_in, int pip_out)
{
	if (pip_in >= 0)
		close(pip_in);
	if (pip_out >= 0)
		close(pip_out);
}

int ft_start(t_built *built, t_list *env_list)
{
	int	fd[2];
	int mini[2];
	int	status;

	mini[0] = STDOUT;
	mini[1] = STDIN;
	status = 1;
	while (built)
	{
		if (built->next && built->next->command->str[0] == '|')
		{
			if (pipe(fd) < 0)
			{
				perror("pipeerror");
				return (ERROR);
			}
			while (built)
			{
				mini[0] = mini[1];
				// dup2(mini[0], fd[1]);
				if (!built->next || (built->next && built->next->command->str[0] != '|'))
					break ;
				status = ft_subshell(built, env_list, fd, mini);
				built = built->next;
			}
			dup2(STDOUT, STDOUT);
			ft_execute(built, env_list);
			built = built->next;
			close_pip(mini[0], mini[1]);

		}
		else
		{
			status = ft_execute(built, env_list);
			built = built->next;
		}
	}

	return (status);
}

static void	do_piping(int pip_in, int pip_out)
{
	if (pip_in != -1)
	{
		if (dup2(pip_in, STDIN) < 0)
			perror("pipe_in:error");
		// ft_close(pip_in);
	}
	if (pip_out != -1)
	{
		// printf("pipout[%d]\n", pip_out);
		if (dup2(pip_out, STDOUT) < 0)
			perror("pipe_out:error");
		// ft_close(pip_out);
	}
}

int	ft_subshell(t_built *built, t_list *env_list, int *fd, int *mini)
{
	int	status;
	int	w_status;
	pid_t	pid;
	pid_t	w_pid;

	pid = fork();

	if (pid < 0)
	{
		perror("forkerror");
		return (ERROR);
	}
	if (pid == 0) //자식
	{
		dup2(mini[0], STDIN);
		status = ft_execute(built, env_list);
		exit(status);
	}
	else // 부모
	{
		dup2(fd[1], STDOUT);
		w_pid = waitpid(pid, &w_status, WUNTRACED);
		while (!WIFEXITED(w_status) && !WIFSIGNALED(status))
			w_pid = waitpid(pid, &w_status, WUNTRACED);
	}
	return (w_status);
}