/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quotes.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spzona <spzona@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 15:26:34 by spzona            #+#    #+#             */
/*   Updated: 2022/05/03 16:02:09 by spzona           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

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

int	check_quotes(void)
{
	int	i;

	i = 0;
	while (g_shell.line[i] != '\0')
	{
		if (g_shell.line[i] == "\'")
		{
			i++;
			while (g_shell.line[i] != '\0' && g_shell.line != '\'')
			 i++;
			if (g_shell.line[i] == '\0')
				return (0);
		}
	}
	if (g_shell.line[i] == '"')
	{
		i++;
		while (g_shell.line[i] != '\0' && g_shell.line[i] != '"')
			i++;
		if (g_shell.line[i] == '\0')
			return (0);
	}
	return (1);
}

int	check_quotes_pipe(void)
{
	if (!chek_quotes())
	{
		ft_shell_error("\033[0;32mminishell: \033[0;37m", 21, 0);
		ft_shell_error(g_shell.line, 21, 0);
		ft_shell_error(": unclosed quotes", 21, 0);
		free(g_shell.line);
		return (1);
	}
	if (!check_first_pipe())
	{
		ft_shell_error("\033[0;32mminishell:\033[0;37m", 258, 0);
		ft_shell_error(" syntax error near unexpected token `|'", 258, 0);
		free(g_shell.line);
		return (1);
	}
	return (0);
}

