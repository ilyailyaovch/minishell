/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleoma <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 22:03:53 by pleoma            #+#    #+#             */
/*   Updated: 2021/10/07 22:03:53 by pleoma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	len_d;
	size_t	len_s;
	size_t	j;
	size_t	coun;

	len_d = ft_strlen(dst);
	len_s = ft_strlen((char *)src);
	coun = 0;
	if (size == 0)
		return (len_s);
	if (size > len_d)
	{	
		j = len_d;
		while (src[coun] && (j < size - 1))
		{
			dst[j] = src[coun];
			coun++;
			j++;
		}
		dst[j] = '\0';
		return (len_d + len_s);
	}
	return (len_s + size);
}
