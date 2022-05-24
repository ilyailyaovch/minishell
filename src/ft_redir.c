/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_redir.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleoma <pleoma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 13:28:15 by pleoma            #+#    #+#             */
/*   Updated: 2022/05/24 15:13:30 by pleoma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	redirect_in(t_cmd *cmd)
{
	t_dict	*tmp;
	int		fd;

	tmp = cmd->infd;
	fd = 0;
	while (tmp)
	{
		if (fd)
			close(fd);
		if (!ft_strncmp("<", tmp->key, ft_strlen(tmp->key)))
			fd = open(tmp->value, O_RDONLY, 0777);
		else if (!ft_strncmp("<<", tmp->key, ft_strlen(tmp->key)))
			fd = open(cmd->name, O_RDONLY);
		if (fd < 0)
			ft_shell_error(tmp->value, errno, EXIT_FLAG);
		tmp = tmp->next;
	}
	if (fd && dup2(fd, STDIN_FILENO) < 0)
		ft_shell_error("file: ", errno, EXIT_FLAG);
	if (fd)
		close(fd);
	if (cmd->tmpfile && unlink(cmd->name) < 0)
		ft_shell_error("unlink: ", errno, EXIT_FLAG);
}

void	redirect_out(t_cmd *cmd)
{
	t_dict	*tmp;
	int		fd;

	tmp = cmd->outfd;
	fd = 0;
	while (tmp)
	{
		if (fd)
			close(fd);
		if (!ft_strncmp(">", tmp->key, ft_strlen(tmp->key)))
			fd = open(tmp->value, O_WRONLY | O_TRUNC | O_CREAT, 0777);
		else if (!ft_strncmp(">>", tmp->key, ft_strlen(tmp->key)))
			fd = open(tmp->value, O_WRONLY | O_APPEND | O_CREAT, 0777);
		if (fd < 0)
			ft_shell_error(tmp->value, errno, EXIT_FLAG);
		tmp = tmp->next;
	}
	if (fd && dup2(fd, STDOUT_FILENO) < 0)
		ft_shell_error("file: ", errno, EXIT_FLAG);
	if (fd)
		close(fd);
}
