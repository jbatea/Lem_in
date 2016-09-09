/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbateau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/01 11:22:50 by jbateau           #+#    #+#             */
/*   Updated: 2016/06/10 11:36:32 by jbateau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int			ft_count(int n)
{
	int		i;

	i = 0;
	if (n < 0)
	{
		n = -n;
		i++;
	}
	while (n >= 10)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char		*ft_limits(int n)
{
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	return (ft_strdup("2147483647"));
}

char		*ft_itoa(int n)
{
	char	*str;
	int		len;

	if (n == -2147483648 || n == 2147483647)
		return (ft_limits(n));
	len = ft_count(n);
	str = (char *)malloc(sizeof(char) * (len + 2));
	if (str == NULL)
		return (NULL);
	str[len + 1] = '\0';
	if (n < 0)
	{
		str[0] = '-';
		n = -n;
	}
	while (n >= 10)
	{
		str[len] = n % 10 + '0';
		n = n / 10;
		len--;
	}
	if (n < 10)
		str[len] = n + '0';
	return (str);
}
