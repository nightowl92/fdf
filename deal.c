/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deal.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stherkil <stherkil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/15 16:09:55 by stherkil          #+#    #+#             */
/*   Updated: 2019/06/15 19:08:49 by stherkil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	move(int key)
{
	if (key == 126)
	{
		delfig(g_zoom);
		g_beg[1] -= 5;
		drawfig(g_zoom);
	}
	if (key == 125)
	{
		delfig(g_zoom);
		g_beg[1] += 5;
		drawfig(g_zoom);
	}
	if (key == 123)
	{
		delfig(g_zoom);
		g_beg[0] -= 5;
		drawfig(g_zoom);
	}
	if (key == 124)
	{
		delfig(g_zoom);
		g_beg[0] += 5;
		drawfig(g_zoom);
	}
}

void	tilt(int key)
{
	if (key == 86)
	{
		delfig(g_zoom);
		if (g_angle % 90 - 5 == 0)
			g_angle -= 10;
		else
			g_angle -= 5;
		drawfig(g_zoom);
	}
	if (key == 88)
	{
		delfig(g_zoom);
		if (g_angle % 90 - 5 == 0)
			g_angle += 10;
		else
			g_angle += 5;
		drawfig(g_zoom);
	}
}

int		deal_key(int key, void *param)
{
	if (key == 53)
		exit(0);
	if (key <= 126 && key >= 123)
		move(key);
	if (key == 86 || key == 88)
		tilt(key);
	if (key == 24)
	{
		delfig(g_zoom);
		mult(2);
		drawfig(g_zoom);
	}
	if (key == 27)
	{
		delfig(g_zoom);
		divi(2);
		drawfig(g_zoom);
	}
	return (0);
}

int		deal_mouse(int key, void *param)
{
	if (key == 4)
	{
		delfig(g_zoom);
		g_zoom += 5;
		drawfig(g_zoom);
	}
	if (key == 5)
	{
		delfig(g_zoom);
		g_zoom -= 5;
		drawfig(g_zoom);
	}
	return (0);
}
