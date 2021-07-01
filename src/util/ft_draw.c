#include "head.h"

void	draw(void)
{
	ft_putstr_fd("                          f)}\"\\__Xoo2o2o2o2on_sr\"{;]                           \n", 1, "\033[33m");
	ft_putstr_fd("                            _<S2XX2oo2o2o2o2o2Snoos,                            \n", 1, "\033[33m");
	ft_putstr_fd("                          _xooooooo2o2o2o2o2o2ooooons,                        \n", 1, "\033[33m");
	ft_putstr_fd("                        'Jno2r\"\"\"\"\"\"2o2o2o2o\"\"\"\"\"\"{2oos\"                        \n", 1, "\033[33m");
	ft_putstr_fd("                        ooo2o222S22So2o2o2o22222S2So2ooo                       \n", 1, "\033[33m");
	ft_putstr_fd("                        o2o2oo2o( )oo2o2oo2oo( )noooo2oo                        \n", 1, "\033[33m");
	ft_putstr_fd("                        2o2o2o2o222or\"\"\"\"\"\"{So2ooo2o2o2o                        \n", 1, "\033[33m");
	ft_putstr_fd("                        {oo2o2o2oor_j  aa  b/1o2o2o2o2or]                       \n", 1, "\033[33m");
	ft_putstr_fd("                         {o2o2o2o2o,????????_2o2oo2o2or_                        \n", 1, "\033[33m");
	ft_putstr_fd("                          \"oo2oo2o2S222oo2o222o2o2o2o^a                         \n", 1, "\033[33m");
	ft_putstr_fd("                            \"{2o2o2oooo22o2oo2o2o2r\"a                           \n", 1, "\033[33m");
	ft_putstr_fd("                             \'_%\"{oo2o2oo2o2o2}\"\\_)                             \n", 1, "\033[33m");
	ft_putstr_fd("                            _oX22os__s_%__s__anoo2o,4                           \n", 1, "\033[33m");
	ft_putstr_fd("                           .Sor{ooomm22 mX2 mooor{o2,4                          \n", 1, "\033[33m");
	ft_putstr_fd("                           )no()n          W  po()no(]                          \n", 1, "\033[33m");
	ft_putstr_fd("                          [{oo()vm        W   mo()non.                          \n", 1, "\033[33m");
	ft_putstr_fd("                           )no()v$            Do(=no(]                          \n", 1, "\033[33m");
	ft_putstr_fd("                           ,{o()voW          @no(=2}_                           \n", 1, "\033[33m");
	ft_putstr_fd("                            aa/)noodVU$  @VUnnoo(_aa                            \n", 1, "\033[33m");
	ft_putstr_fd("                              [)vo2oo_ aa _2oo2o(]                              \n", 1, "\033[33m");
	ft_putstr_fd("                              f)no2ooe.  ,{Xo2o2(]", 1, "\033[33m");
	ft_putstr_fd("        @hopark @suhong        \n", 1, "\033[36m");
	ft_putstr_fd("                              g {Soo2'j  b-2oo2e'j                              \n", 1, "\033[33m");
	ft_putstr_fd("                                aaggaj    baggaa              \n", 1, "\033[33m");
}

void	draw2(void)
{
	char	*pwd;

	pwd = getcwd(0, BUFFER_SIZE);
	// ft_putstr_fd(pwd, 1, "\x1b[32m");
	ft_putstr_fd(pwd, STDERR, "\x1b[32m");
	free(pwd);
	// ft_putstr_fd("$ ", 1, "\x1b[32m");
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

void	print_built_list(t_built *built)
{
	t_built	*tmp;

	tmp = built;
	while (tmp)
	{
		test_print_passing(tmp);
		write(2,"\n",1);
		tmp = tmp->next;
	}
}
