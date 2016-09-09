/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrimall.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbateau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/12 11:15:50 by jbateau           #+#    #+#             */
/*   Updated: 2016/05/30 07:16:53 by jbateau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

char		*ft_strtrimall(char const *s)
{
	char	*strim;
	int		i;
	int		len;
	int		j;

	i = 0;
	j = 0;
	len = ft_strlen(s) - 1;
	while ((s[i] == ' ' || s[i] == '\n' || s[i] == '\t' || s[i] == '\v' ||
				s[i] == '\r' || s[i] == '\f') && s[i])
		i++;
	if (s[i] != '\0')
		while ((s[len] == ' ' || s[len] == '\n' || s[len] == '\t' || s[len]
					== '\v' || s[len] == '\r' || s[len] == '\f') && (len > 0))
			len--;
	if (!(strim = (char *)malloc(sizeof(char) * ((len - i) + 2))))
		return (NULL);
	while (i < (len + 1) && s[i])
	{
		strim[j] = s[i];
		i++;
		j++;
	}
	strim[j] = '\0';
	return (strim);
}
