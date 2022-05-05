/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spzona <spzona@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 14:01:16 by pleoma            #+#    #+#             */
/*   Updated: 2022/05/05 19:11:57 by spzona           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

/*	finds len of two dimentional array
	used in ft_init.c	*/

int	len_of_mass(char **mass)
{
	int	coun;

	coun = 0;
	while(mass[coun])
		coun++;
	return (coun);
}

/*	finds man of two elements
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

/*	return array size as int */

int	arr_size(char **envp)
{
	int	i;

	i = 0;
	while (envp[i])
		i++;
	return (i);
}