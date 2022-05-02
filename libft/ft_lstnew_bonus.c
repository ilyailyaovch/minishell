/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleoma <pleoma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 11:28:40 by pleoma            #+#    #+#             */
/*   Updated: 2022/05/02 10:00:23 by pleoma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*res;

	if (!content)
		return (0);
	res = malloc(sizeof(*res));
	if (!res)
		return (0);
	res->content = content;
	res->next = NULL;
	return (res);
}
