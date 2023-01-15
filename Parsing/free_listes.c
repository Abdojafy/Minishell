/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_listes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajafy <ajafy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 02:21:18 by ajafy             #+#    #+#             */
/*   Updated: 2023/01/15 14:41:09 by ajafy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../minishell.h"

void	free_lst_temp(t_temp *head_temp)
{
	t_temp	*tmp;
	t_red	*red;

	tmp = NULL;
	if (head_temp)
	{
		while (head_temp)
		{
			tmp = head_temp;
			head_temp = head_temp->next;
			red = NULL;
			if (tmp->content)
				free(tmp->content);
			free(tmp);
			tmp = NULL;
		}
	}
}

void	free_lst(t_list *lst)
{
	t_list	*tmp;
	t_red	*red;

	tmp = NULL;
	while (lst)
	{
		tmp = lst;
		lst = lst->next;
		red = NULL;
		while (tmp->red)
		{
			red = tmp->red;
			tmp->red = tmp->red->next;
			if (red->file_name)
				free(red->file_name);
			free(red);
		}
		if (tmp->cmd)
			free(tmp->cmd);
		free(tmp);
		tmp = NULL;
	}
}