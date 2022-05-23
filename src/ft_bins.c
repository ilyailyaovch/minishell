/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bins.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spzona <spzona@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 12:53:57 by pleoma            #+#    #+#             */
/*   Updated: 2022/05/23 13:00:30 by spzona           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

/*	handles exit command without any args */

void	ft_exit(t_cmd *cmd)
{
	if (!ft_strncmp(cmd->args[0], "exit", ft_strlen(cmd->args[0])))
		ft_shell_error("exit\n", 0, 0);
	if (cmd->args[1])
		ft_shell_error("minishell: exit: too many arguments\n", 1, 0);
	exit(1);
}

void	ft_echo(t_cmd *cmd)
{
	int	i;

	i = 1;
	g_shell.status = 0;
	if (!cmd->args[1])
	{
		printf("\n");
		return ;
	}
	while (cmd->args[i] && !ft_strncmp(cmd->args[i], "-n",
			ft_strlen(cmd->args[i])))
		i++;
	while (cmd->args[i])
	{
		printf("%s", cmd->args[i]);
		if (cmd->args[i + 1])
			printf(" ");
		i++;
	}
	if (ft_strncmp(cmd->args[1], "-n", ft_strlen(cmd->args[1])))
		printf("\n");
}

void	ft_pwd(void)
{
	char	cwd[4096];

	getcwd(cwd, 4097);
	printf("%s\n", cwd);
	g_shell.status = 0;
}

void	ft_env(void)
{
	int	i;

	i = 0;
	while (g_shell.envp[i])
	{
		if (!ft_strchr(g_shell.envp[i], '='))
			i++;
		else
		{
			printf("%s\n", g_shell.envp[i]);
			i++;
		}
	}
	g_shell.status = 0;
}
