/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checknbant.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbateau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/30 06:55:32 by jbateau           #+#    #+#             */
/*   Updated: 2016/06/07 11:43:04 by jbateau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void			ft_outofnbant(long int res, int sign, t_info *info, char *s)
{
	if ((res * sign) <= 0 || (res * sign) > INT_MAX)
	{
		ft_strdel(&s);
		ft_exit(info, -1);
	}
}

int				ft_whichsign(char c)
{
	int			sign;

	sign = 1;
	if (c == '-')
		sign = -sign;
	return (sign);
}

int				ft_strtoi(char *str, t_info *info)
{
	int			i;
	long int	res;
	int			sign;
	char		*s;

	i = 0;
	res = 0;
	s = ft_strtrimall(str);
	sign = ft_whichsign(s[i]);
	if (s[i] == '-' || s[i] == '+')
		i++;
	while (s[i])
	{
		if (ft_isdigit(s[i]) == 0)
		{
			ft_strdel(&s);
			return (sign * res);
		}
		res = res * 10 + s[i] - '0';
		i++;
	}
	ft_strdel(&s);
	ft_outofnbant(res, sign, info, str);
	return (sign * res);
}

int				ft_checknbant(char *str, t_info *info)
{
	int			i;

	i = 0;
	if (str[i] == '+' || str[i] == '-')
		i++;
	if (*str == '\0' || (i == 1 && str[i] == '\0'))
	{
		ft_strdel(&str);
		ft_exit(info, -1);
	}
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
		{
			ft_strdel(&str);
			ft_exit(info, -1);
		}
		i++;
	}
	return (ft_strtoi(str, info));
}
