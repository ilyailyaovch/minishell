/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_cmd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleoma <pleoma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 17:23:26 by spzona            #+#    #+#             */
/*   Updated: 2022/05/05 14:20:28 by pleoma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

/*	func fills t_cmd with needed commands and 
	makes dict from special symbols	*/

void	ft_get_cmd(void)
{
	//t_list	*tmp_list;
	//t_cmd	*cmd;
	
	//md = g_shell.cmd;
	//tmp_list = g_shell.list;
	enum_cmd();
	// while (tmp_list)
	// {
	// 	//if tmp_line = |
	// 	//if tmp_line = redir
	// 	//else fill tmp_line->conrent
	// 	tmp_list = tmp_list->next;
	// }
	//printf("cmd doesn't work\n");
}