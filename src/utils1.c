/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Arbiter <Arbiter@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 14:01:16 by pleoma            #+#    #+#             */
/*   Updated: 2022/05/20 20:49:11 by Arbiter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

/*	finds len of two dimentional array
	used in	ft_init.c 
			put_envp.c	*/

int	arr_size(char **envp)
{
	int	i;

	i = 0;
	while (envp[i])
		i++;
	return (i);
}


/*	finds max of two elements
	used in ft_sigil.c	*/

int	max(int a, int b)
{
	if (a > b)
		return (a);
	else
		return (b);
}

/*	finds length of env variable bafore '='
	used in ft_sigil.c	*/

int	ft_len_before_eq(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '=' && str[i] != '\0')
		i++;
	return (i);
}

/*	errormanagment for cd	*/

void	ifs(int j, int i, char *args, char *str)
{
	if (j == 1 && i)
		chdir(str);
	else if (j != 1)
		ft_errmsg("minishell: cd: ", args, ": No such file or directory", -1);
	else if (j == 1 && !i)
		ft_errmsg("minishell: cd: ", args, ": Not a directory", -1);
}

void	ft_free(char **mass)
{
	int	sizemass;

	sizemass = 0;
	while (mass[sizemass])
	{
		free(mass[sizemass]);
		sizemass++;
	}
	free(mass);
}