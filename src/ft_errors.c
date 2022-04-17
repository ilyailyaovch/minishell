/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_errors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleoma <pleoma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 19:43:48 by pleoma            #+#    #+#             */
/*   Updated: 2022/04/17 19:44:12 by pleoma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_error(int exit_code, char *argv)
{
	if (exit_code == -1)
	{
		printf(RED"command not found: "WTH);
		printf("%s\n", argv);
		exit(EXIT_FAILURE);
	}
	printf(RED"%s: "WTH, strerror(exit_code));
	printf("%s\n", argv);
	exit(EXIT_FAILURE);
}