/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleoma <pleoma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 14:11:41 by pleoma            #+#    #+#             */
/*   Updated: 2022/05/02 16:15:50 by pleoma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

/*	frees array */

void	ft_free_mass(char **arr)
{
	int	coun;

	coun = 0;
	while(arr[coun])
	{
		free(arr[coun]);
		coun++;
	}
	free(arr);
}