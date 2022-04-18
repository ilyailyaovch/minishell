/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleoma <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 12:40:52 by pleoma            #+#    #+#             */
/*   Updated: 2021/10/09 12:40:52 by pleoma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	unsigned int	coun;

	coun = 0;
	if (!s)
		return ;
	while (s[coun])
	{
		ft_putchar_fd(s[coun], fd);
		coun++;
	}
}
