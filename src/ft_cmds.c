/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cmds.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spzona <spzona@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 16:18:03 by pleoma            #+#    #+#             */
/*   Updated: 2022/05/23 13:46:43 by spzona           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

t_cmd	*ft_cmdinit(void)
{
	t_cmd	*res;

	res = malloc(sizeof(*res));
	if (!res)
		ft_error("ft_cmdinit(): ", ENOMEM);
	res->next = NULL;
	res->count = 0;
	res->args = NULL;
	res->outfd = NULL;
	res->tmpfile = 0;
	res->infd = NULL;
	return (res);
}

int	ft_cmdlen(t_cmd *cmd)
{
	int	i;

	i = 0;
	while (cmd)
	{
		i++;
		cmd = cmd->next;
	}
	return (i);
}

t_cmd	*ft_cmd_last(t_cmd *lst)
{
	t_cmd	*tmp;

	if (!lst)
		return (0);
	tmp = lst;
	while (tmp->next)
		tmp = tmp->next;
	return (tmp);
}

void	ft_cmdadd_back(t_cmd **lst, t_cmd *new)
{
	if (!*lst)
		(*lst) = new;
	else
		ft_cmd_last(*lst)->next = new;
}

void	ft_free_cmd(t_cmd *cmd)
{
	t_cmd	*tmp;

	tmp = cmd;
	while (tmp)
	{
		tmp = cmd->next;
		ft_free_mass(cmd->args);
		free(cmd->i);
		ft_free_dict(cmd->infd);
		ft_free_dict(cmd->outfd);
		free(cmd);
		cmd = tmp;
	}
}
