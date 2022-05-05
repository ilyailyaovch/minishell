/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_cmd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleoma <pleoma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 17:23:26 by spzona            #+#    #+#             */
/*   Updated: 2022/05/05 18:22:44 by pleoma           ###   ########.fr       */
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
}