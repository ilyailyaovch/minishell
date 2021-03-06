/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleoma <pleoma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 10:45:36 by pleoma            #+#    #+#             */
/*   Updated: 2022/05/24 15:40:07 by pleoma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static void	ft_beautiful_header(float ver)
{
	printf(BLUE"------------------------------\n"WTH);
	printf(BLUE"WELLCUM to minishell by ...\n"WTH);
	printf(BLUE"Version %.2f\n"WTH, ver);
	printf(BLUE"------------------------------\n"WTH);
}

void	ft_init_g_shell(void)
{
	if ((pipe(g_shell.fd[0])) == -1)
		ft_shell_error("minishell: pipe: \n", errno, EXIT_FLAG);
	if ((pipe(g_shell.fd[1])) == -1)
		ft_shell_error("minishell: pipe: \n", errno, EXIT_FLAG);
	if ((pipe(g_shell.fd[2])) == -1)
		ft_shell_error("minishell: pipe: \n", errno, EXIT_FLAG);
	g_shell.list = NULL;
	g_shell.cmd = NULL;
	g_shell.line = NULL;
}

void	ft_readline(void)
{
	g_shell.line = readline(GREEN"myshell> "WTH);
	if (!g_shell.line)
		ft_shell_error("\033[1A\033[0;31mmyshell>\033[0;37m exit\n", 1, EXIT_FLAG);
	add_history(g_shell.line);
}

void	minishell(void)
{
	ft_beautiful_header(1.10);
	while (true)
	{
		ft_init_g_shell();
		ft_signals();
		ft_readline();
		if (*g_shell.line && ft_strlen(g_shell.line))
		{
			if (check_quotes_pipe())
				continue ;
			if (ft_one_pipe())
				continue ;
			ft_sigil();
			ft_parser();
			ft_remove_extra_quotes();
			ft_get_cmd();
			ft_executor(g_shell.cmd);
			ft_free_all();
		}
	}
}
