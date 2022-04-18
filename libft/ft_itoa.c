/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleoma <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 21:56:28 by pleoma            #+#    #+#             */
/*   Updated: 2021/10/08 21:56:28 by pleoma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_len(int n)
{
	int	len;

	if (n <= 0)
		len = 1;
	else
		len = 0;
	while (n != 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

static int	ft_sign(int n)
{
	int	sign;

	if (n < 0)
		sign = -1;
	else
		sign = 1;
	return (sign);
}

static unsigned int	ft_abs(int n)
{
	unsigned int	abs;

	if (n < 0)
		abs = -n;
	else
		abs = n;
	return (abs);
}

char	*ft_itoa(int n)
{
	char			*str;
	int				len;
	int				sign;
	unsigned int	abs;

	sign = ft_sign(n);
	abs = ft_abs(n);
	len = ft_len(n);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	str[len] = '\0';
	len = len - 1;
	if (sign < 0)
		str[0] = '-';
	while (abs >= 10)
	{
		str[len] = abs % 10 + '0';
		abs /= 10;
		len--;
	}
	str[len] = abs % 10 + '0';
	return (str);
}
