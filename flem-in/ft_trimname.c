/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_trimname.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbateau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/04 16:05:06 by jbateau           #+#    #+#             */
/*   Updated: 2016/06/04 16:05:28 by jbateau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		ft_trimname(t_info *info)
{
	t_room	*tmp;
	char	*str;

	str = NULL;
	tmp = info->room;
	while (tmp)
	{
		str = ft_fword(tmp->name);
		free(tmp->name);
		tmp->name = str;
		tmp = tmp->next;
	}
}
