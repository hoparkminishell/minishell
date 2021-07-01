/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_line.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjpark <hjpark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 19:15:41 by hjpark            #+#    #+#             */
/*   Updated: 2021/07/01 22:10:24 by hjpark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

void	ft_getchar(int *cursor, int *len, int n)
{
	char c;

	tputs(tgetstr("im", NULL), 1, ft_putchar_tc);
	tputs(tgetstr("ic", NULL), 1, ft_putchar_tc);
	(*cursor)++;
	(*len)++;
	c = (char)n;
	ft_putchar_fd(c, STDERR, "\x1b[34m");
	g_mini.line = ft_add_char(g_mini.line, c, (*cursor));
	tputs(tgetstr("ip", NULL), 1, ft_putchar_tc);
	tputs(tgetstr("ei", NULL), 1, ft_putchar_tc);
}

static void	ft_init_get_line(int *cursor, int *len)
{
	if (!ft_malloc(&g_mini.line, sizeof(char)))
		return ;
	g_mini.line[0] = 0;
	(*cursor) = 0;
	(*len) = 0;
}

void	ft_get_line(void)
{
	int		n;
	int		k;
	int		i;
	int		c;

	ft_init_get_line(&g_mini.cursor, &g_mini.len);
	n = 0;
	while ((k = read(STDIN, &n, sizeof(int))) > 0)
	{
		if (n == LEFT_ARROW && g_mini.cursor > 0)
			ft_left_arrow(&g_mini.cursor, &g_mini.len);
		else if (n == RIGHT_ARROW && g_mini.cursor < g_mini.len)
			ft_right_arrow(&g_mini.cursor, &g_mini.len);
		else if (n == BACKSPACE && g_mini.cursor > 0)
			ft_backspace(&g_mini.cursor, &g_mini.len);
		else if (n == UP_ARROW)
			ft_up_arrow(&g_mini.cursor, &g_mini.len);
		else if (n == DOWN_ARROW)
			ft_down_arrow(&g_mini.cursor, &g_mini.len);
		else if (ft_isprint(n) || n == '\n')
		{
			i = 0;
			c = n;
			while (i < 4 && c)
			{
				c = n >> (8 * i);
				c = (char)c;
				if (ft_isprint(c))
					ft_getchar(&g_mini.cursor, &g_mini.len, c);
				else if (c == '\n' || c == 4)
				{
					ft_add_history();
					return ;
				}
				i++;
			}
		}
		n = 0;
	}
}
