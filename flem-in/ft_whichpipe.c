/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_whichpipe.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbateau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/04 15:55:13 by jbateau           #+#    #+#             */
/*   Updated: 2016/06/07 11:40:27 by jbateau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

char			*ft_whichpipe(t_info *info, char *name)
{
	t_pipe		*tmp;
	char		*line;

	tmp = info->pipe;
	line = NULL;
	while (tmp)
	{
		if (tmp->from && !ft_strcmp(tmp->from, name))
			line = ft_strdup(tmp->to);
		if (tmp->to && !ft_strcmp(tmp->to, name))
			line = ft_strdup(tmp->from);
		if (line)
		{
			ft_strdel(&(tmp->to));
			ft_strdel(&(tmp->from));
			return (line);
		}
		tmp = tmp->next;
	}
	return (NULL);
}
