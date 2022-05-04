/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleoma <pleoma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 12:08:38 by pleoma            #+#    #+#             */
/*   Updated: 2022/05/04 12:14:16 by pleoma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

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