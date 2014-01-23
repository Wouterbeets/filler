/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   analyse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbeets <wbeets@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/22 11:50:52 by wbeets            #+#    #+#             */
/*   Updated: 2014/01/23 13:52:54 by wbeets           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		place_piece(int y, int x, int j, t_info *d)
{
	int	i;
	int	piece_x;
	int	piece_y;
	int	touch;

	j = 0;
	touch = 0;
	i = 0;
	ft_putstr_fd("starting tests:\n", 2);
	ft_putstr_fd("map location for piece =  ", 2);
	ft_putstr_fd(ft_itoa(y), 2);
	ft_putstr_fd("\t", 2);
	ft_putstr_fd(ft_itoa(x), 2);
	ft_putstr_fd("\n", 2);
	if (!(x < 0 || x > d->mapcol || y < 0 || y < d->maprow))
		return (0);
	while (find_place_in_piece(&piece_y, &piece_x, ++i, d))
	{
		ft_putstr_fd("place of * = ", 2);
		ft_putstr_fd(ft_itoa(piece_y), 2);
		ft_putstr_fd("\t", 2);
		ft_putstr_fd(ft_itoa(piece_x), 2);
		ft_putstr_fd("\n", 2);
		ft_putstr_fd(ft_itoa(i), 2);
		if (y + d->piecerow < d->maprow &&
			x + d->piececol < d->mapcol &&
			y + piece_y >= 0 && y + piece_y < d->maprow &&
			x + piece_x >= 0 &&
			x + piece_x < d->mapcol)
		{
//			ft_putstr_fd(" \t testing with y + piece_y && x + piece_x\n", 2);
			if (d->map[y + piece_y][x + piece_x] != '.')
			{
//				ft_putstr_fd("POINT\n", 2);
				touch++;
			}
		}
		else
		{
//			ft_putstr_fd("RET 0\n", 2);
			return (0);
		}
		if (touch > 1)
			return (0);
	}
	if (y + d->piecerow > d->maprow || x + d->piececol > d->mapcol)
	{
		d->x = 0;
		d->y = 0;
	}
	d->x = x;
	d->y = y;
	return (1);
}

int		find_place_in_piece(int *y, int *x, int i, t_info *d)
{
	int		j;
	int		k;
	int		l;

	j = 0;
	k = 0;
	l = 0;
	while (j < d->piecerow)
	{
		while (k < d->piececol)
		{
			if (d->piece[j][k] == '*')
			{
				l++;
				if (l == i)
				{
					*y = j;
					*x = k;
					return (1);
				}
			}
			k++;
		}
		j++;
		k = 0;
	}
	return (0);
}

int		is_space(t_info *d)
{
	int	piece_x;
	int	piece_y;
	int	i;

	i = 0;
	piece_x = 0;
	piece_y = 0;
	find_place_in_piece(&piece_y, &piece_x, ++i, d);
//	ft_putstr_fd("\n piece fist * x & y are \t", 2);
//	ft_putstr_fd(ft_itoa(piece_y), 2);
//	ft_putstr_fd("\t", 2);
//	ft_putstr_fd(ft_itoa(piece_x), 2);
//	ft_putstr_fd("\n", 2);
	while(!(place_piece(d->y - piece_y, d->x - piece_x, i, d)))
	{
		if (!(find_place_in_piece(&piece_y, &piece_x, ++i, d)))
		{
//			ft_putstr_fd("RET 0\n", 2);
			return (0);
		}
//		ft_putstr_fd("trying next posib for piece\n", 2);
//		ft_putstr_fd(ft_itoa(piece_y), 2);
//		ft_putstr_fd(ft_itoa(piece_x), 2);
	}
	return (1);
}

int		test_case(t_info *d, int y, int x)
{
	d->x = x;
	d->y = y;
	if (is_space(d))
		return (1);
//	ft_putstr_fd("RET 0\n", 2);
	return (0);
}

void	analyse(t_info *d)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (i < d->maprow)
	{
		while (j < d->mapcol)
		{
			if (d->map[i][j] == d->player || d->map[i][j] == d->player + 32)
			{
//				ft_putstr_fd("\n\ntrying next posib for map loce\n\n\n", 2);
//				ft_putstr_fd(ft_itoa(i), 2);
//				ft_putstr_fd("\t", 2);
//				ft_putstr_fd(ft_itoa(j), 2);
				if (test_case(d, i, j))
					return ;
			}
			if (d->map[i][j] == d->opponent || d->map[i][j] == d->opponent + 32)
			{
				d->opx = (d->opx + j) / 2;
				d->opy = (d->opy + i) / 2;
			}
			j++;
		}
//		ft_putstr_fd(ft_itoa(i), 2);
		j = 0;
		i++;
	}
//	ft_putstr_fd("RET ANALYSE 0\n", 2);
	freetab(d->map);
	freetab(d->piece);
}
