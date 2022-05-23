/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spzona <spzona@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 12:08:38 by pleoma            #+#    #+#             */
/*   Updated: 2022/05/23 14:01:13 by spzona           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_new_envp(char **envp)
{
	int		coun;
	char	**new_env;

	coun = -1;
	new_env = malloc(sizeof(char *) * (arr_size(envp) + 1));
	if (!new_env)
		ft_error("ft_new_envp(char **envp): ", ENOMEM);
	while (envp[++coun])
		new_env[coun] = ft_strdup(envp[coun]);
	new_env[coun] = NULL;
	g_shell.envp = new_env;
	g_shell.status = 0;
}

char	**ft_new_envp_return(char **envp)
{
	char	**new_mass;
	int		i;

	new_mass = malloc(sizeof(char *) * (arr_size(envp) + 1));
	if (!new_mass)
		ft_error("ft_new_envp_return(char **envp): ", ENOMEM);
	i = 0;
	while (envp[i])
	{
		new_mass[i] = ft_strdup(envp[i]);
		i++;
	}
	new_mass[i] = NULL;
	return (new_mass);
}
