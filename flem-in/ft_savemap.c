/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_savemap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbateau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/07 11:56:36 by jbateau           #+#    #+#             */
/*   Updated: 2016/06/07 11:56:48 by jbateau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

char		*ft_printroom(t_info *info)
{
	t_room	*tmp;
	char	*map;

	map = NULL;
	tmp = info->room;
	while (tmp)
	{
		if (tmp->info)
		{
			if (!map)
				map = ft_strdup("##");
			else
				map = ft_strjoindel(map, "##");
			map = ft_strjoindel(map, tmp->info);
			map = ft_strjoindel(map, "\n");
		}
		if (!map)
			map = ft_strdup(tmp->name);
		else
			map = ft_strjoindel(map, tmp->name);
		map = ft_strjoindel(map, "\n");
		tmp = tmp->next;
	}
	return (map);
}

char		*ft_printpipe(t_pipe *pipe, char *map)
{
	t_pipe	*tmp;

	if (pipe && pipe->from)
	{
		tmp = pipe;
		while (tmp)
		{
			if (tmp->from)
				map = ft_strjoindel(map, tmp->from);
			map = ft_strjoindel(map, "-");
			if (tmp->to)
			{
				map = ft_strjoindel(map, tmp->to);
				map = ft_strjoindel(map, "\n");
			}
			tmp = tmp->next;
		}
	}
	return (map);
}

char		*ft_savemap(t_info *info)
{
	char	*map;

	map = ft_printroom(info);
	map = ft_printpipe(info->pipe, map);
	ft_trimname(info);
	return (map);
}
