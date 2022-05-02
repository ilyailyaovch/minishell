/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_errors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleoma <pleoma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 19:43:48 by pleoma            #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2022/05/02 14:59:22 by pleoma           ###   ########.fr       */
=======
/*   Updated: 2022/05/02 13:47:36 by pleoma           ###   ########.fr       */
>>>>>>> 6ed10b9d91b59b76dbc49e67ae50f7e674cbeffd
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

/* Function handles errors of main programm by code*/

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
	ft_putstr_fd("\n", 2);
	g_shell.status = exit_code;
	if (exit_flag == EXIT_FLAG)
		exit (exit_code);
}
