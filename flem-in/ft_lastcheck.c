/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lastcheck.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbateau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/04 15:46:38 by jbateau           #+#    #+#             */
/*   Updated: 2016/06/04 15:47:10 by jbateau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		ft_lastcheck(t_info *info)
{
	if (info->nbroom < 1)
		ft_exit(info, -1);
	if (!ft_checkinfo(info))
		ft_exit(info, -1);
	if (!ft_lenpipe(info))
		ft_exit(info, -1);
}
