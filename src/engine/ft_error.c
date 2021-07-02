#include "head.h"

void	ft_perror(char *filename, char *message)
{
	char	*error_str;

	error_str = strerror(errno);
	ft_putstr_fd("minish : ", STDERR, 0);
	if (filename)
	{
		ft_putstr_fd(filename, STDERR, 0);
		ft_putstr_fd(": ", STDERR, 0);
	}
	if (message)
	{
		ft_putstr_fd(message, STDERR, 0);
		ft_putstr_fd("\n", STDERR, 0);
	}
	else
	{
		ft_putstr_fd(strerror(errno), STDERR, 0);
		ft_putstr_fd("\n", STDERR, 0);
	}
}

void	ft_syntaxerror(char type)
{
	char	*message;

	ft_putstr_fd("minish :  syntax error near unexpected token \'", STDERR, 0);
	if (type)
	{
		if (ft_strchr("><", type))
		{
			message = ft_strndup("newline", 7);
		}
		else
			message = ft_strndup(&type, 1);
		ft_putstr_fd(message, STDERR, 0);
		ft_free(message);
	}
	ft_putstr_fd("'\n", STDERR, 0);
}

void	ft_error(char *str)
{
	ft_perror(0, str);
	exit(EXIT_FAILURE);
}
