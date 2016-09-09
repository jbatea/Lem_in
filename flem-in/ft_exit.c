/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbateau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/27 18:44:21 by jbateau           #+#    #+#             */
/*   Updated: 2016/06/10 11:37:03 by jbateau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		ft_roomfree(t_room *room)
{
	t_room	*tmp;
	t_room	*ptmp;

	tmp = room;
	while (tmp)
	{
		ptmp = tmp->next;
		ft_strdel(&(tmp->name));
		if (tmp->info)
			ft_strdel(&(tmp->info));
		free(tmp);
		tmp = ptmp;
	}
}

void		ft_pipefree(t_pipe *pipe)
{
	t_pipe	*tmp;
	t_pipe	*ptmp;

	tmp = pipe;
	while (tmp)
	{
		ptmp = tmp->next;
		ft_strdel(&(tmp->from));
		ft_strdel(&(tmp->to));
		free(tmp);
		tmp = ptmp;
	}
}

void		ft_graphfree(t_info *info)
{
	int			i;
	t_adjnode	*tmp;
	t_adjnode	*ptmp;

	i = 0;
	tmp = NULL;
	ptmp = NULL;
	if (info->array)
	{
		while (i < info->nbroom)
		{
			tmp = info->array[i].head;
			while (tmp)
			{
				ptmp = tmp->next;
				free(tmp);
				tmp = ptmp;
			}
			i++;
		}
		free(info->array);
	}
}

void		ft_exit(t_info *info, int i)
{
	if (i == -1)
		ft_putendl("ERROR");
	ft_graphfree(info);
	ft_roomfree(info->room);
	ft_pipefree(info->pipe);
	free(info);
	exit(1);
}
