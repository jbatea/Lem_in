/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_antptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbateau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/07 14:44:11 by jbateau           #+#    #+#             */
/*   Updated: 2016/06/07 16:02:36 by jbateau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_room		*ft_antptr(t_info *info, int ant)
{
	t_room	*tmp;

	tmp = info->room;
	while (tmp)
	{
		if (ant == tmp->ant && !(tmp->info))
			return (tmp);
		tmp = tmp->next;
	}
	return (NULL);
}
