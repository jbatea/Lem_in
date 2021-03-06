/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_to.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbateau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/30 06:56:01 by jbateau           #+#    #+#             */
/*   Updated: 2016/05/30 07:16:13 by jbateau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

char		*ft_to(char *line)
{
	int		i;

	i = 0;
	while (line[i] && line[i] != '-')
		i++;
	i++;
	return (ft_strndup(line + i, ft_strlen(line) - i));
}
