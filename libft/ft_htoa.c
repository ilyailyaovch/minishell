/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_htoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleoma <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 15:57:59 by pleoma            #+#    #+#             */
/*   Updated: 2021/11/10 15:57:59 by pleoma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_len(unsigned long long int n)
{
	unsigned int	len;

	len = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n /= 16;
		len++;
	}
	return (len);
}

char	*ft_htoa(unsigned long long int num, char *base)
{
	char			*str;
	unsigned int	len;

	len = ft_len(num);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	str[len] = '\0';
	len = len - 1;
	while (num >= 16)
	{
		str[len] = base[num % 16];
		num /= 16;
		len--;
	}
	str[len] = base[num % 16];
	return (str);
}
