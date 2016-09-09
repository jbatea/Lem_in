/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isinfo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbateau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/30 06:56:50 by jbateau           #+#    #+#             */
/*   Updated: 2016/05/30 07:12:51 by jbateau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

char	*ft_isinfo(char *line)
{
	if (line[0] && line[0] == '#')
	{
		if (line[1] && line[1] == '#')
		{
			if (!ft_strcmp(line + 2, "start"))
				return (ft_strdup("start"));
			if (!ft_strcmp(line + 2, "end"))
				return (ft_strdup("end"));
		}
	}
	return (NULL);
}
