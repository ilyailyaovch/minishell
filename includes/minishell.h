/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleoma <pleoma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 09:56:20 by pleoma            #+#    #+#             */
/*   Updated: 2022/04/18 13:12:58 by pleoma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <errno.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>

# include "../readline/tilde.h"
# include "../readline/rlconf.h"
# include "../readline/rlstdc.h"
# include "../readline/history.h"
# include "../readline/keymaps.h"
# include "../readline/readline.h"
# include "../readline/chardefs.h"
# include "../readline/rltypedefs.h"

# include "../libft/libft.h"

# define RED "\033[0;31m"
# define GREEN "\033[0;32m"
# define BLUE "\033[0;34m"
# define YELW "\033[1;33m"
# define WTH "\033[0;37m"

# define EXIT_FLAG 1

//	minishell.c //
void	minishell(void);

//	ft_errors.c //
void	ft_error(char *argv, int exit_code);
void 	ft_shell_error(char *argv, int exit_code, int exit_flag);


#endif