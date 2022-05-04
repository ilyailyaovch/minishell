/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quotes_pipes.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spzona <spzona@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 15:26:34 by spzona            #+#    #+#             */
/*   Updated: 2022/05/04 15:58:03 by spzona           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

/*	checks lasts pipe at the end of the line */

int	check_last_pipe(char *line)
{
	int	coun;
	int	pipe;

	coun = 0;
	pipe = 0;
	while (line[coun])
	{
		if (line[coun] == '|')
			pipe = 1;
		else if (line[coun] != ' ')
			pipe = 0;
		coun++;
	}
	return (pipe);
}

/*	checks pipe at the end of the line and waits line */

int	ft_one_pipe(void)
{
	char	*tmpline;
	char	*tmpread;

	while (check_last_pipe(g_shell.line))
	{
		tmpline = ft_strdup(g_shell.line);
		free(g_shell.line);
		tmpread = readline(" > ");
		if (!tmpread)
		{
			ft_shell_error("\033[0;32mmyshell:\033[0;37m", 258, 0);
			ft_shell_error(" syntax error: unexpected end of file\n", 258, 0);
			return (1);
		}
		g_shell.line = ft_strjoin(tmpline, tmpread);
		free(tmpread);
		free(tmpline);
	}
	return (0);
}

/*	checks pipe at the beggining of the line */

int	check_first_pipe(void)
{
	int	i;

	i = 0;
	while (g_shell.line[i] != '\0' && g_shell.line[i] == ' ')
		i++;
	if (g_shell.line[i] == '|')
		return (0);
	else
		return (1);
}

/*	checks unclosed quotes */

int	check_quotes(void)
{
	int	i;

	i = 0;
	while (g_shell.line[i] != '\0')
	{
		if (g_shell.line[i] == '\'')
		{
			i++;
			while (g_shell.line[i] != '\0' && g_shell.line[i] != '\'')
				i++;
			if (g_shell.line[i] == '\0')
				return (0);
		}
		if (g_shell.line[i] == '"')
		{
			i++;
			while (g_shell.line[i] != '\0' && g_shell.line[i] != '"')
				i++;
			if (g_shell.line[i] == '\0')
				return (0);
		}
		i++;
	}
	return (1);
}

/*	checks unclosed quotes and pipe at the beggining of the line and returns */

int	check_quotes_pipe(void)
{
	if (!check_quotes())
	{
		ft_shell_error("\033[0;32mmyshell: \033[0;37m", 21, 0);
		ft_shell_error(g_shell.line, 21, 0);
		ft_shell_error(": unclosed quotes\n", 21, 0);
		free(g_shell.line);
		return (1);
	}
	if (!check_first_pipe())
	{
		ft_shell_error("\033[0;32mmyshell:\033[0;37m", 258, 0);
		ft_shell_error(" syntax error near unexpected token `|'\n", 258, 0);
		free(g_shell.line);
		return (1);
	}
	return (0);
}
