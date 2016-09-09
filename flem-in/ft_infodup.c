/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_infodup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbateau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/30 06:56:19 by jbateau           #+#    #+#             */
/*   Updated: 2016/05/30 07:19:24 by jbateau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int			ft_infodup(char *line, t_info *info)
{
	t_room	*tmp;

	tmp = info->room;
	while (tmp)
	{
		if (tmp->info && !ft_strcmp(line, tmp->info))
			return (1);
		tmp = tmp->next;
	}
	return (0);
}
