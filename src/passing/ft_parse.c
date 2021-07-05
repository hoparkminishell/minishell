/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhong <suhong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/04 23:00:11 by hjpark            #+#    #+#             */
/*   Updated: 2021/07/05 22:07:58 by suhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "passing.h"

void	ft_put_blank(t_built *built)
{
	t_list	*temp_l;
	t_list	*head;
	t_list	*new;
	char	*str;

	if (!built || !built->command)
		return ;
	temp_l = built->command;
	head = temp_l;
	while (temp_l)
	{
		if (!ft_strncmp(temp_l->str, " ", 1) && temp_l->next && \
			!ft_strncmp(temp_l->next->str, " ", 1))
		{
			str = ft_strndup(" ", 1);
			new = ft_listnew(str, 0);
			ft_listadd_back(&temp_l, &new);
		}
		temp_l = temp_l->next;
	}
}
