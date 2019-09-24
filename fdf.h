/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stherkil <stherkil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/16 20:26:52 by stherkil          #+#    #+#             */
/*   Updated: 2019/07/19 11:41:22 by stherkil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# define WINX 1000
# define WINY 1000
# include "mlx.h"
# include <unistd.h>
# include <math.h>
# include <stdlib.h>
# include "get_next_line.h"

typedef struct		s_data
{
	double			angle;
	int				row;
	int				col;
	int				wit;
	int				refx;
	int				refy;
	int				min_z;
	int				max_z;
	double			rate_z;
	double			rotx;
	double			roty;
	double			rotz;
	int				**m;
	int				**m_cp;
	int				**co_x;
	int				**co_y;
	void			*win_ptr;
	void			*mlx_ptr;
}					t_data;
void				key5(int key, t_data **points);
double				ft_getrate(int a, int b);
void				iso(int *x, int *y, int z, t_data **points);
int					gridinit(t_data **points);
void				gridedit(t_data **points);
void				rmdraw(t_data **points);
void				draw(t_data **points);
int					gridinit(t_data **points);
void				line(int c[2], int x2, int y2, t_data *data);
void				rmline(int c[2], int x2, int y2, t_data *data);
int					errfct(char *msg, t_data **tobefreed);
int					get_points(t_data **points, char *s, int i);
int					deal_key(int key, void *param);
int					deal_mouse(int key, void *param);
#endif
