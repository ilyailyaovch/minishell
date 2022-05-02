/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spzona <spzona@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 09:58:12 by pleoma            #+#    #+#             */
/*   Updated: 2022/05/02 19:15:19 by spzona           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	main(int argc, char **argv, char **envp)
{	
	if (argc != 1)
		ft_error(argv[0], EINVAL);
	ft_new_envp(envp);
	minishell();
	ft_free_mass(g_shell.envp);
	return (0);
}
