/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bins_export_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleoma <pleoma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 10:31:34 by pleoma            #+#    #+#             */
/*   Updated: 2022/05/23 11:05:26 by pleoma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	ft_sym_export(char *str)
{
	int	j;

	j = 0;
	while (str[j] && str[j] != '=')
		j++;
	return (j);
}

char	**sort_mass_bubble(char **mass)
{
	int		i;
	int		k;
	int		j;
	char	*tmp;

	i = -1;
	j = arr_size(mass);
	while (++i < (j - 1))
	{
		k = -1;
		while (++k < (j - i - 1))
		{
			if (ft_strncmp(mass[k], mass[k + 1], ft_sym_export(mass[k])) > 0)
			{
				tmp = ft_strdup(mass[k]);
				free(mass[k]);
				mass[k] = ft_strdup(mass[k + 1]);
				free(mass[k + 1]);
				mass[k + 1] = ft_strdup(tmp);
				free(tmp);
			}
		}
	}
	mass[i + 1] = NULL;
	return (mass);
}

char	**mass_quots_after(char **tmpmass)
{
	int		i;
	int		j;
	int		k;
	char	**after;

	after = malloc(sizeof(char *) * (arr_size(tmpmass) + 1));
	if (!after)
		return (NULL);
	i = -1;
	while (tmpmass[++i])
	{
		k = 0;
		after[i] = malloc(sizeof(char) * (ft_strlen(tmpmass[i])
					- ft_sym_export(tmpmass[i]) + 1));
		if (!after[i])
			return (NULL); //Можно написать ошибку
		j = ft_sym_export(tmpmass[i]);
		while (tmpmass[i][++j] != '\0')
			after[i][k++] = tmpmass[i][j];
		after[i][k] = '\0';
	}
	after[i] = NULL;
	return (after);
}

char	**mass_quots_before(char **tmpmass)
{
	int		i;
	int		j;
	char	**before;

	before = malloc(sizeof(char *) * (arr_size(tmpmass) + 1));
	if (!before)
		return (NULL);
	i = -1;
	while (tmpmass[++i])
	{
		j = -1;
		before[i] = malloc(sizeof(char) * (ft_sym_export(tmpmass[i]) + 1));
		if (!before[i])
			return (NULL); //Можно написать ошибку
		if (!ft_strchr(tmpmass[i], '='))
			before[i] = ft_strdup(tmpmass[i]);
		else
		{
			while (tmpmass[i][++j] != '=')
				before[i][j] = tmpmass[i][j];
			before[i][j] = '\0';
		}
	}
	before[i] = NULL;
	return (before);
}
