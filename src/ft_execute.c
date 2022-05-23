/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execute.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spzona <spzona@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 18:19:27 by pleoma            #+#    #+#             */
/*   Updated: 2022/05/23 13:49:04 by spzona           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

/*	func takes sys PATH and splits it into array */

static char	**get_paths(char **envp)
{
	char	**paths;
	char	*tmp;
	int		i;

	i = 0;
	while (*envp)
	{
		if (!ft_strncmp(*envp, "PATH=", 5))
		{
			paths = ft_split(*envp + 5, ':');
			while (paths[i])
			{
				tmp = ft_strjoin(paths[i], "/");
				free(paths[i]);
				paths[i] = ft_strdup(tmp);
				free(tmp);
				i++;
			}
			return (paths);
		}
		envp++;
	}
	return (0);
}

/*	func takes array of PATHs and checks access to cmd */

static char	*find_cmd(char **paths, char **cmd_flags)
{
	char	*cmd;
	int		i;

	i = 0;
	cmd = ft_strdup(cmd_flags[0]);
	if (!access(cmd_flags[0], F_OK))
		return (cmd);
	free(cmd);
	while (paths[i])
	{
		cmd = ft_strjoin(paths[i], cmd_flags[0]);
		if (!access(cmd, F_OK))
			return (cmd);
		else
			free(cmd);
		i++;
	}
	if (!cmd)
	{
		ft_shell_error("minishell: ", 0, 0);
		ft_shell_error(cmd_flags[0], 0, 0);
		ft_shell_error(": command not found\n", 127, 0);
	}
	return (NULL);
}

/*	func checks and executes build-is */

static int	exucute_build_ins(t_cmd *cmd)
{
	int		flag;

	flag = 1;
	if (!ft_strncmp(cmd->args[0], "exit", ft_strlen(cmd->args[0])))
		flag = 1;
	else if (!ft_strncmp(cmd->args[0], "cd", ft_strlen(cmd->args[0])))
		flag = 1;
	else if (!ft_strncmp(cmd->args[0], "echo", ft_strlen(cmd->args[0])))
		ft_echo(cmd);
	else if (!ft_strncmp(cmd->args[0], "pwd", ft_strlen(cmd->args[0])))
		ft_pwd();
	else if (!ft_strncmp(cmd->args[0], "env", ft_strlen(cmd->args[0])))
		ft_env();
	else if (!ft_strncmp(cmd->args[0], "export", ft_strlen(cmd->args[0])))
		g_shell.envp = ft_export(cmd->args);
	else if (!ft_strncmp(cmd->args[0], "unset", ft_strlen(cmd->args[0])))
		g_shell.envp = ft_unset(cmd->args, g_shell.envp);
	else
		flag = 0;
	return (flag);
}

/*	func takes cmd and looks for right path to it
	1) takes all possible paths
	2) looks for cmd with an access by path
	3) executes cmd
	4) frees everything								*/

static void	execute_command(t_cmd *cmd)
{
	char	**paths;
	char	*name;

	paths = get_paths(g_shell.envp);
	if (!paths)
	{
		ft_shell_error("minishell: ", 0, 0);
		ft_shell_error(cmd->args[0], 0, 0);
		ft_shell_error(": command not found\n", 127, 0);
	}
	name = find_cmd(paths, cmd->args); //Если нет пути или unset?
	ft_free_mass(paths);
	if (execve(name, cmd->args, g_shell.envp) == -1)
	{
		ft_shell_error("minishell: ", 0, 0);
		ft_shell_error(cmd->args[0], 0, 0);
		ft_shell_error(": command not found\n", 127, 0);
	}
	if (name)
		free(name);
}

/*	func checks build-ins and executes them
	if there are no build-in finds path to command */

void	ft_execute(t_cmd *cmd)
{
	pid_t	pid;

	if (exucute_build_ins(cmd))
		return ;
	pid = fork();
	if (pid == -1)
		ft_error("minishell: fork: ", errno);
	if (pid == 0)
		execute_command(cmd);
	else
		waitpid(pid, &g_shell.status, 0);
}
