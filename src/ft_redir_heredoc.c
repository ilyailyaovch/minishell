/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_redir_heredoc.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleoma <pleoma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 15:44:15 by pleoma            #+#    #+#             */
/*   Updated: 2022/05/06 18:16:08 by pleoma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char	*heredoc(char *delim)
{
	char	*tmpline1;
	char	*tmpline2;
	char	*tmpline3;
	char	*line;

	tmpline1 = readline("heredoc > ");
	if(!tmpline1)
		return ("\0");
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
		if(!tmpline1)
			return ("\0");
	}
	free(tmpline1);
	return (line);
}

void	tmp_heredoc_file(char *delim, t_cmd *cmd)
{
	int		fd;
	char	*line;

	line = heredoc(delim);
	if (!line)
		return ;
	cmd->name = ft_strjoin(".tmpfile", cmd->i);
	fd = open(cmd->name, O_WRONLY | O_TRUNC | O_CREAT, 0777);
	if (fd < 0)
		ft_shell_error(cmd->name, errno, EXIT_FLAG);
	write(fd, line, ft_strlen(line));
	close(fd);
	if (line)
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