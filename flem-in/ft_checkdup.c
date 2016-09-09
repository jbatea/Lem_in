/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkdup.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbateau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/30 06:55:04 by jbateau           #+#    #+#             */
/*   Updated: 2016/05/30 07:15:16 by jbateau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

char		*ft_spart(char *str)
{
	int		i;

	i = 0;
	while (str[i] && str[i] != ' ')
		i++;
	return (str + i + 1);
}

int			ft_strcmpcoord(char *line, char *name)
{
	if (!ft_strcmp(ft_spart(line), ft_spart(name)))
		return (1);
	return (0);
}

int			ft_dupcoord(char *line, t_info *info)
{
	t_room	*tmp;

	tmp = info->room;
	while (tmp)
	{
		if (ft_strcmpcoord(line, tmp->name))
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

int			ft_dupname(char *line, t_info *info)
{
	t_room	*tmp;
	char	*fword;
	char	*fname;

	tmp = info->room;
	while (tmp)
	{
		fword = ft_fword(line);
		fname = ft_fword(tmp->name);
		if (!ft_strcmp(fword, fname))
		{
			ft_strdel(&fname);
			ft_strdel(&fword);
			return (1);
		}
		ft_strdel(&fname);
		ft_strdel(&fword);
		tmp = tmp->next;
	}
	return (0);
}

int			ft_checkdup(char *line, t_info *info)
{
	if (ft_dupname(line, info))
		return (1);
	if (ft_dupcoord(line, info))
		return (1);
	return (0);
}
