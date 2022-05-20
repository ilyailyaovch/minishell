/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bins_export.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Arbiter <Arbiter@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 13:07:21 by pleoma            #+#    #+#             */
/*   Updated: 2022/05/20 20:54:02 by Arbiter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

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
	ft_free(envp);
	return (new_mass);
}

int	ft_sym_export(char *str)
{
	int	j;

	j = 0;
	while (str[j] && str[j] != '=')
		j++;
	return (j);
}

char	**export_envp(char **envp, char *str, int free)
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
	if (free)
		ft_free(envp);
	return (new_mass);
}