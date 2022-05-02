/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spzona <spzona@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 10:45:36 by pleoma            #+#    #+#             */
/*   Updated: 2022/05/02 19:15:20 by spzona           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_readline(void)
{
	g_shell.line = readline(GREEN"myshell> "WTH);
	if (!g_shell.line)
		ft_shell_error("exit myshell", 1, EXIT_FLAG);
	if (!ft_strncmp(g_shell.line , "exit", 4))
		ft_shell_error("exit", 0, EXIT_FLAG);
	add_history(g_shell.line);
}

void	minishell(void)
{
	printf(BLUE"WELLCUM to minishell by ...\n"WTH);
	while (true)
	{
		//ft_init();
		ft_readline();
		//if (*t_shell.line && ft_strlen(g_line.line))
		// {
		//	if (check_quots_pipe())
			// 	continue ;
		// 	prompt_pipe();
		ft_parser();
		// 	signals();
		// 	executor();
		// 	ft_free_all();		
		// }
	}
}
