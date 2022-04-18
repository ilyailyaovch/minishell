/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleoma <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 22:04:12 by pleoma            #+#    #+#             */
/*   Updated: 2021/10/07 22:04:12 by pleoma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	coun_b;
	size_t	coun_l;

	coun_b = 0;
	coun_l = 0;
	if (*little == '\0')
		return ((char *)big);
	while (big[coun_b] != '\0')
	{
		if (big[coun_b] == little[0])
		{
			while ((big[coun_b + coun_l] == little[coun_l])
				&& (little[coun_l] != '\0') && (coun_b + coun_l < len))
				coun_l++;
			if (little[coun_l] == '\0')
				return ((char *)&big[coun_b]);
		}
		coun_b++;
	}
	return (NULL);
}
