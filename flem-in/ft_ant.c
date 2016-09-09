/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ant.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbateau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/04 16:09:45 by jbateau           #+#    #+#             */
/*   Updated: 2016/06/04 16:10:59 by jbateau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		ft_ant(t_info *info)
{
	char	*line;

	if (get_next_line(0, &line) == 1)
	{
		info->nbant = ft_checknbant(line, info);
		free(line);
	}
}
