/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawline.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stherkil <stherkil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/15 17:40:05 by stherkil          #+#    #+#             */
/*   Updated: 2019/06/15 19:01:42 by stherkil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	line(int x, int y, int x2, int y2, int col)
{
	int tmp;
	int w;
	int h;
	double m;
	double j;
	int i;

	if (x2 < x || (y2 < y && x2 == x))
	{
		tmp = x;
		x = x2;
		x2 = tmp;
		tmp = y;
		y = y2;
		y2 = tmp;
	}
	w = x2 - x;
	h = y2 - y;
	m = h / (double)w;
	j = y;
	if (x2 == x)
	{
		j = x;
		i = y - 1;
		while (++i < y2)
		{
			if (col == 0)
				mlx_pixel_put(g_mlx_ptr, g_win_ptr, (int)j, (int)i, yellow);
			if (col == 1)
				mlx_pixel_put(g_mlx_ptr, g_win_ptr, (int)j, (int)i, blue);
			if (col == 2)
				mlx_pixel_put(g_mlx_ptr, g_win_ptr, (int)j, (int)i, red);
			if (col == 3)
				mlx_pixel_put(g_mlx_ptr, g_win_ptr, (int)j, (int)i, black);
			j += 0.001;
		}
	}
	else
	{
		i = x - 1;
		while (++i <= x2)
		{
			if (col == 0)
				mlx_pixel_put(g_mlx_ptr, g_win_ptr, i, (int)j, yellow);
			if (col == 1)
				mlx_pixel_put(g_mlx_ptr, g_win_ptr, i, (int)j, blue);
			if (col == 2)
				mlx_pixel_put(g_mlx_ptr, g_win_ptr, i, (int)j, red);
			if (col == 3)
				mlx_pixel_put(g_mlx_ptr, g_win_ptr, i, (int)j, black);
			j += m;
		}
	}
}
