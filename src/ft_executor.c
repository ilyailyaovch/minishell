/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_executor.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleoma <pleoma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 09:24:39 by pleoma            #+#    #+#             */
/*   Updated: 2022/05/06 18:41:46 by pleoma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

/* Makes pipes and executes cmds */

void	ft_executor(t_cmd *cmd)
{
	t_child child;

	ft_init_child(&child, cmd);
	ft_init_heredoc_instd(cmd);
	
	// while()
	// {
	// 	check cd();
	// 	pipe()
	// 	fork()
	// 	signals();
	// 	work_woth_child()
	// 	close();
	// 	get_variables();
	// }
	// close();
	// waitpid();

	printf("executor doesn't work\n");
}