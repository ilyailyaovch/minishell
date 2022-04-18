/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleoma <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 22:03:20 by pleoma            #+#    #+#             */
/*   Updated: 2021/10/07 22:03:20 by pleoma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	coun;

	coun = 0;
	if ((dest == NULL) && (src == NULL))
		return (NULL);
	while (coun < n)
	{
		((unsigned char *)dest)[coun] = ((unsigned char *)src)[coun];
		coun++;
	}
	return (dest);
}
