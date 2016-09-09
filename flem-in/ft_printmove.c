/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printmove.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbateau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/04 16:03:25 by jbateau           #+#    #+#             */
/*   Updated: 2016/06/08 16:34:52 by jbateau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		ft_printmove(int ant, t_room *room, char **str)
{
	char	*tmp;

	tmp = ft_itoa(ant);
	if (*str)
		*str = ft_strjoindel(*str, "L");
	else
		*str = ft_strdup("L");
	*str = ft_strjoindel(*str, tmp);
	ft_strdel(&tmp);
	*str = ft_strjoindel(*str, "-");
	*str = ft_strjoindel(*str, room->name);
}
