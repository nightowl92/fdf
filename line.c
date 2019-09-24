/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stherkil <stherkil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 21:19:32 by stherkil          #+#    #+#             */
/*   Updated: 2019/07/16 18:57:59 by stherkil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void			ft_swap(int *a, int *b, int *c, int *d)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
	tmp = *c;
	*c = *d;
	*d = tmp;
}

static void			put_update(t_data *data, int i, double *j, int col)
{
	mlx_pixel_put(data->mlx_ptr,
			data->win_ptr, (int)*j, (int)i, col);
	*j += 0.001;
}

void				line(int c[2], int x2, int y2, t_data *data)
{
	double	j;
	int		i;
	int		x;
	int		y;

	x = c[0];
	y = c[1];
	if (x2 < x || (y2 < y && x2 == x))
		ft_swap(&x, &x2, &y, &y2);
	if (x2 == x)
	{
		j = x;
		i = y - 1;
		while (++i < y2)
			put_update(data, i, &j, 0x0000ff);
	}
	else if ((j = y) || 1)
	{
		i = x - 1;
		while (++i <= x2)
		{
			mlx_pixel_put(data->mlx_ptr, data->win_ptr, i, (int)j, 0x0000ff);
			j += (y2 - y) / (double)(x2 - x);
		}
	}
}

void				rmline(int c[2], int x2, int y2, t_data *data)
{
	double	j;
	int		i;
	int		x;
	int		y;

	x = c[0];
	y = c[1];
	if (x2 < x || (y2 < y && x2 == x))
		ft_swap(&x, &x2, &y, &y2);
	if (x2 == x)
	{
		j = x;
		i = y - 1;
		while (++i < y2)
			put_update(data, i, &j, 0x000000);
	}
	else if ((j = y) || 1)
	{
		i = x - 1;
		while (++i <= x2)
		{
			mlx_pixel_put(data->mlx_ptr, data->win_ptr, i, (int)j, 0x000000);
			j += (y2 - y) / (double)(x2 - x);
		}
	}
}
