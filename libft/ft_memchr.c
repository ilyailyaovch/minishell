/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleoma <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 22:03:10 by pleoma            #+#    #+#             */
/*   Updated: 2021/10/07 22:03:10 by pleoma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t n)
{
	size_t			coun;
	unsigned char	*pointer;

	coun = 0;
	pointer = (unsigned char *)str;
	while (coun < n)
	{
		if (*pointer == (unsigned char)c)
			return (pointer);
		pointer++;
		coun++;
	}
	return (NULL);
}
