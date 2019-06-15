/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   figure.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stherkil <stherkil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/15 16:12:57 by stherkil          #+#    #+#             */
/*   Updated: 2019/06/15 19:47:33 by stherkil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	change_horiz(int i, int j, int col, int fat)
{
	line(g_beg[0] + i * fat - g_mex[j][i] - tandeg(g_angle) * j * fat,
			g_beg[1] + j * fat - g_mex[j][i] + tandeg(g_angle) * i * fat,
			g_beg[0] + i * fat - g_mex[j + 1][i]
			- tandeg(g_angle) * (j + 1) * fat,
			g_beg[1] + fat * (j + 1) - g_mex[j + 1][i]
			+ tandeg(g_angle) * i * fat,
			col);
}

void	change_vert(int i, int j, int col, int fat)
{
	line(g_beg[0] + i * fat - g_mex[j][i] - tandeg(g_angle) * j * fat,
			g_beg[1] + j * fat - g_mex[j][i] + tandeg(g_angle) * i * fat,
			g_beg[0] + (i + 1) * fat - g_mex[j][i + 1]
			- tandeg(g_angle) * j * fat,
			g_beg[1] + fat * j - g_mex[j][i + 1]
			+ tandeg(g_angle) * (1 + i) * fat,
			col);
}

void	text(void)
{
	mlx_string_put(g_mlx_ptr, g_win_ptr, 0, 0, blue,
			ft_strjoin("angle: ", ft_itoa(g_angle % 360)));
	mlx_string_put(g_mlx_ptr, g_win_ptr, 0, 20, blue,
			ft_strjoin("zoom: x", ft_itoa(g_zoom)));
}

void	drawfig(int fat)
{
	int i;
	int j;
	int col;

	text();
	if (g_zoom == 0)
		return ;
	j = -1;
	fat = cosdeg(g_angle) * fat;
	while (++j < g_rows - 1)
	{
		i = -1;
		while (++i < g_cols - 1)
		{
			if (g_mex[j][i] != 0)
				col = 1;
			else
				col = 0;
			change_horiz(i, j, col, fat);
			change_vert(i, j, col, fat);
		}
		change_horiz(i, j, col, fat);
	}
	i = -1;
	while (++i < g_cols - 1)
		change_vert(i, j, col, fat);
}

void	delfig(int fat)
{
	int i;
	int j;
	int col;

	i = -1;
	while (++i < 150)
	{
		j = -1;
		while (++j < 150)
			mlx_pixel_put(g_mlx_ptr, g_win_ptr, (int)j, (int)i, black);
	}
	j = -1;
	fat = cosdeg(g_angle) * fat;
	while (++j < g_rows - 1)
	{
		i = -1;
		while (++i < g_cols - 1)
		{
			change_horiz(i, j, 3, fat);
			change_vert(i, j, 3, fat);
		}
		change_horiz(i, j, 3, fat);
	}
	i = -1;
	while (++i < g_cols - 1)
		change_vert(i, j, 3, fat);
}
