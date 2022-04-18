/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleoma <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 22:03:23 by pleoma            #+#    #+#             */
/*   Updated: 2021/10/07 22:03:23 by pleoma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*new_dest;
	unsigned char	*new_src;

	if ((dest == NULL) && (src == NULL))
		return (NULL);
	if (dest == src)
		return (dest);
	if (dest > src)
	{	
		new_dest = (unsigned char *)dest + n - 1;
		new_src = (unsigned char *)src + n - 1;
		while (n--)
			*(new_dest--) = *(new_src--);
	}
	else
	{
		new_dest = (unsigned char *)dest;
		new_src = (unsigned char *)src;
		while (n--)
			*(new_dest++) = *(new_src++);
	}
	return (dest);
}
