/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gridedit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stherkil <stherkil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 21:11:37 by stherkil          #+#    #+#             */
/*   Updated: 2019/07/16 20:19:26 by stherkil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		rotationz(int i, int j, t_data **points)
{
	int tmpx;
	int tmpy;

	tmpx = ((*points)->co_x)[i][j];
	tmpy = ((*points)->co_y)[i][j];
	((*points)->co_x)[i][j] =
		cos((*points)->rotz) * tmpx + sin((*points)->rotz) * tmpy;
	((*points)->co_y)[i][j] =
		-sin((*points)->rotz) * tmpx + cos((*points)->rotz) * tmpy;
}

static void		rotationy(int i, int j, int *z, t_data **points)
{
	int tmpx;
	int tmpz;

	tmpx = ((*points)->co_x)[i][j];
	tmpz = *z;
	((*points)->co_x)[i][j] =
		cos((*points)->roty) * tmpx + sin((*points)->roty) * tmpz;
	*z = -tmpx * sin((*points)->roty) + tmpz * cos((*points)->roty);
}

static void		rotationx(int i, int j, int *z, t_data **points)
{
	int tmpy;
	int tmpz;

	tmpy = ((*points)->co_y)[i][j];
	tmpz = *z;
	((*points)->co_y)[i][j] =
		cos((*points)->rotx) * tmpy + sin((*points)->rotx) * tmpz;
	*z = -sin((*points)->rotx) * tmpy + cos((*points)->rotx) * tmpz;
}

static void		putitback(int i, int j, t_data **points)
{
	((*points)->co_x)[i][j] +=
		(*points)->row * (*points)->wit / 2 + (*points)->refx;
	((*points)->co_y)[i][j] +=
		(*points)->col * (*points)->wit / 2 + (*points)->refy;
}

void			gridedit(t_data **points)
{
	int i;
	int j;
	int z;

	i = -1;
	while (++i < (*points)->row)
	{
		j = -1;
		while (++j < (*points)->col)
		{
			((*points)->co_x)[i][j] =
				i * (*points)->wit - (*points)->row * (*points)->wit / 2;
			((*points)->co_y)[i][j] =
				j * (*points)->wit - (*points)->col * (*points)->wit / 2;
			z = ((*points)->m)[i][j];
			rotationz(i, j, points);
			rotationy(i, j, &z, points);
			rotationx(i, j, &z, points);
			iso(&((*points)->co_x)[i][j],
					&((*points)->co_y)[i][j], ((*points)->m)[i][j], points);
			putitback(i, j, points);
		}
	}
}
