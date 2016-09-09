/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr_cnt.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbateau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/07 18:34:14 by jbateau           #+#    #+#             */
/*   Updated: 2016/05/30 07:17:15 by jbateau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_strchr_cnt(char *s, char c)
{
	int cnt;

	cnt = 0;
	while (s[cnt] != c && s[cnt])
		cnt++;
	if (s[cnt] == c)
		return (cnt);
	return (-1);
}
