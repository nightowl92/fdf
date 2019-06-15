/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stherkil <stherkil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/15 15:23:12 by stherkil          #+#    #+#             */
/*   Updated: 2019/06/15 19:18:35 by stherkil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

double	tandeg(double g_angle)
{
	return (tan(g_angle * 3.14159265 / 180));
}

double	cosdeg(double g_angle)
{
	return (cos(g_angle * 3.14159265 / 180));
}

void	mult(int coef)
{
	int i;
	int j;

	i = -1;
	while (++i < g_rows)
	{
		j = -1;
		while (++j < g_cols)
		{
			if (g_mex[i][j] < 0)
			{
				if (g_mex[i][j] / coef == 0)
					g_mex[i][j] *= -1;
				else
					g_mex[i][j] /= coef;
			}
			else
				g_mex[i][j] *= coef;
		}
	}
}

void	divi(int coef)
{
	int i;
	int j;

	i = -1;
	while (++i < g_rows)
	{
		j = -1;
		while (++j < g_cols)
		{
			if (g_mex[i][j] < 0)
				g_mex[i][j] *= coef;
			else if (g_mex[i][j] / coef == 0)
				g_mex[i][j] *= -1;
			else
				g_mex[i][j] /= coef;
		}
	}
}
