/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbeets <wbeets@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/21 17:00:54 by wbeets            #+#    #+#             */
/*   Updated: 2014/01/23 14:32:30 by wbeets           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
void	print(t_info *d)
{
	ft_putstr(ft_itoa(d->y));
//	ft_putstr_fd(ft_itoa(d->y), 2);
	ft_putchar(' ');
//	ft_putchar_fd(' ', 2);
	ft_putstr(ft_itoa(d->x));
//	ft_putstr_fd(ft_itoa(d->x), 2);
	ft_putchar('\n');
//	ft_putchar_fd('\n', 2);
}

char	declare_player(char *line, t_info *d)
{
	static char	player = 'Z';

	if (player == 'Z')
	{
		player = line[10] == '1' ? P1 : P2;
		d->opponent = player == P1 ? P2 : P1;
	}
	free(line);
	line = NULL;
	return (player);
}

int		main()
{
	char	*line;
	t_info	d;

	while (get_next_line(0, &line) > 0)
	{
		ft_putstr_fd("main()\n", 2);
		ft_putstr_fd(line, 2);
		ft_putstr_fd("\n", 2);
		if (strstart(line, "$$$"))
		{
			d.player = declare_player(line, &d);
			ft_putstr_fd("$$$\n", 2);
		}
		if (strstart(line, "Plateau"))
		{
			ft_putstr_fd("Plateau\n", 2);
			d.map = save_map(&line, &d);
		}
		if (strstart(line, "Piece"))
		{
			ft_putstr_fd("Piece\n", 2);
			d.piece = save_piece(&line, &d);
			analyse(&d);
			ft_putstr_fd("back in main", 2);
			print(&d);
		}
	}
	return (0);
}
