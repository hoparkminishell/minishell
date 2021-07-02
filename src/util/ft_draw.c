/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjpark <hjpark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 21:15:45 by hjpark            #+#    #+#             */
/*   Updated: 2021/07/03 05:15:27 by hjpark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

static void	draw1_2(void)
{
	ft_putstr_fd("                             \'_%\"{oo2o2oo2o2o2}\"\\_)                \
		            \n", STDERR, "\033[33m");
	ft_putstr_fd("                            _oX22os__s_%__s__anoo2o,4                  \
		        \n", STDERR, "\033[33m");
	ft_putstr_fd("                           .Sor{ooomm22 mX2 mooor{o2,4                 \
		        \n", STDERR, "\033[33m");
	ft_putstr_fd("                           )no()n          W  po()no(]                 \
		        \n", STDERR, "\033[33m");
	ft_putstr_fd("                          [{oo()vm        W   mo()non.                 \
		        \n", STDERR, "\033[33m");
	ft_putstr_fd("                           )no()v$            Do(=no(]                 \
		        \n", STDERR, "\033[33m");
	ft_putstr_fd("                           ,{o()voW          @no(=2}_                  \
		        \n", STDERR, "\033[33m");
	ft_putstr_fd("                            aa/)noodVU$  @VUnnoo(_aa                   \
		        \n", STDERR, "\033[33m");
	ft_putstr_fd("                              [)vo2oo_ aa _2oo2o(]                     \
		        \n", STDERR, "\033[33m");
	ft_putstr_fd("                       \
	      f)no2ooe. ,{Xo2o2(]", 1, "\033[33m");
	ft_putstr_fd("        @hopark @suhong        \n", 1, "\033[36m");
	ft_putstr_fd("                              g {Soo2'j  b-2oo2e'j                   \
		          \n", 1, "\033[33m");
	ft_putstr_fd("                                aaggaj    baggaa            \
		 \n", 1, "\033[33m");
}

void	draw(void)
{
	ft_putstr_fd("                          f)}\"\\__Xoo2o2o2o2on_sr\"{;]         \
		                 \n", STDERR, "\033[33m");
	ft_putstr_fd("                            _<S2XX2oo2o2o2o2o2Snoos,            \
		               \n", STDERR, "\033[33m");
	ft_putstr_fd("                          _xooooooo2o2o2o2o2o2ooooons,           \
		            \n", STDERR, "\033[33m");
	ft_putstr_fd("                        'Jno2r\"\"\"\"\"\"2o2o2o2o\"\"\"\"\"\"{2oos\"\
		                        \n", STDERR, "\033[33m");
	ft_putstr_fd("                        ooo2o222S22So2o2o2o22222S2So2ooo             \
		         \n", STDERR, "\033[33m");
	ft_putstr_fd("                        o2o2oo2o( )oo2o2oo2oo( )noooo2oo             \
		          \n", STDERR, "\033[33m");
	ft_putstr_fd("                        2o2o2o2o222or\"\"\"\"\"\"{So2ooo2o2o2o       \
		                \n", STDERR, "\033[33m");
	ft_putstr_fd("                        {oo2o2o2oor_j  aa  b/1o2o2o2o2or]             \
		         \n", STDERR, "\033[33m");
	ft_putstr_fd("                         {o2o2o2o2o,????????_2o2oo2o2or_              \
		         \n", STDERR, "\033[33m");
	ft_putstr_fd("                          \"oo2oo2o2S222oo2o222o2o2o2o^a              \
		          \n", STDERR, "\033[33m");
	ft_putstr_fd("                            \"{2o2o2oooo22o2oo2o2o2r\"a                \
		          \n", STDERR, "\033[33m");
	draw1_2();
}

static void	draw_2(void)
{
	ft_putstr_fd("                             \'_%\"{oo2o2oo2o2o2}\"\\_)                \
		            \n", STDERR, "\033[33m");
	ft_putstr_fd("                            _oX22os__s_%__s__anoo2o,4                  \
		        \n", STDERR, "\033[33m");
	ft_putstr_fd("                           .Sor{ooomm22 mX2 mooor{o2,4                 \
		        \n", STDERR, "\033[33m");
	ft_putstr_fd("                           )no()n          W  po()no(]                 \
		        \n", STDERR, "\033[33m");
	ft_putstr_fd("                          [{oo()vm        W   mo()non.                 \
		        \n", STDERR, "\033[33m");
	ft_putstr_fd("                           )no()v$            Do(=no(]                 \
		        \n", STDERR, "\033[33m");
	ft_putstr_fd("                           ,{o()voW          @no(=2}_                  \
		        \n", STDERR, "\033[33m");
	ft_putstr_fd("                            aa/)noodVU$  @VUnnoo(_aa                   \
		        \n", STDERR, "\033[33m");
	ft_putstr_fd("                              [)vo2oo_ aa _2oo2o(]                     \
		        \n", STDERR, "\033[33m");
	ft_putstr_fd("                              f)no2ooe.\
		,{Xo2o2(]", STDERR, "\033[33m");
	ft_putstr_fd("        @hopark @suhong        \n", STDERR, "\033[36m");
	ft_putstr_fd("                              g {Soo2'j  b-2oo2e'j                   \
		          \n", STDERR, "\033[33m");
	ft_putstr_fd("                                aaggaj    baggaa            \
		 \n", STDERR, "\033[33m");
}

void	draw2(void)
{
	char	*pwd;

	pwd = getcwd(0, BUFFER_SIZE);
	ft_putstr_fd(pwd, STDERR, "\x1b[32m");
	free(pwd);
	ft_putstr_fd("$ ", STDERR, "\x1b[32m");
}

void	test_print_passing(t_built *built)
{
	t_list	*temp_l;

	temp_l = built->command;
	write(2, "          passing print : ", 26);
	while (temp_l)
	{
		write(2, "[", 1);
		ft_putstr_fd(temp_l->str, 2, 0);
		write(2, "]", 1);
		temp_l = temp_l->next;
	}
	write(2, "\n", 1);
}
