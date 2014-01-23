/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strstart.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbeets <wbeets@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/22 09:54:02 by wbeets            #+#    #+#             */
/*   Updated: 2014/01/22 09:59:22 by wbeets           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		strstart(char *str, char *start)
{
	int		i;

	i = 0;
	while(str[i] && start[i])
	{
		if (start[i] != str[i])
			return (0);
		i++;
	}
	if (start[i])
		return (0);
	return (1);
}
