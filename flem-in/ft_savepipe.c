/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_savepipe.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbateau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/04 15:47:36 by jbateau           #+#    #+#             */
/*   Updated: 2016/06/04 15:48:51 by jbateau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int			ft_strcmppipe(t_pipe *pipe, char *from, char *to)
{
	if (!ft_strcmp(from, pipe->from) && !ft_strcmp(to, pipe->to))
		return (1);
	if (!ft_strcmp(from, pipe->to) && !ft_strcmp(to, pipe->from))
		return (1);
	return (0);
}

int			ft_checkduppipe(t_info *info, char *from, char *to)
{
	t_pipe	*tmp;

	tmp = info->pipe;
	while (tmp)
	{
		if (ft_strcmppipe(tmp, from, to))
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

void		ft_savepipe(t_info *info, char *from, char *to)
{
	t_pipe	*tmp;
	t_pipe	*new;

	if (!ft_checkduppipe(info, from, to))
	{
		tmp = info->pipe;
		new = ft_pipeinit();
		new->from = ft_strdup(from);
		new->to = ft_strdup(to);
		new->next = NULL;
		if (new)
		{
			if (!(info->pipe))
				info->pipe = new;
			else
			{
				while (tmp->next)
					tmp = tmp->next;
				tmp->next = new;
			}
		}
	}
	ft_strdel(&from);
	ft_strdel(&to);
}
