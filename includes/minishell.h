/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleoma <pleoma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 09:56:20 by pleoma            #+#    #+#             */
/*   Updated: 2022/04/17 19:44:59 by pleoma           ###   ########.fr       */
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


# define RED "\033[0;31m"
# define GREEN "\033[0;32m"
# define BLUE "\033[0;34m"
# define YELW "\033[1;33m"
# define WTH "\033[0;37m"

//	minishell.c //
void	ft_error(int exit_code, char *argv);
void	minishell(void);

#endif