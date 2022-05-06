/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_redir_heredoc.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleoma <pleoma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 15:44:15 by pleoma            #+#    #+#             */
/*   Updated: 2022/05/06 16:51:15 by pleoma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	tmp_heredoc_file(char *delim, t_cmd *cmd)
{
	int		fd;
	char	*line;

	line = heredoc(delim); //not yet
	cmd->name = ft_strjoin(".tmpfile", cmd->i);
	fd = open(cmd->name, O_WRONLY | O_TRUNC | O_CREAT, 0777);
	if (fd < 0)
		ft_shell_error(cmd->name, errno, EXIT_FLAG);
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