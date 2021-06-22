/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execute.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjpark <hjpark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 15:16:07 by suhong            #+#    #+#             */
/*   Updated: 2021/06/22 17:11:04 by hjpark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

int	ft_execute(t_built *built, t_list *env_list)
{
	t_built	*temp;
	int		fd[2];
	int		tempout;
	int		tempin;

	tempout = dup(STDOUT);
	tempin = dup(STDIN);
	fd[0] = STDIN;
	fd[1] = STDOUT;
	temp = ft_builtndup(built->command);
	ft_split_built(temp, "><");
	ft_execute2(temp, env_list, fd);
	ft_close(fd[0]);
	ft_close(fd[1]);
	dup2(tempout, 1);
	dup2(tempin, 0);
	write(1, "END\n", 4);
	return (1);
}

int	ft_execute2(t_built *built, t_list *env_list, int *fd)
{
	write(1,"A",1);
	if (!built)
		return (0);
	test_print_passing(built);
	printf("{%s}\n", built->command->str);
	if (built->next)
		ft_execute2(built->next, env_list, fd);
	if (ft_strncmp(built->command->str, ">", 1))
		ft_redirect(built, "TRUNC", fd);
	else if (ft_strncmp(built->command->str, ">>", 2))
		ft_redirect(built, "APPEND", fd);
	else if (ft_strncmp(built->command->str, "<", 1))
		ft_redirect2(built, "INPUT", fd);
	else if (ft_strncmp(built->command->str, "<<", 2))
		ft_redirect2(built, "INPUT", fd);
	else
		ft_builtin(built, env_list);
	write(1,"B",1);
	return (SUCCESS);
}

void	ft_close(int fd)
{
	if (fd > 0)
		close(fd);
}

int	ft_redirect(t_built *built, char *type, int *fd)
{
	t_list	*list;

	fd[0] = fd[1];
	list = built->command;
	if (!list->next || !list->next->next)
		return (ERROR);
	list = list->next->next;
	if (ft_strncmp(type, "TRUNC", 5))
		fd[1] = open(list->str, O_CREAT | O_WRONLY | O_TRUNC, S_IRWXU);
	else if (ft_strncmp(type, "APPEND", 6))
		fd[1] = open(list->str, O_CREAT | O_WRONLY | O_APPEND, S_IRWXU);
	dup2(fd[1], fd[0]);
	ft_close(fd[1]);
	return (SUCCESS);
}

int	ft_redirect2(t_built *built, char *type, int *fd)
{
	t_list	*list;

	fd[1] = fd[0];
	list = built->command;
	if (!list->next || !list->next->next)
		return (ERROR);
	list = list->next->next;
	if (ft_strncmp(type, "INPUT", 5))
		fd[0] = open(list->str, O_RDONLY, S_IRWXU);
	else if (ft_strncmp(type, "INPUT", 6))
		fd[0] = open(list->str, O_RDONLY, S_IRWXU);
	dup2(fd[0], fd[1]);
	// ft_close(fd[0]);
	return (SUCCESS);
}
