/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleoma <pleoma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 10:45:36 by pleoma            #+#    #+#             */
/*   Updated: 2022/05/16 11:33:26 by pleoma           ###   ########.fr       */
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
			ft_get_cmd();
			//ft_signals();				//не надо вроде
			ft_executor(g_shell.cmd); 	//
			ft_free_all();				//

			//Написать проверку на лист
			// t_list *tmp;
			// tmp = g_shell.list;
			// while (tmp)
			// {
			// 	printf("Elem of list: %s\n", tmp->content);
			// 	tmp = tmp->next;
			// }

			//Написать проверку на cmd
			// t_cmd	*tmp_c;
			// tmp_c = g_shell.cmd;
			// while (tmp_c)
			// {
			// 	printf("cmd	arg: %s\n", tmp_c->args[0]);
			// 	printf("cmd	arg: %s\n", tmp_c->args[1]);
			// 	printf("cmd	count: %d\n", tmp_c->count);
			// 	//printf("cmd	in_dick_key: %s\n", tmp_c->infd->key);
			// 	//printf("cmd	in_dick_value: %s\n", tmp_c->infd->value);
			// 	printf("cmd	in_dick_key: %s\n", tmp_c->outfd->key);
			// 	printf("cmd	in_dick_value: %s\n", tmp_c->outfd->value);
			// 	printf("enumed cmd: %s\n", tmp_c->i);
			// 	tmp_c = tmp_c->next;
			// }
		}
	}
}
