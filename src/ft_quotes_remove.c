/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quotes_remove.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleoma <pleoma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 10:42:13 by pleoma            #+#    #+#             */
/*   Updated: 2022/05/04 14:40:39 by pleoma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static char	*manage_quotes(char q, int *i, char *line)
{
	int		start;
	char	*tmp;

	start = (*i);
	(*i)++;
	while (line[(*i)] != q && line[(*i)] != '\0')
		(*i)++;
	tmp = malloc(sizeof(char) * (ft_strlen(line) - 1));
	if (!tmp)
		return (0);
	ft_strlcpy(tmp, line, start + 1);
	ft_strlcpy(tmp + start, line + start + 1, (*i) - start);
	ft_strlcpy(tmp + (*i) - 1, line + (*i) + 1, ft_strlen(line)
		- (*i));
	if (line)
		free(line);
	line = ft_strdup(tmp);
	free(tmp);
	(*i)--;
	return (line);
}

static char	*rm_quotes(void *content)
{
	int		i;
	char	*line;

	i = 0;
	line = (char *)content;
	while (line[i] != '\0')
	{
		if (line[i] == '"' || line[i] == '\'')
			line = manage_quotes(line[i], &i, line);
		else
			i++;
		if (!line)
			return (0);
	}
	return (line);
}

void	ft_remove_extra_quotes(void)
{
	t_list	*tmp;

	tmp = g_shell.list;
	while (tmp)
	{
		tmp->content = (void *)rm_quotes(tmp->content);
		tmp = tmp->next;
	}
	//free(tmp);	//?
}