/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bins_cd_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spzona <spzona@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 11:17:16 by pleoma            #+#    #+#             */
/*   Updated: 2022/05/23 13:01:52 by spzona           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static void	if_checks(int j, int i, char *args, char *str)
{
	if (j == 1 && i)
		chdir(str);
	else if (j != 1)
	{
		ft_shell_error("minishell: cd: ", 0, 0);
		ft_shell_error(args, 0, 0);
		ft_shell_error(": No such file or directory\n", 1, 0);
	}
	else if (j == 1 && !i)
	{
		ft_shell_error("minishell: cd: ", 0, 0);
		ft_shell_error(args, 0, 0);
		ft_shell_error(": Not a directory\n", 1, 0);
	}
}

void	inside_validpath(char *str, int j, char *old_path, char *args)
{
	DIR				*dir;
	struct dirent	*entry;
	struct stat		status;
	int				ifcd;
	int				i;

	ifcd = j;
	entry = NULL;
	dir = opendir("./");
	entry = readdir(dir);
	j = 0;
	while (entry != NULL)
	{
		if (ft_strncmp(str, entry->d_name, ft_strlen(entry->d_name)) == 0)
		{
			stat(str, &status);
			j = 1;
		}
		entry = readdir(dir);
	}
	closedir(dir);
	i = S_ISDIR(status.st_mode);
	if_checks(j, i, args, str);
	if ((j != 1 || !i) || !ifcd)
		chdir(old_path);
}

void	validpath(char *args, char *old_path, int ifcd)
{
	char	**str;
	int		i;
	int		j;

	j = 0;
	i = ft_strlen(args);
	while (args[j] && args[j] != '/' )
		j++;
	if (j != i)
		str = ft_split(args, '/');
	else
		str = ft_split(args, '\0');
	i = 0;
	while (str[i])
	{
		j = ifcd;
		inside_validpath(str[i], j, old_path, args);
		i++;
	}
	ft_free_mass(str);
}
