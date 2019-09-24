/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stherkil <stherkil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/16 19:12:50 by stherkil          #+#    #+#             */
/*   Updated: 2019/07/18 20:49:12 by stherkil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	key5(int key, t_data **points)
{
	if (key == 126)
	{
		rmdraw(points);
		(*points)->refy -= 5;
		gridedit(points);
		draw(points);
	}
	if (key == 125)
	{
		rmdraw(points);
		(*points)->refy += 5;
		gridedit(points);
		draw(points);
	}
	if (key == 19)
	{
		rmdraw(points);
		(*points)->angle = 0.46373398;
		gridedit(points);
		draw(points);
	}
}
