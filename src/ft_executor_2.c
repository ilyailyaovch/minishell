/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_executor_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleoma <pleoma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 11:27:37 by pleoma            #+#    #+#             */
/*   Updated: 2022/05/16 10:32:45 by pleoma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	check_exit(t_cmd *cmd)
{
	if (!ft_strncmp(cmd->args[0], "exit", ft_strlen(cmd->args[0])))
		ft_exit(cmd);
}

void	collect_variables(void)
{
	int	i;

	i = 0;
	while (g_shell.envp[i])
	{
		write(g_shell.fd[0][1], g_shell.envp[i], ft_strlen(g_shell.envp[i]));
		write(g_shell.fd[0][1], "\n", 1);
		i++;
	}
	close (g_shell.fd[0][1]);
	write(g_shell.fd[1][1], &i, sizeof(int));
	close (g_shell.fd[1][1]);
	write(g_shell.fd[2][1], &g_shell.status, sizeof(int));
	close (g_shell.fd[2][1]);
}

void	get_variables(void)
{
	int	i;
	int	j;

	read(g_shell.fd[1][0], &i, sizeof(int));
	ft_free_mass(g_shell.envp);
	g_shell.envp = malloc(sizeof(char *) * (i + 1));
	j = 0;
	while (j < i)
	{
		g_shell.envp[j] = get_next_line(g_shell.fd[0][0]);
		g_shell.envp[j][ft_strlen(g_shell.envp[j]) - 1] = '\0';
		j++;
	}
	g_shell.envp[j] = NULL;
	read(g_shell.fd[2][0], &g_shell.status, sizeof(int));
}
