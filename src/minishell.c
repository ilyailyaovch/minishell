/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleoma <pleoma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 10:45:36 by pleoma            #+#    #+#             */
/*   Updated: 2022/05/02 12:20:06 by pleoma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_readline(void)
{
	char	*str; //  тут будет наша глобалка
	str = readline(GREEN"myshell> "WTH);
	if (!str)
	{
		printf(RED"myshell>  exit\n"WTH);
		exit(0);
	}
	if (!ft_strncmp(str, "exit", 4))
		ft_shell_error("exit", 0, EXIT_FLAG);
	add_history(str);
	//free(str);
}

void	minishell(void)
{
	printf(BLUE"WELLCUM to minishell by ...\n"WTH);
	while (true)
	{
		//ft_init();
		ft_readline();
		//if (line)
		// {
		//	if (check_quots_pipe())
			// 	continue ;
		// 	prompt_pipe();
		// 	lecser_parser();
		// 	signals();
		// 	executor();
		// 	ft_free_all();		
		// }
	}
}
