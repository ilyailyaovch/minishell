/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleoma <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 22:04:16 by pleoma            #+#    #+#             */
/*   Updated: 2021/10/07 22:04:16 by pleoma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int ch)
{
	int	coun;

	coun = ft_strlen((char *)str);
	while (coun >= 0)
	{
		if (*(str + coun) == (unsigned char)ch)
			return ((char *)(str + coun));
		coun--;
	}
	return (NULL);
}
