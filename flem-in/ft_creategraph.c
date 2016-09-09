/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_creategraph.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbateau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/04 15:58:04 by jbateau           #+#    #+#             */
/*   Updated: 2016/06/10 11:37:17 by jbateau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_adjnode	*ft_adjnode(int to)
{
	t_adjnode	*new;

	new = (t_adjnode *)malloc(sizeof(t_adjnode));
	if (!new)
		return (NULL);
	new->to = to;
	new->next = NULL;
	return (new);
}

void		ft_addpipe(t_info *info, int from, int to)
{
	t_adjnode	*new;

	new = ft_adjnode(to);
	if (!new)
		ft_exit(info, -1);
	new->next = info->array[from].head;
	info->array[from].head = new;
	new = ft_adjnode(from);
	new->next = info->array[to].head;
	info->array[to].head = new;
}

void		ft_addgraph(t_info *info)
{
	int		i;
	int		nbroom;

	i = 0;
	nbroom = ft_nbroom(info);
	info->array = (t_adjlst *)malloc(sizeof(t_adjlst) * nbroom);
	if (info->array)
	{
		while (i < nbroom)
		{
			info->array[i].head = NULL;
			i++;
		}
	}
}

void		ft_creategraph(t_info *info)
{
	t_room	*tmp;
	char	*to;
	char	*map;

	to = NULL;
	info->nbroom = ft_nbroom(info);
	ft_lastcheck(info);
	map = ft_savemap(info);
	ft_addgraph(info);
	tmp = info->room;
	while (tmp)
	{
		while ((to = ft_whichpipe(info, tmp->name)))
		{
			ft_addpipe(info, tmp->num, ft_rnum(info, to));
			ft_strdel(&to);
		}
		tmp = tmp->next;
	}
	ft_startinit(info, map);
	ft_printmap(info, map);
	ft_resolve(info);
	ft_exit(info, 1);
}
