/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_infoinit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbateau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/26 18:00:01 by jbateau           #+#    #+#             */
/*   Updated: 2016/06/07 11:48:21 by jbateau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_info		*ft_infoinit(void)
{
	t_info	*new;

	new = (t_info *)malloc(sizeof(t_info));
	if (!new)
		return (NULL);
	new->nbant = 0;
	new->curant = 1;
	new->nbroom = 0;
	new->room = NULL;
	new->pipe = NULL;
	new->array = NULL;
	new->first = NULL;
	return (new);
}
