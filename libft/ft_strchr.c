/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleoma <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 22:03:39 by pleoma            #+#    #+#             */
/*   Updated: 2021/10/07 22:03:39 by pleoma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int ch)
{	
	unsigned char	coun;

	coun = 0;
	while (str[coun] != '\0')
	{
		if (str[coun] == (unsigned char)ch)
			return ((char *)str + coun);
		else
			coun++;
	}
	if (str[coun] == (unsigned char)ch)
		return ((char *)str + coun);
	return (NULL);
}
