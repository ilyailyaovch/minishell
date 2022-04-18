/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleoma <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 22:03:15 by pleoma            #+#    #+#             */
/*   Updated: 2021/10/07 22:03:15 by pleoma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *buf1, const void *buf2, size_t n)
{
	size_t			coun;
	unsigned char	*p1;
	unsigned char	*p2;

	coun = 0;
	p1 = (unsigned char *)buf1;
	p2 = (unsigned char *)buf2;
	while (coun < n)
	{
		if (*p1 != *p2)
			return ((int)(*p1 - *p2));
		p1++;
		p2++;
		coun++;
	}
	return (0);
}
