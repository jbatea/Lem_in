/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isroom.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbateau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/30 06:54:15 by jbateau           #+#    #+#             */
/*   Updated: 2016/05/30 07:15:30 by jbateau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int			ft_iscoor(char *str)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	k = 0;
	if (str[i] && (str[i] == '-' || str[i] == '+'))
		i++;
	while (str[i] && ft_isdigit(str[i]))
		i++;
	if (str[i] && str[i] == ' ' && i != 0)
		j++;
	i++;
	if (str[i] && (str[i] == '-' || str[i] == '+'))
		i++;
	k = i;
	while (str[i] && ft_isdigit(str[i]))
		i++;
	if (!str[i])
		j++;
	if (i == k || j != 2)
		return (0);
	return (1);
}

int			ft_isroom(char *str)
{
	int		i;

	i = 0;
	if (str[i] && str[i] == '#')
		return (0);
	if (str[i] && str[i] == 'L')
		return (0);
	while (str[i] && str[i] != ' ')
		i++;
	if (str[i] && str[i] == ' ')
		i++;
	if (!str[i])
		return (0);
	if (!ft_iscoor(str + i))
		return (0);
	return (1);
}
