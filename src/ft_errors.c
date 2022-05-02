/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_errors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleoma <pleoma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 19:43:48 by pleoma            #+#    #+#             */
/*   Updated: 2022/05/02 09:58:11 by pleoma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

/* Function handles errors of main programm */

void	ft_error(char *argv, int exit_code)
{
	// if (exit_code == 127)
	// {
	// 	printf(RED"command not found: "WTH);
	// 	printf("%s\n", argv);
	// 	exit(EXIT_FAILURE);
	// }
	printf(RED"%s: "WTH, strerror(exit_code));
	printf("%s\n", argv);
	exit(EXIT_FAILURE);
}

/* Function handles errors of myshell */

void	ft_shell_error(char *argv, int exit_code, int exit_flag)
{
	ft_putstr_fd(argv, 2);
	ft_putstr_fd("\n", 2);
	//main_struct.status = exit_code;
	if (exit_flag == EXIT_FLAG)
		exit (exit_code);
}
