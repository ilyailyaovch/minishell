/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bins.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleoma <pleoma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 12:53:57 by pleoma            #+#    #+#             */
/*   Updated: 2022/05/15 15:39:14 by pleoma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

/*	handles exit command without any args */

void	ft_exit(t_cmd *cmd)
{
	if (!ft_strncmp(cmd->args[0] , "exit", ft_strlen(cmd->args[0])))
		ft_shell_error("exit\n", 0, 0);
	if (cmd->args[1])
		ft_shell_error("minishell: exit: too many arguments\n", 1, 0);
	exit(1);
}
