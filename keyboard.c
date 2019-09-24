/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stherkil <stherkil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/13 13:16:29 by stherkil          #+#    #+#             */
/*   Updated: 2019/07/18 20:49:15 by stherkil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		apply_m(t_data **points, int sign)
{
	int i;
	int j;

	i = -1;
	while (++i < (*points)->row)
	{
		j = -1;
		while (++j < (*points)->col)
			((*points)->m)[i][j] +=
				((*points)->m_cp)[i][j] * sign * (*points)->rate_z;
	}
}

void			key2(int key, t_data **points)
{
	if (key == 86)
	{
		rmdraw(points);
		(*points)->rotz -= 0.05;
		gridedit(points);
		draw(points);
	}
	if (key == 88)
	{
		rmdraw(points);
		(*points)->rotz += 0.05;
		gridedit(points);
		draw(points);
	}
	if (key == 91)
	{
		rmdraw(points);
		(*points)->roty -= 0.05;
		gridedit(points);
		draw(points);
	}
}

void			key3(int key, t_data **points)
{
	if (key == 84)
	{
		rmdraw(points);
		(*points)->roty += 0.05;
		gridedit(points);
		draw(points);
	}
	if (key == 89)
	{
		rmdraw(points);
		(*points)->rotx -= 0.05;
		gridedit(points);
		draw(points);
	}
	if (key == 83)
	{
		rmdraw(points);
		(*points)->rotx += 0.05;
		gridedit(points);
		draw(points);
	}
}

void			key4(int key, t_data **points)
{
	if (key == 24 || key == 69)
	{
		rmdraw(points);
		apply_m(points, 1);
		gridedit(points);
		draw(points);
	}
	if (key == 27 || key == 78)
	{
		rmdraw(points);
		apply_m(points, -1);
		gridedit(points);
		draw(points);
	}
	if (key == 18)
	{
		rmdraw(points);
		(*points)->angle = 0.523599;
		gridedit(points);
		draw(points);
	}
}

int				deal_key(int key, void *param)
{
	t_data **points;

	points = (t_data**)&param;
	if (key == 53)
		exit(errfct("ESC pressed", points));
	if (key == 123)
	{
		rmdraw(points);
		(*points)->refx -= 5;
		gridedit(points);
		draw(points);
	}
	if (key == 124)
	{
		rmdraw(points);
		(*points)->refx += 5;
		gridedit(points);
		draw(points);
	}
	key2(key, points);
	key3(key, points);
	key4(key, points);
	key5(key, points);
	return (0);
}
