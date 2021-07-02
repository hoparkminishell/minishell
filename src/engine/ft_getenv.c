/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjpark <hjpark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 17:24:08 by hopark            #+#    #+#             */
/*   Updated: 2021/07/02 21:10:52 by hjpark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

char	*ft_getenv(t_list *list, const char *varname, int varlen)
{
	t_list	*env;
	char	*res;

	res = 0;
	env = list;
	if (ft_strncmp("?", (char *)varname, varlen))
		return (ft_itoa(g_mini.status));
	while (env)
	{
		if (ft_strncmp(env->id, (char *)varname, varlen))
		{
			res = ft_strndup(env->str, ft_strlen(env->str));
			break ;
		}
		env = env->next;
	}
	return (res);
}
