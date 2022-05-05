/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_cmd_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleoma <pleoma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 13:43:02 by pleoma            #+#    #+#             */
/*   Updated: 2022/05/05 15:37:56 by pleoma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

bool is_pipe(t_list	*tmp)
{
	if (ft_strncmp("|", tmp->content, 1))
		return (false);
	return (true);
}

bool is_redir(t_list	*tmp)
{
	if (ft_strncmp(">", tmp->content, 1) ||
			ft_strncmp("<", tmp->content, 1))
		return (false);
	return (true);
}

/*	enumirates t_cmd */

void	enum_cmd(void)
{
	int 	coun;
	t_cmd	*temp_cmd;

	coun =  0;
	temp_cmd = g_shell.cmd;
	while(temp_cmd)
	{
		// Можно переделать в инт
		temp_cmd->i = ft_itoa(coun);
		coun++;
		temp_cmd = temp_cmd->next;
	}
}
