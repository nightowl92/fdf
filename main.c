/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stherkil <stherkil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 16:20:42 by stherkil          #+#    #+#             */
/*   Updated: 2019/07/19 13:24:33 by stherkil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void			freematrix(int **a, int len)
{
	int i;

	i = -1;
	while (++i < len)
		free(a[i]);
	free(a);
}

int				errfct(char *msg, t_data **tobefreed)
{
	if (*tobefreed != NULL)
	{
		if (((*tobefreed)->m) != NULL)
			freematrix(((*tobefreed)->m), ((*tobefreed)->row));
		if (((*tobefreed)->m_cp) != NULL)
			freematrix(((*tobefreed)->m_cp), ((*tobefreed)->row));
		if (((*tobefreed)->co_x) != NULL)
			freematrix(((*tobefreed)->co_x), ((*tobefreed)->row));
		if (((*tobefreed)->co_y) != NULL)
			freematrix(((*tobefreed)->co_y), ((*tobefreed)->row));
		if (((*tobefreed)->win_ptr) != NULL)
			mlx_destroy_window(
					((*tobefreed)->mlx_ptr), ((*tobefreed)->win_ptr));
		if (((*tobefreed)->mlx_ptr) != NULL)
			ft_memdel((void **)&((*tobefreed)->mlx_ptr));
		free(*tobefreed);
	}
	if (msg)
		ft_putendl(msg);
	return (0);
}

static t_data	*init_p(void)
{
	t_data	*points;

	if (!(points = malloc(sizeof(t_data))))
		return (NULL);
	points->m = NULL;
	points->m_cp = NULL;
	points->co_x = NULL;
	points->co_y = NULL;
	if (!(points->mlx_ptr = mlx_init()))
		return (NULL);
	if (!(points->win_ptr =
				mlx_new_window(points->mlx_ptr, WINX, WINY, "mlx 42")))
		return (NULL);
	return (points);
}

int				main(int argc, char **argv)
{
	t_data	*points;

	points = NULL;
	if (argc != 2)
		return (errfct("Usage: ./fdf <datafile>", &points));
	if (!(points = init_p()))
		return (errfct("Couldn't init", &points));
	if (!get_points(&points, argv[1], -1))
		return (errfct("FATAL ERROR: FILE NOT VALID", &points));
	if (!gridinit(&points))
		return (errfct("Malloc error", &points));
	draw(&points);
	mlx_hook(points->win_ptr, 2, 0, deal_key, (void *)points);
	mlx_loop(points->mlx_ptr);
	return (errfct((char*)0, &points));
}
