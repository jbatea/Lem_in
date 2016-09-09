/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printmap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbateau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/07 11:57:04 by jbateau           #+#    #+#             */
/*   Updated: 2016/06/07 12:04:04 by jbateau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		ft_printmap(t_info *info, char *map)
{
	ft_putnbrl(info->nbant);
	ft_putendl(map);
	ft_strdel(&map);
}
