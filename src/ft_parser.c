/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleoma <pleoma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 14:08:32 by spzona            #+#    #+#             */
/*   Updated: 2022/05/03 14:50:28 by pleoma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static char	*ft_separator(int *i, char c)
{
	char	*tmp;

	(void) i;
	tmp = malloc(sizeof(char) * 2);
	if (!tmp)
		return (0);
	tmp[0] = c;
	tmp[1] = '\0';
	return (tmp);	
}

static int	ft_quotes(int *i)
{
	int j;

	j = 0;
	while (j < *i)
	{
		if (g_shell.line[j] == '\'')
		{
			j++;
			while (j < *i && g_shell.line[j] != '\'')
				j++;
			if (j == *i)
				return (1);
		}
		if (g_shell.line[j] == '"')
		{
			j++;
			while (j < *i && g_shell.line[j] != '"')
				j++;
			if (j == *i)
				return (1);	
		}
		j++;
	}
	return (0);
}	

static char	*ft_pivot(int *i, char *redir)
{
	char	*tmp;

	tmp = malloc(sizeof(char) * 3);
	if (!tmp)
		return (0);
	tmp[0] = redir[0];
	tmp[1] = redir[1];
	tmp[2] = redir[2];
	(*i)++;
	return (tmp);
}

static char	*ft_str(int *i)
{
	int		j;
	char	*tmp;

	j = 0;
	if (!ft_strlen(g_shell.line + (*i)))
		return (0);
	tmp = malloc(sizeof(char) * (ft_strlen(g_shell.line + (*i)) + 1));
	if (!tmp)
		return (0);
	while (!ft_strchr(" |<>\0", g_shell.line[(*i)]) || ft_quotes(i))
	{
		tmp[j] = g_shell.line[(*i)];
		j++;
		(*i)++;
	}
	tmp[j] = '\0';
	(*i)--;
	return (tmp);
}

void	ft_parser(void)
{
	int	i;

	i = 0;
	while (g_shell.line[i] != '\0')
	{
		while (g_shell.line[i] != '\0' && (g_shell.line[i] == ' ' || g_shell.line[i] == '\t'
			|| g_shell.line[i] == '\v' || g_shell.line[i] == '\f' || g_shell.line[i] == '\r'))
			i++;
		if (!ft_strncmp(g_shell.line + i, ">>", 2))
			ft_lstadd_back(&g_shell.list, ft_lstnew((void *)ft_pivot(&i, ">>")));
		else if (!ft_strncmp(g_shell.line + i, "<<", 2))
			ft_lstadd_back(&g_shell.list, ft_lstnew((void *)ft_pivot(&i, "<<")));
		else if (!ft_strncmp(g_shell.line + i, ">", 2))
			ft_lstadd_back(&g_shell.list, ft_lstnew((void *)ft_separator(&i, '>')));
		else if (!ft_strncmp(g_shell.line + i, "<", 2))
			ft_lstadd_back(&g_shell.list, ft_lstnew((void *)ft_separator(&i, '<')));
		else if (!ft_strncmp(g_shell.line + i, "|", 2))
			ft_lstadd_back(&g_shell.list, ft_lstnew((void *)ft_separator(&i, '|')));
		else if (!ft_strncmp(g_shell.line + i, "|", 2))
			ft_lstadd_back(&g_shell.list, ft_lstnew((void *)ft_str(&i)));
		i++;
	}
}