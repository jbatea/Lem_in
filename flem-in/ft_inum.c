/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_inum.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbateau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/10 11:29:38 by jbateau           #+#    #+#             */
/*   Updated: 2016/06/10 11:29:45 by jbateau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int			ft_inum(t_info *info, char *str)
{
	t_room	*tmp;

	tmp = info->room;
	while (tmp)
	{
		if (tmp->info && !ft_strcmp(tmp->info, str))
			return (tmp->num);
		tmp = tmp->next;
	}
	return (-1);
}
