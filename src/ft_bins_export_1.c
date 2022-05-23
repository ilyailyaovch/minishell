/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bins_export_1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spzona <spzona@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 13:07:21 by pleoma            #+#    #+#             */
/*   Updated: 2022/05/23 13:39:34 by spzona           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char	*check_double(char *args, char **envp)
{
	int		i;
	char	*str_tmp;

	i = 0;
	str_tmp = malloc(sizeof(char) * (ft_sym_export(args) + 1));
	if (!str_tmp)
		return (NULL);
	while (args[i] != '\0' && args[i] != '=')
	{
		str_tmp[i] = args[i];
		i++;
	}
	str_tmp[i] = '\0';
	i = 0;
	while (envp[i])
	{
		if (!ft_strncmp(str_tmp, envp[i], max(ft_strlen(str_tmp),
					ft_sym_export(envp[i]))))
			return (str_tmp);
		i++;
	}
	free(str_tmp);
	return (NULL);
}

void	exp_withot_args(char **envp)
{
	int		i;
	char	**tmpmass;
	char	**before;
	char	**after;

	i = 0;
	tmpmass = ft_new_envp_return(envp);
	tmpmass = sort_mass_bubble(tmpmass);
	before = mass_quots_before(tmpmass);
	after = mass_quots_after(tmpmass);
	while (tmpmass[i])
	{
		if (!ft_strchr(tmpmass[i], '='))
			printf("declare -x %s\n", before[i]);
		else
			printf("declare -x %s=\"%s\"\n", before[i], after[i]);
		i++;
	}
	ft_free_mass(tmpmass);
	ft_free_mass(before);
	ft_free_mass(after);
}

void	change_envp(char *new, char **args, int i)
{
	if (new && ft_strrchr(args[i], '='))
		g_shell.envp = replace_envp_el(g_shell.envp, args[i], new);
	else if (!new)
		g_shell.envp = export_envp(g_shell.envp, args[i], 1);
}

char	**ft_export(char **args)
{
	int		i;
	int		j;
	char	*new;

	if (!args[1])
		exp_withot_args(g_shell.envp);
	i = 0;
	while (args[++i])
	{
		j = -1;
		new = check_double(args[i], g_shell.envp);
		while (args[i][++j])
		{
			if (!ft_isalpha(args[i][0]) || args[i][0] == '=')
				ft_shell_error_multi("export: `",
					args[i], "': not a valid identifier\n", 1);
			else
				change_envp(new, args, i);
			break ;
		}
		if (new)
			free(new);
	}
	return (g_shell.envp);
}
