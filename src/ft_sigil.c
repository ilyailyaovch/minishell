/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sigil.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleoma <pleoma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 14:44:13 by spzona            #+#    #+#             */
/*   Updated: 2022/05/05 13:48:41 by pleoma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static char	*find_var(char **envp, char *line, int len)
{
	char	*name;
	int		j;

	name = malloc(sizeof(char) * len);
	if (!name)
		return (0);
	ft_strlcpy(name, line, len);
	j = -1;
	while (envp[++j])
	{
		if (!ft_strncmp(name, envp[j],
				max(ft_len_before_eq(envp[j]), ft_strlen(name))))
		{
			free(name);
			name = ft_strdup(envp[j] + ft_len_before_eq(envp[j]) + 1);
			return (name);
		}
	}
	if (!ft_strncmp("?", name, 1))
	{
		free(name);
		return (ft_itoa(g_shell.status));
	}
	free(name);
	return (NULL);
}

static void	replace_var(int start, int len, char *name, int *i)
{
	int		j;
	char	*new;
	int		lenname;

	j = 0;
	lenname = 0;
	if (name)
		lenname = ft_strlen(name);
	new = malloc(sizeof(char) * (ft_strlen(g_shell.line) + lenname));
	if (!new)
		return ;
	ft_strlcpy(new, g_shell.line, start + 1);
	if (name)
		ft_strlcpy(new + start, name, ft_strlen(name) + 1);
	ft_strlcpy(new + start + lenname, g_shell.line + start + len,
		ft_strlen(g_shell.line + start + len) + 1);
	free(g_shell.line);
	g_shell.line = ft_strdup(new);
	(*i) = start;
	free(new);
	if (name)
		free(name);
}

static void	process_var(int *i, char **envp)
{
	int		count;
	char	*name;

	count = 0;
	(*i)++;
	if (ft_isdigit(*(g_shell.line + (*i))) || *(g_shell.line + (*i)) == '?')
	{
		count = 1;
		(*i)++;
	}
	else
	{
		while (*(g_shell.line + (*i)) != '\0' && (*(g_shell.line + (*i)) == '_'
				|| ft_isdigit(*(g_shell.line + (*i)))
				|| ft_isalpha(*(g_shell.line + (*i)))))
		{
			(*i)++;
			count++;
		}
	}
	name = find_var(envp, g_shell.line + ((*i) - count), count + 1);
	replace_var((*i) - count - 1, count + 1, name, i);
}

/*	finds name of the global var and replaces it after $
	doesn't work with new global vars	*/

void	ft_sigil(void)
{
	int		coun;
	int		quot1;
	int		qout2;

	coun = 0;
	quot1 = 0;
	qout2 = 0;
	while (g_shell.line[coun] != '\0')
	{
		if (g_shell.line[coun] == '"' && quot1 % 2 == 0)
			qout2++;
		if (g_shell.line[coun] == '\'')
			quot1++;
		if ((quot1 % 2 == 0 || qout2 % 2 == 1) && g_shell.line[coun] == '$')
			process_var(&coun, g_shell.envp);
		else
			coun++;
	}
}
