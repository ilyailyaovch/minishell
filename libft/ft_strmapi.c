/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleoma <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 12:16:42 by pleoma            #+#    #+#             */
/*   Updated: 2021/10/09 12:16:42 by pleoma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	coun;
	char			*rez;

	coun = 0;
	if (!s || !f)
		return (NULL);
	rez = (char *)malloc(sizeof(char) * (ft_strlen((char *)s) + 1));
	if (!rez)
		return (NULL);
	while (s[coun])
	{
		rez[coun] = f(coun, s[coun]);
		coun++;
	}
	rez[coun] = '\0';
	return (rez);
}
