/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoindel.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbateau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/07 11:39:04 by jbateau           #+#    #+#             */
/*   Updated: 2016/06/07 11:39:22 by jbateau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

char			*ft_strjoindel(char *s1, char const *s2)
{
	char		*scat;
	int			i;
	int			j;

	i = 0;
	j = 0;
	scat = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (scat == NULL)
		return (NULL);
	while (s1[i])
	{
		scat[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		scat[i] = s2[j];
		i++;
		j++;
	}
	scat[i] = '\0';
	ft_strdel(&s1);
	return (scat);
}
