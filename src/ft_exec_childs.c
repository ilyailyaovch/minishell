/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec_childs.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleoma <pleoma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 15:24:43 by pleoma            #+#    #+#             */
/*   Updated: 2022/05/06 15:47:46 by pleoma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void ft_init_child(t_child *child, t_cmd *cmd)
{
	child->i = -1;
	child->len = ft_cmdlen(cmd);
	child->current = 0;
	child->pipe[0][0] = -1;
	child->pipe[0][1] = -1;
	child->pipe[1][0] = -1;
	child->pipe[1][1] = -1;
}