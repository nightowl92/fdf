/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gridinit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stherkil <stherkil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 20:46:34 by stherkil          #+#    #+#             */
/*   Updated: 2019/07/19 11:59:02 by stherkil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

double			ft_getrate(int a, int b)
{
	if (abs(a - b) < 10)
		return (2);
	if (abs(a - b) < 15)
		return (0.7);
	else if (abs(a - b) < 40)
		return (0.5);
	else
		return (0.2);
}

void			iso(int *x, int *y, int z, t_data **points)
{
	int previous_x;
	int previous_y;

	previous_x = *x;
	previous_y = *y;
	*x = (previous_x - previous_y) * cos((*points)->angle);
	*y = -z + (previous_x + previous_y) * sin((*points)->angle);
}

static int		gridinitinit(t_data **points)
{
	(*points)->wit = fmin((WINX * 0.5) / (*points)->row,
			(WINY * 0.4) / (*points)->col);
	(*points)->co_x = malloc(sizeof(int*) * (*points)->row);
	(*points)->co_y = malloc(sizeof(int*) * (*points)->row);
	(*points)->refx = (WINX / 2) -
		(*points)->row * (*points)->wit / 2;
	(*points)->refy = (WINY / 2) -
		(*points)->col * (*points)->wit / 2;
	(*points)->angle = 0.523599;
	(*points)->rotx = 0;
	(*points)->roty = 0;
	(*points)->rotz = 0;
	return (1);
}

static void		update_cords(int i, int j, int *z, t_data **points)
{
	((*points)->co_x)[i][j] =
		i * (*points)->wit - (*points)->row * (*points)->wit / 2;
	((*points)->co_y)[i][j] =
		j * (*points)->wit - (*points)->col * (*points)->wit / 2;
	*z = ((*points)->m)[i][j];
	iso(&((*points)->co_x)[i][j],
			&((*points)->co_y)[i][j], ((*points)->m)[i][j], points);
	((*points)->co_x)[i][j] +=
		(*points)->row * (*points)->wit / 2 + (*points)->refx;
	((*points)->co_y)[i][j] +=
		(*points)->col * (*points)->wit / 2 + (*points)->refy;
	if (i == 0 && j == 0)
	{
		(*points)->max_z = ((*points)->m)[i][j];
		(*points)->min_z = ((*points)->m)[i][j];
	}
	else
	{
		(*points)->max_z = fmax(((*points)->m)[i][j], (*points)->max_z);
		(*points)->min_z = fmin(((*points)->m)[i][j], (*points)->min_z);
	}
}

int				gridinit(t_data **points)
{
	int i;
	int j;
	int z;

	gridinitinit(points);
	i = -1;
	while (++i < (*points)->row)
	{
		j = -1;
		((*points)->co_x)[i] = malloc(sizeof(int) * (*points)->col);
		((*points)->co_y)[i] = malloc(sizeof(int) * (*points)->col);
		while (++j < (*points)->col)
			update_cords(i, j, &z, points);
	}
	(*points)->rate_z = ft_getrate((*points)->min_z, (*points)->max_z);
	return (1);
}
