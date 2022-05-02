/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spzona <spzona@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 14:01:16 by pleoma            #+#    #+#             */
/*   Updated: 2022/05/02 19:15:21 by spzona           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

unsigned int	len_of_mass(char **mass)
{
	int	coun;

	coun = 0;
	while(mass[coun])
		coun++;
	return (coun);
}

void	ft_new_envp(char **envp)
{
	int		coun;
	char	**new_env;
	
	coun = -1;
	new_env = malloc(sizeof(char *) * (len_of_mass(envp) + 1));
	if (!new_env)
		ft_error("ft_new_envp(char **envp): ", ENOMEM);
	while(envp[++coun])
		new_env[coun]  = ft_strdup(envp[coun]);
	new_env[coun] = NULL;
	g_shell.envp = new_env;
	g_shell.status = 0;
}