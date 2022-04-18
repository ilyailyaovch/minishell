/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleoma <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 17:59:39 by pleoma            #+#    #+#             */
/*   Updated: 2021/10/04 18:00:12 by pleoma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *dest, int c, size_t n)
{
	size_t			coun;
	unsigned char	*pointer;

	coun = 0;
	pointer = (unsigned char *)dest;
	while (coun < n)
	{
		pointer[coun] = c;
		coun++;
	}
	return (dest);
}
