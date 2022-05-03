/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_signals.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleoma <pleoma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 11:56:32 by pleoma            #+#    #+#             */
/*   Updated: 2022/05/03 14:16:10 by pleoma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	shell_handler(int sig)
{
	if (sig == SIGINT)
	{
		rl_on_new_line();
		rl_redisplay();
		printf("  \n");
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
	}
}

// void	handler_quit(int sig)
// {
// 	if (sig == SIGINT)
// 		write(1, "\n", 1);
// 	if (sig == SIGQUIT)
// 		write(1, "Quit: 3\n", 8);
// }

void	ft_signals(void)
{
	// signal(SIGINT, handler_quit);
	// signal(SIGQUIT, handler_quit);
	signal(SIGQUIT, SIG_IGN);
	signal(SIGINT, shell_handler);
}

void	ft_pipe_signals(void)
{
	signal(SIGINT, SIG_IGN);
	signal(SIGQUIT, SIG_IGN);
}
