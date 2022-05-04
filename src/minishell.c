/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spzona <spzona@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 10:45:36 by pleoma            #+#    #+#             */
/*   Updated: 2022/05/04 19:27:24 by spzona           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_init_g_shell(void)
{
	//signal(SIGQUIT, SIG_IGN);
	//signal(SIGINT, shell_handler);
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
		ft_shell_error("\033[1A\033[0;32mmyshell>\033[0;37m exit\n", 1, EXIT_FLAG);
	if (!ft_strncmp(g_shell.line , "exit", 4))
		ft_shell_error("exit\n", 0, EXIT_FLAG);
	add_history(g_shell.line);
}

void	minishell(void)
{
	printf(BLUE"WELLCUM to minishell by ...\n"WTH);
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
			//ft_get_cmd();
			//ft_signals();				//не надо вроде
			//ft_executor(g_shell.cmd); //потом
			//ft_free_all();			//вставить в конце

			//Написать проверку на лист
			// t_list *tmp;
			// tmp = g_shell.list;
			// while (tmp)
			// {
			// 	printf("Elem of list: %s\n", tmp->content);
			// 	tmp = tmp->next;
			// }
		}
	}
}
