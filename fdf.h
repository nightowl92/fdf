/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stherkil <stherkil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/13 20:17:33 by stherkil          #+#    #+#             */
/*   Updated: 2019/06/15 19:17:43 by stherkil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "mlx.h"
# include <unistd.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include "GNL/get_next_line.h"
# define black 0x000000
# define blue 0x0000ff
# define red 0xff0000
# define yellow 0xffd700
# define PUT(X) mlx_pixel_put(mlx_ptr, win_ptr, i,(int)j, X);

int		**get_next_matrix(char *s, int i);
double	tandeg(double angle);
double	cosdeg(double angle);
void	mult(int coef);
void	divi(int coef);
int		deal_key(int key, void *param);
int		deal_mouse(int key, void *param);
void	drawfig(int fat);
void	delfig(int fat);
void	line(int x, int y, int x2, int y2, int col);
int		**g_mex;
void	*g_win_ptr;
void	*g_mlx_ptr;
int		g_beg[2];
int		g_angle;
int		g_zoom;
int     g_rows;
int     g_cols;
#endif
