/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_delfile.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbateau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/07 11:49:32 by jbateau           #+#    #+#             */
/*   Updated: 2016/06/07 11:49:59 by jbateau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int			ft_delfile(t_info *info)
{
	int		num;
	t_file	*tmp;

	num = -1;
	tmp = info->first;
	if (tmp)
	{
		num = tmp->num;
		info->first = tmp->next;
		free(tmp);
	}
	return (num);
}
