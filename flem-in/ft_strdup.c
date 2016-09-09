/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbateau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 17:09:24 by jbateau           #+#    #+#             */
/*   Updated: 2016/05/30 07:18:08 by jbateau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

char		*ft_strdup(const char *s1)
{
	char	*str;

	if (s1)
	{
		str = (char *)malloc(sizeof(char) * (ft_strlen(s1) + 1));
		if (str == NULL)
			return (NULL);
		return (ft_strcpy(str, s1));
	}
	return (NULL);
}
