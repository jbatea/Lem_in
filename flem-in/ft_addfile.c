/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_addfile.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbateau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/07 11:39:50 by jbateau           #+#    #+#             */
/*   Updated: 2016/06/07 11:40:12 by jbateau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		ft_addfile(t_info *info, int num)
{
	t_file	*new;
	t_file	*tmp;

	tmp = NULL;
	new = (t_file *)malloc(sizeof(t_file));
	if (new)
	{
		new->num = num;
		new->next = NULL;
		if (info->first)
		{
			tmp = info->first;
			while (tmp->next)
				tmp = tmp->next;
			tmp->next = new;
		}
		else
			info->first = new;
	}
}
