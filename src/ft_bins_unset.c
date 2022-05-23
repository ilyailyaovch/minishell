/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bins_unset.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleoma <pleoma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 13:07:25 by pleoma            #+#    #+#             */
/*   Updated: 2022/05/23 14:39:53 by pleoma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

/* func runs through the envp and creates new 
	ignoring var, that should be unset		*/

static char	**unset_from_envp(char *args, char **envp)
{
	int		i;
	int		j;
	char	**new_mass;

	new_mass = malloc(sizeof(char *) * arr_size(envp));
	if (!new_mass)
		ft_error("ft_bins_unset.c", ENOMEM);
	i = 0;
	j = 0;
	while (envp[j])
	{
		if (ft_strncmp(envp[j], args, ft_strlen(args)) == 0)
			j++;
		if (!envp[j])
			break ;
		new_mass[i] = ft_strdup(envp[j]);
		i++;
		j++;
	}
	new_mass[i] = NULL;
	ft_free_mass(envp);
	return (new_mass);
}

/*	funk checks if there a variable
	which should be unset
	returns 1 if variable exists	*/

int	check_unset(char *args, char **envp)
{
	int	i;

	i = 0;
	while (envp[i])
	{
		if (ft_strncmp(envp[i], args, ft_strlen(args)) == 0)
			return (1);
		i++;
	}
	return (0);
}

/*	func replaces old envp with new
	without unset varialble			*/

static char	**ft_make_unset_envp(char **args, char **envp, bool correct_usage)
{	
	int	i;

	i = 0;
	while (args[++i])
	{
		if (correct_usage && check_unset(args[i], envp))
			envp = unset_from_envp(args[i], envp);
	}
	return (envp);
}

/*	funk checks right symbols in cmd
	and establish flag "correct usage"
	correct_usage = true, if it's no extra symbols	*/

static void	ft_check_unset_usage(char **args, bool *correct_usage)
{
	int	i;
	int	j;

	i = 0;
	while (args[i])
	{
		j = 0;
		*correct_usage = true;
		while (args[i][j])
		{
			if (ft_isalnum(args[i][j]) == false)
			{
				ft_shell_error_multi("unset: `", args[i],
					"': not a valid identifier\n", 1);
				*correct_usage = false;
				break ;
			}
			j++;
		}
		i++;
	}
}

/*	func takes arg and looks fot it in envp
	if it exist that deletes it
	returns new enwp without arg	*/

char	**ft_unset(char **args, char **envp)
{
	bool	correct_usage;

	ft_check_unset_usage(args, &correct_usage);
	envp = ft_make_unset_envp(args, envp, correct_usage);
	g_shell.status = 0;
	return (envp);
}
