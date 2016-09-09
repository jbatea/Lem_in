/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_roomptr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbateau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/07 11:40:31 by jbateau           #+#    #+#             */
/*   Updated: 2016/06/07 11:41:00 by jbateau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_room		*ft_roomptr(t_info *info, int num)
{
	t_room	*tmp;

	tmp = info->room;
	while (tmp && (tmp->num != num))
		tmp = tmp->next;
	return (tmp);
}
