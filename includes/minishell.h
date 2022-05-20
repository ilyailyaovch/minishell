/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Arbiter <Arbiter@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 09:56:20 by pleoma            #+#    #+#             */
/*   Updated: 2022/05/20 20:54:11 by Arbiter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <errno.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>
# include <dirent.h>
# include <signal.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <string.h>

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

/*	ft_init.c */
void	ft_new_envp(char **envp);

/*	ft_free.c */
void	ft_free_all(void);
void	ft_free_mass(char **arr);
void	ft_free_list(t_list *a);

/*	ft_errors.c */
void	ft_error(char *argv, int exit_code);
void 	ft_shell_error(char *argv, int exit_code, int exit_flag);
void	ft_errmsg(char *s1, char *s2, char *s3, int code);

/*	ft_parser.c */
void	ft_parser(void);

/*	ft_get_cmd.c */
void	count_cmd(t_list *list);
void	ft_get_cmd(void);

/*	ft_get_cmd_2.c */
bool 	is_pipe(t_list	*tmp);
bool 	is_redir(t_list	*tmp);
void	enum_cmd(void);
void	fill_redirect(char *redir, char *file);
void	fill_argument(void *content);


/*	ft_signals.c */
void	shell_handler(int sig);
void	ft_signals(void);
void	ft_pipe_signals(void);

/*	ft_quotes_pipes.c */
int		ft_one_pipe(void);
int		check_first_pipe(void);
int		check_quotes(void);
int		check_quotes_pipe(void);

/*	ft_quotes_remove.c */
void	ft_remove_extra_quotes(void);

/*	ft_sigil.c */
void	ft_sigil(void);

/*	ft_utils1.c */
int			max(int a, int b);
int			ft_len_before_eq(char *str);
int			arr_size(char **envp);
void		ifs(int j, int i, char *args, char *str);
void		ft_free(char **mass);

/*	ft_cmds.c */
t_cmd	*ft_cmdinit(void);
int		ft_cmdlen(t_cmd *cmd);
void	ft_free_cmd(t_cmd *cmd);
t_cmd	*ft_cmd_last(t_cmd *lst);
void	ft_cmdadd_back(t_cmd **lst,t_cmd *new);

/*	ft_dicts.c */
t_dict	*ft_dictinit(char *key, char *value);
t_dict	*ft_dict_last(t_dict *lst);
void	ft_free_dict(t_dict *dict);
void	ft_dictadd_back(t_dict **lst, t_dict *new);

/*	put_envp.c */
char	**put_envp(char **envp, char *str, int free_flag);

/*	ft_executor.c */
void	ft_executor(t_cmd *cmd);
void	check_cd(t_cmd *cmd, int n);

/*	ft_executor_2.c */
void	check_exit(t_cmd *cmd);
void	collect_variables(void);
void	get_variables(void);

/*	ft_exec_children.c */
void	ft_init_child(t_child *child, t_cmd *cmd);
void	child_process(t_child *child, t_cmd *cmd, int len);
void	wait_children(int n);
void	ft_execute(t_cmd *cmd);

/*	ft_execute.c */
void	ft_execute(t_cmd *cmd);

/*	ft_redir_heredoc.c*/
void	redirect_out(t_cmd *cmd);
void	redirect_in(t_cmd *cmd);
char	*heredoc(char *delim);
void	tmp_heredoc_file(char *delim, t_cmd *cmd);
void	ft_init_heredoc_instd(t_cmd *cmd);

/*	ft_bins.c */
void	ft_exit(t_cmd *cmd);
void	ft_echo(t_cmd *cmd);
void	ft_pwd(void);
void	ft_env(void);

/*	ft_bins_unset.c */
char	**ft_unset(char **args, char **envp);
int	check_unset(char *args, char **envp);

/*	ft_bins_export.c */
char	**replace_envp_el(char **envp, char *args, char *new);
char	**export_envp(char **envp, char *str, int free);
int		ft_sym_export(char *str);

/*	ft_bins_cd.c */
void	inside_validpath(char *str, int j, char *old_path, char *args);
void	validpath(char *args, char *old_path, int ifcd);
char	**cd_oldpwd(char *old_path);
char	*ft_strchr_for_mini(const char *s, int c);
char	**ft_cd(char **args, int ifcd);



#endif