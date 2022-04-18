/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleoma <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 22:04:00 by pleoma            #+#    #+#             */
/*   Updated: 2021/10/07 22:04:00 by pleoma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *str1, const char *str2, size_t num)
{
	size_t			coun;
	unsigned char	*s1;
	unsigned char	*s2;

	s1 = (unsigned char *)str1;
	s2 = (unsigned char *)str2;
	coun = 0;
	while (num--)
	{
		if (s1[coun] != s2[coun] || s1[coun] == '\0' || s2[coun] == '\0')
			return (s1[coun] - s2[coun]);
		coun++;
	}
	return (0);
}
