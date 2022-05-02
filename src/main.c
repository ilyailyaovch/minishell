/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleoma <pleoma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 09:58:12 by pleoma            #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2022/05/02 16:14:59 by pleoma           ###   ########.fr       */
=======
/*   Updated: 2022/05/02 13:49:19 by pleoma           ###   ########.fr       */
>>>>>>> 6ed10b9d91b59b76dbc49e67ae50f7e674cbeffd
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	main(int argc, char **argv, char **envp)
{	
<<<<<<< HEAD
	if (argc != 1)
		ft_error(argv[0], EINVAL);
	ft_new_envp(envp);
	minishell();
	ft_free_mass(g_shell.envp);
=======
	(void) envp;
	
	if (argc != 1)
		ft_error(argv[0], EINVAL);
	//ft_new_envp(envp);
	
	/*	try gnl */
	int fd;
	fd = open("/Users/pleoma/minishell/src/file", O_RDONLY);
	printf ("file descriptor: %d\n", fd);
	char *line = get_next_line(fd);
	printf("%s\n", line);
	
	minishell();
>>>>>>> 6ed10b9d91b59b76dbc49e67ae50f7e674cbeffd
	return (0);
}
