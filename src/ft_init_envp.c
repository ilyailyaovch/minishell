/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_envp.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleoma <pleoma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 12:08:38 by pleoma            #+#    #+#             */
/*   Updated: 2022/05/24 15:28:58 by pleoma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

/*	creates g_shell.envp */

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

/*	creates g_shell.envp, returns mass */

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

/* concatinate two arrays and return them as one */

char	**put_envp(char **envp, char *str, int free_flag)
{
	char	**new_arr;
	int		j;

	new_arr = malloc(sizeof(char *) * (arr_size(envp) + 2));
	if (!new_arr)
		ft_error("count_cmd: ", ENOMEM);
	j = 0;
	while (envp[j])
	{
		new_arr[j] = ft_strdup(envp[j]);
		j++;
	}
	new_arr[j] = ft_strdup(str);
	j++;
	new_arr[j] = NULL;
	if (free_flag)
		ft_free_mass(envp);
	return (new_arr);
}
