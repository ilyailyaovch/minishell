/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_errors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleoma <pleoma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 19:43:48 by pleoma            #+#    #+#             */
/*   Updated: 2022/05/23 14:51:31 by pleoma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

/* Function handles standart errors by code */

void	ft_error(char *argv, int exit_code)
{
	printf(RED"%s: "WTH, strerror(exit_code));
	printf("%s\n", argv);
	exit(EXIT_FAILURE);
}

/* Function handles errors of myshell by argument */

void	ft_shell_error(char *argv, int exit_code, int exit_flag)
{
	ft_putstr_fd(argv, 2);
	g_shell.status = exit_code;
	if (exit_flag == EXIT_FLAG)
		exit (exit_code);
}

/* Function handles errors of myshell by argument 
	but do not exits			*/

void	ft_shell_error_multi(char *argv_2, char *argv_3,
		char *argv_4, int exit_code)
{
	printf(YELW"myshell: "WTH);
	printf("%s", argv_2);
	printf("%s", argv_3);
	printf("%s", argv_4);
	g_shell.status = exit_code;
}
