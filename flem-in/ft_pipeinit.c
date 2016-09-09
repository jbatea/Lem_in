/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipeinit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbateau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/27 17:37:12 by jbateau           #+#    #+#             */
/*   Updated: 2016/05/30 07:18:29 by jbateau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_pipe			*ft_pipeinit(void)
{
	t_pipe		*new;

	new = (t_pipe *)malloc(sizeof(t_pipe));
	if (!new)
		return (NULL);
	new->from = NULL;
	new->to = NULL;
	return (new);
}
