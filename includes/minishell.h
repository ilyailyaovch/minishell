/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleoma <pleoma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 09:56:20 by pleoma            #+#    #+#             */
/*   Updated: 2022/05/03 14:21:46 by pleoma           ###   ########.fr       */
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

typedef struct s_child
{
	int		current;
	pid_t	pid;
	int		pipe[2][2];
	int		i;
	int		len;
}	t_child;

typedef struct s_dict
{
	char			*key;
	char			*value;
	struct s_dict	*next;
}	t_dict;

typedef struct s_cmd
{
	char			*name;
	char			**args;
	char			*i;
	t_dict			*infd;
	t_dict			*outfd;
	int				tmpfile;
	int				count;
	struct s_cmd	*next;
}	t_cmd;

typedef struct s_shell
{
	int		fd[3][2];
	int		status;
	char	*line;
	char	**envp;
	t_list	*list;
	t_cmd	*cmd;
}	t_shell;

/* one global var */
t_shell	g_shell;

/*	minishell.c */
void	ft_init_g_shell(void);
void	ft_readline(void);
void	minishell(void);

/*	utils1.c */
unsigned int	len_of_mass(char **mass);
void			ft_new_envp(char **envp);

/*	ft_free.c */
void	ft_free_mass(char **arr);

/*	ft_errors.c */
void	ft_error(char *argv, int exit_code);
void 	ft_shell_error(char *argv, int exit_code, int exit_flag);

/*	ft_parser.c */
void	ft_parser(void);

/*	ft_executor.c */
void	ft_executor(t_cmd *cmd);

/*	ft_signals.c */
void	shell_handler(int sig);
void	ft_signals(void);
void	ft_pipe_signals(void);


#endif