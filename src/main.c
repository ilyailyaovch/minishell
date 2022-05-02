/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleoma <pleoma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 09:58:12 by pleoma            #+#    #+#             */
/*   Updated: 2022/05/02 12:18:27 by pleoma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	main(int argc, char **argv, char **envp)
{	
	(void) envp;
	
	if (argc != 1)
		ft_error(argv[0], EINVAL);
	//ft_new_envp(envp);
	
	// try gnl //
	int fd;
	fd = open("/Users/pleoma/minishell/src/file", O_RDONLY);
	printf ("file descriptor: %d\n", fd);
	char *line = get_next_line(fd);
	printf("%s\n", line);
	
	minishell();
	return (0);
}
