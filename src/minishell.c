/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleoma <pleoma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 10:45:36 by pleoma            #+#    #+#             */
/*   Updated: 2022/04/18 13:23:22 by pleoma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	minishell(void)
{
	printf(BLUE"IT WORKS FINE\n"WTH);
	while (true)
	{
		char *str = readline(GREEN"myshell> "WTH);
		add_history(str);

		if (!ft_strncmp(str, "exit", 4))
			ft_shell_error("exit", 0, EXIT_FLAG);
			
		free(str);
	}
}
