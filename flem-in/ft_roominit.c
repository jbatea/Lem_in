/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_roominit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbateau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/26 17:58:21 by jbateau           #+#    #+#             */
/*   Updated: 2016/06/07 11:41:45 by jbateau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_room		*ft_roominit(void)
{
	t_room	*new;

	new = (t_room *)malloc(sizeof(t_room));
	if (!new)
		return (NULL);
	new->name = NULL;
	new->num = 0;
	new->ant = 0;
	new->weight = -1;
	new->info = NULL;
	new->next = NULL;
	return (new);
}
