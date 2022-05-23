/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dicts.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spzona <spzona@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 17:22:58 by spzona            #+#    #+#             */
/*   Updated: 2022/05/23 13:46:56 by spzona           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

t_dict	*ft_dictinit(char *key, char *value)
{
	t_dict	*res;

	res = malloc(sizeof(*res));
	if (!res)
		ft_error("ft_dictinit(): ", ENOMEM);
	res->next = NULL;
	res->key = ft_strdup(key);
	res->value = ft_strdup(value);
	return (res);
}

t_dict	*ft_dict_last(t_dict *lst)
{
	t_dict	*tmp;

	if (!lst)
		return (0);
	tmp = lst;
	while (tmp->next)
		tmp = tmp->next;
	return (tmp);
}

void	ft_dictadd_back(t_dict **lst, t_dict *new)
{
	if (!*lst)
		(*lst) = new;
	else
		ft_dict_last(*lst)->next = new;
}

void	ft_free_dict(t_dict *dict)
{
	t_dict	*tmp;

	tmp = dict;
	while (dict)
	{
		tmp = dict->next;
		free(dict->key);
		free(dict->value);
		free(dict);
		dict = tmp;
	}
}
