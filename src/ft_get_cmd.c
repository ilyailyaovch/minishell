/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_cmd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spzona <spzona@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 17:23:26 by spzona            #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2022/05/05 14:49:44 by spzona           ###   ########.fr       */
=======
/*   Updated: 2022/05/05 15:55:17 by pleoma           ###   ########.fr       */
>>>>>>> 96a6e000525235b73e4304a956b760de0e6de5d6
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

/*	func fills t_cmd with needed commands and 
	makes dict from special symbols	*/

void	ft_get_cmd(void)
{
	t_list	*tmp_list;
	t_cmd	*cmd;
	
	cmd = g_shell.cmd;
	tmp_list = g_shell.list;
	while (tmp_list)
	{
		if (is_pipe(tmp_list) == false)
		{
			ft_cmdadd_back(&g_shell.cmd, ft_cmdnew());
			//count_cmd(tmp_list); //1
		}
		while (tmp_list && (is_pipe(tmp_list) == false))
		{
			if (is_redir(tmp_list) == true)
			{
				//fill_redirect(); //1
				tmp_list = tmp_list->next;
			}
			else
				//fill_argument(); //2
			tmp_list = tmp_list->next;
		}
		if (tmp_list)
			tmp_list = tmp_list->next;
	}
	enum_cmd();
<<<<<<< HEAD
	// while (tmp_list)
	// {
	// 	//if tmp_line = |
	// 	//if tmp_line = redir
	// 	//else fill tmp_line->conrent
	// 	tmp_list = tmp_list->next;
	// }
	//printf("cmd doesn't work\n");
}
=======
}
>>>>>>> 96a6e000525235b73e4304a956b760de0e6de5d6
