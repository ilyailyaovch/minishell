/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_cmd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleoma <pleoma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 17:23:26 by spzona            #+#    #+#             */
/*   Updated: 2022/05/23 14:25:44 by pleoma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

/* counting cmds while avoiding pipes */

void	count_cmd(t_list *list)
{
	t_cmd	*tmp_cmd;
	t_list	*tmp;

	tmp = list;
	while (tmp && (is_pipe(tmp) == false))
	{
		if (is_redir(tmp) == true)
			tmp = tmp->next;
		else
			ft_cmd_last(g_shell.cmd)->count++;
		tmp = tmp->next;
	}
	tmp_cmd = ft_cmd_last(g_shell.cmd);
	tmp_cmd->args = ft_calloc(tmp_cmd->count, sizeof(char *));
	if (!tmp_cmd->args)
		ft_error("count_cmd", ENOMEM);
}

/*	func fills t_cmd with needed commands and 
	makes dict from special symbols	*/

void	ft_get_cmd(void)
{
	t_list	*tmp_list;
	t_cmd	*cmd;

	cmd = g_shell.cmd;
	tmp_list = g_shell.list;
	while (tmp_list)
	{
		if (is_pipe(tmp_list) == false)
		{
			ft_cmdadd_back(&g_shell.cmd, ft_cmdinit());
			count_cmd(tmp_list);
		}
		while (tmp_list && (is_pipe(tmp_list) == false))
		{
			if (is_redir(tmp_list) == true)
			{
				fill_redirect(tmp_list->content, tmp_list->next->content);
				tmp_list = tmp_list->next;
			}
			else
				fill_argument(tmp_list->content);
			tmp_list = tmp_list->next;
		}
		if (tmp_list)
			tmp_list = tmp_list->next;
	}
	enum_cmd();
}
