/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stherkil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/01 17:35:25 by stherkil          #+#    #+#             */
/*   Updated: 2019/06/15 16:28:03 by stherkil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	exitfct(void *in, void *in2)
{
	free(in);
	free(in2);
	return (0);
}

int			main(int argc, char **argv)
{
	if (argc != 2)
		return (0);
	printf("yes1n");
	g_zoom = 30;
	g_mex = get_next_matrix(argv[1], -1);
	/*
	g_mlx_ptr = mlx_init();
	g_win_ptr = mlx_new_window(g_mlx_ptr, 1000, 1000, "mlx 42");
	g_beg[0] = 200;
	g_beg[1] = 200;
	g_angle = 30;
	
	drawfig(g_zoom);
	mlx_key_hook(g_win_ptr, deal_key, (void *)0);
	mlx_mouse_hook(g_win_ptr, deal_mouse, (void *)0);
	mlx_loop(g_mlx_ptr);*/
	return (exitfct(g_mlx_ptr, g_win_ptr));
}
