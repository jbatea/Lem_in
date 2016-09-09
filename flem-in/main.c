/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbateau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/10 11:36:35 by jbateau           #+#    #+#             */
/*   Updated: 2016/06/10 11:36:50 by jbateau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		ft_ret(char *str, t_info *info)
{
	if (str)
		ft_strdel(&str);
	ft_creategraph(info);
}

void		ft_pipe(t_info *info, char *line)
{
	if (line && ft_ispipe(line, info))
	{
		ft_savepipe(info, ft_from(line), ft_to(line));
		ft_strdel(&line);
	}
	while (get_next_line(0, &line) == 1 && ft_ispipe(line, info))
	{
		ft_savepipe(info, ft_from(line), ft_to(line));
		ft_strdel(&line);
	}
	if (line && ft_isignore(line))
	{
		if (ft_isinfo(line))
			ft_ret(NULL, info);
		ft_strdel(&line);
		ft_pipe(info, NULL);
	}
}

char		*ft_info(t_info *info, char *str, char *line)
{
	if (line && (str = ft_isinfo(line)))
	{
		if (!ft_infodup(str, info))
		{
			ft_strdel(&line);
			return (str);
		}
		else
			ft_ret(str, info);
	}
	return (NULL);
}

void		ft_room(t_info *info, char *str)
{
	char	*line;

	while (get_next_line(0, &line) == 1 && ft_isroom(line))
	{
		if (!ft_checkdup(line, info))
			ft_addroom(info, line, str);
		else
			ft_ret(str, info);
		ft_strdel(&str);
	}
	if (str && ft_info(info, str, line))
		ft_ret(str, info);
	else if (!str && (str = ft_info(info, str, line)))
		ft_room(info, str);
	else if (line && ft_isignore(line))
	{
		ft_strdel(&line);
		ft_room(info, str);
	}
	else if (line && ft_ispipe(line, info))
		ft_pipe(info, line);
	else
		ft_strdel(&line);
}

int			main(void)
{
	t_info	*info;

	info = ft_infoinit();
	ft_ant(info);
	ft_room(info, NULL);
	ft_creategraph(info);
	return (0);
}
