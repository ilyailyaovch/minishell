/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_cmd_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spzona <spzona@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 13:43:02 by pleoma            #+#    #+#             */
/*   Updated: 2022/05/05 18:49:00 by spzona           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	fill_ridirect(char *redir, char *file)
{
	if (!ft_strncmp(">>", redir, 2))
		ft_dictadd_back(&ft_cmd_last(g_shell.cmd)->outfd, ft_dictinit(">>", file));
	else if (!ft_strncmp("<<", redir, 2))
		ft_dictadd_back(&ft_cmd_last(g_shell.cmd)->infd, ft_dictinit("<<", file));
	else if (!ft_strncmp(">", redir, 1))
		ft_dictadd_back(&ft_cmd_last(g_shell.cmd)->outfd, ft_dictinit(">", file));
	else if (!ft_strncmp("<", redir, 1))
		ft_dictadd_back(&ft_cmd_last(g_shell.cmd)->infd, ft_dictinit("<", file));
}

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
