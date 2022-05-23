/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleoma <pleoma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 14:11:41 by pleoma            #+#    #+#             */
/*   Updated: 2022/05/23 14:25:38 by pleoma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

/*	frees all at the end */

void	ft_free_all(void)
{
	free(g_shell.line);
	ft_free_cmd(g_shell.cmd);
	ft_free_list(g_shell.list);
}

/*	frees array */

void	ft_free_mass(char **arr)
{
	int	coun;

	coun = 0;
	while (arr[coun])
	{
		free(arr[coun]);
		coun++;
	}
	free(arr);
}

/*	frees list */

void	ft_free_list(t_list *a)
{
	t_list	*tmp;

	tmp = a;
	while (a)
	{
		tmp = a->next;
		free(a->content);
		free(a);
		a = tmp;
	}
}
