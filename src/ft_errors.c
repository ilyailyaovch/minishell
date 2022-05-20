/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_errors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Arbiter <Arbiter@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 19:43:48 by pleoma            #+#    #+#             */
/*   Updated: 2022/05/20 20:43:56 by Arbiter          ###   ########.fr       */
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
	//ft_putstr_fd("\n", 2);
	g_shell.status = exit_code;
	if (exit_flag == EXIT_FLAG)
		exit (exit_code);
}

void	ft_errmsg(char *s1, char *s2, char *s3, int code)
{
	ft_putstr_fd(s1, 2);
	ft_putstr_fd(s2, 2);
	ft_putstr_fd(s3, 2);
	ft_putstr_fd("\n", 2);
	if (code < 0)
		g_shell.status = -code;
	else
		exit(code);
}