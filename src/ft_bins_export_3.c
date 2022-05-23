/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bins_export_3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleoma <pleoma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 10:43:45 by pleoma            #+#    #+#             */
/*   Updated: 2022/05/23 11:05:28 by pleoma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char	**export_envp(char **envp, char *str, int free_fl)
{
	char	**new_mass;
	int		j;

	new_mass = malloc(sizeof(char *) * (arr_size(envp) + 2));
	if (!new_mass)
		return (NULL);
	j = 0;
	while (envp[j])
	{
		new_mass[j] = ft_strdup(envp[j]);
		j++;
	}
	new_mass[j] = ft_strdup(str);
	j++;
	new_mass[j] = NULL;
	if (free_fl)
		ft_free_mass(envp);
	return (new_mass);
}

char	**replace_envp_el(char **envp, char *args, char *new)
{
	char	**new_mass;
	int		j;

	j = 0;
	new_mass = malloc(sizeof(char *) * (arr_size(envp) + 1));
	if (!new_mass)
		return (NULL);
	while (envp[j])
	{
		if (ft_strncmp(envp[j], new, max(ft_strlen(new),
					ft_sym_export(envp[j]))))
			new_mass[j] = ft_strdup(envp[j]);
		else
			new_mass[j] = ft_strdup(args);
		j++;
	}
	new_mass[j] = NULL;
	ft_free_mass(envp);
	return (new_mass);
}