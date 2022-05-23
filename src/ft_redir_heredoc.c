/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_redir_heredoc.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spzona <spzona@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 15:44:15 by pleoma            #+#    #+#             */
/*   Updated: 2022/05/23 13:53:43 by spzona           ###   ########.fr       */
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

char	*heredoc(char *delim)
{
	char	*tmpline1;
	char	*tmpline2;
	char	*tmpline3;
	char	*line;

	tmpline1 = readline("heredoc > ");
	if (!tmpline1)
		return (NULL);
	line = NULL;
	while (ft_strncmp(tmpline1, delim, ft_strlen(tmpline1)))
	{
		tmpline2 = ft_strjoin(tmpline1, "\n");
		if (line)
		{
			tmpline3 = ft_strdup(line);
			free(line);
			line = ft_strjoin(tmpline3, tmpline2);
			free(tmpline3);
		}
		else
			line = ft_strdup(tmpline2);
		free(tmpline1);
		free(tmpline2);
		tmpline1 = readline("heredoc > ");
		if (!tmpline1)
			return (line);
	}
	free(tmpline1);
	return (line);
}

void	tmp_heredoc_file(char *delim, t_cmd *cmd)
{
	int		fd;
	char	*line;

	line = heredoc(delim);
	cmd->name = ft_strjoin(".tmpfile", cmd->i);
	fd = open(cmd->name, O_WRONLY | O_TRUNC | O_CREAT, 0777);
	if (fd < 0)
		ft_shell_error(cmd->name, errno, EXIT_FLAG);
	if (!line)
	{
		close(fd);
		return ;
	}
	write(fd, line, ft_strlen(line));
	close(fd);
	free(line);
	cmd->tmpfile = 1;
}

void	ft_init_heredoc_instd(t_cmd *cmd)
{
	t_cmd	*tmp;
	t_dict	*dict;

	tmp = cmd;
	while (tmp)
	{
		dict = tmp->infd;
		while (dict)
		{
			if (!ft_strncmp("<<", dict->key, 2))
				tmp_heredoc_file(dict->value, tmp);
			dict = dict->next;
		}
		tmp = tmp->next;
	}
}
