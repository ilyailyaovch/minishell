/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_envp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spzona <spzona@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 19:06:39 by spzona            #+#    #+#             */
/*   Updated: 2022/05/23 13:52:35 by spzona           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

/* concatinate two arrays and return them as one */

char	**put_envp(char **envp, char *str, int free_flag)
{
	char	**new_arr;
	int		j;

	new_arr = malloc(sizeof(char *) * (arr_size(envp) + 2));
	if (!new_arr)
		ft_error("count_cmd", ENOMEM);
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
