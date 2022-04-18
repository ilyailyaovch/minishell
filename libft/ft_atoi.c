/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleoma <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 22:03:02 by pleoma            #+#    #+#             */
/*   Updated: 2021/10/07 22:03:02 by pleoma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{	
	int		sign;
	int		sbl;
	long	number;

	sign = 1;
	sbl = 0;
	number = 0;
	while (((str[sbl] >= 9) && (str[sbl] <= 13)) || (str[sbl] == ' '))
		sbl++;
	if ((str[sbl] == '-') || (str[sbl] == '+'))
	{
		if (str[sbl] == '-')
			sign *= (-1);
		sbl++;
	}
	while ((str[sbl] >= '0') && (str[sbl] <= '9'))
	{
		number = (number * 10) + (str[sbl] - '0');
		if (number > 2147483647 && sign == 1)
			return (-1);
		if (number > 2147483648 && sign == -1)
			return (0);
		sbl++;
	}
	return (sign * number);
}
