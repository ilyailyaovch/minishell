/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleoma <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 14:35:40 by pleoma            #+#    #+#             */
/*   Updated: 2021/10/08 14:35:40 by pleoma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	unsigned int	len;
	unsigned int	coun1;
	unsigned int	coun2;
	char			*dst;

	if (!s1 || !s2)
		return (NULL);
	coun1 = 0;
	coun2 = 0;
	len = ft_strlen((char *)s1) + ft_strlen((char *)s2) + 1;
	dst = (char *)malloc(len * sizeof(char));
	if (!dst)
		return (NULL);
	while (s1[coun1])
	{
		dst[coun1] = s1[coun1];
		coun1++;
	}
	while (s2[coun2])
	{
		dst[coun1 + coun2] = s2[coun2];
		coun2++;
	}
	dst[coun1 + coun2] = '\0';
	return (dst);
}
