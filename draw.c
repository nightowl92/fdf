/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stherkil <stherkil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 21:08:19 by stherkil          #+#    #+#             */
/*   Updated: 2019/07/18 21:19:34 by stherkil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		lastone(t_data **points, int i, int x[2], int d)
{
	int j;

	j = -1;
	if (d == 0)
	{
		while (++j < (*points)->col - 1)
		{
			x[0] = ((*points)->co_x)[i][j];
			x[1] = ((*points)->co_y)[i][j];
			line(x, ((*points)->co_x)[i][j + 1],
					((*points)->co_y)[i][j + 1], *points);
		}
	}
	if (d == 1)
	{
		while (++j < (*points)->col - 1)
		{
			x[0] = ((*points)->co_x)[i][j];
			x[1] = ((*points)->co_y)[i][j];
			rmline(x, ((*points)->co_x)[i][j + 1],
					((*points)->co_y)[i][j + 1], *points);
		}
	}
}

void			draw(t_data **points)
{
	int i;
	int j;
	int x[2];

	i = -1;
	while (++i < (*points)->row - 1)
	{
		j = -1;
		while (++j < (*points)->col - 1)
		{
			x[0] = ((*points)->co_x)[i][j];
			x[1] = ((*points)->co_y)[i][j];
			line(x, ((*points)->co_x)[i + 1][j],
					((*points)->co_y)[i + 1][j], *points);
			line(x, ((*points)->co_x)[i][j + 1],
					((*points)->co_y)[i][j + 1], *points);
		}
		x[0] = ((*points)->co_x)[i][j];
		x[1] = ((*points)->co_y)[i][j];
		line(x, ((*points)->co_x)[i + 1][j],
				((*points)->co_y)[i + 1][j], *points);
	}
	lastone(points, i, x, 0);
}

void			rmdraw(t_data **points)
{
	int i;
	int j;
	int x[2];

	i = -1;
	while (++i < (*points)->row - 1)
	{
		j = -1;
		while (++j < (*points)->col - 1)
		{
			x[0] = ((*points)->co_x)[i][j];
			x[1] = ((*points)->co_y)[i][j];
			rmline(x, ((*points)->co_x)[i + 1][j],
					((*points)->co_y)[i + 1][j], *points);
			rmline(x, ((*points)->co_x)[i][j + 1],
					((*points)->co_y)[i][j + 1], *points);
		}
		x[0] = ((*points)->co_x)[i][j];
		x[1] = ((*points)->co_y)[i][j];
		rmline(x, ((*points)->co_x)[i + 1][j],
				((*points)->co_y)[i + 1][j], *points);
	}
	lastone(points, i, x, 1);
}
