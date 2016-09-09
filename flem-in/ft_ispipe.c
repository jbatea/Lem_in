/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ispipe.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbateau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/30 06:56:59 by jbateau           #+#    #+#             */
/*   Updated: 2016/05/30 07:14:51 by jbateau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int			ft_checkname(char *name, t_info *info)
{
	t_room	*tmp;
	char	*fword;

	tmp = info->room;
	while (tmp)
	{
		fword = ft_fword(tmp->name);
		if (!ft_strcmp(name, fword))
		{
			ft_strdel(&name);
			ft_strdel(&fword);
			return (1);
		}
		ft_strdel(&fword);
		tmp = tmp->next;
	}
	ft_strdel(&name);
	return (0);
}

int			ft_ispipe(char *str, t_info *info)
{
	int		i;

	i = 0;
	while (str[i] && str[i] != '-')
		i++;
	if (str[i] && i == 0)
		return (0);
	if (!str[i])
		return (0);
	if (!ft_checkname(ft_strndup(str, i), info))
		return (0);
	if (!ft_checkname(ft_strndup(str + i + 1, ft_strlen(str) - i), info))
		return (0);
	return (1);
}
