/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleoma <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 18:34:30 by pleoma            #+#    #+#             */
/*   Updated: 2021/10/08 14:33:00 by pleoma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *dest, size_t n)
{
	size_t			coun;
	unsigned char	*pointer;

	coun = 0;
	pointer = (unsigned char *)dest;
	while (coun < n)
	{
		pointer[coun] = '\0';
		coun++;
	}
}
