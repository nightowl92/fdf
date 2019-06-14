/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stherkil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/13 20:17:25 by stherkil          #+#    #+#             */
/*   Updated: 2019/06/14 16:22:50 by stherkil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
/*
TODO:
1) makefile
2) adaptable to all inputs
3) norm
4) change relief
5) couleurs (degradé)
*/
#define black 0x000000
#define blue 0x0000ff
#define red 0xff0000
#define yellow 0xffd700
#define PUT(X) mlx_pixel_put(mlx_ptr, win_ptr, i,(int)j, X);

double tandeg(double angle)
{
	return (tan (angle * 3.14159265 / 180));
}

double cosdeg(double angle)
{
	return (cos (angle * 3.14159265 / 180));
}

void mult(int mex[11][19], int coef)
{
	int i;
	int j;

	i = -1;
	while (++i < 11)
	{
		j = -1;
		while (++j < 19)
		{
			if (mex[i][j] < 0) 
			{
				if (mex[i][j] / coef == 0)
					mex[i][j] *= -1;
				else
					mex[i][j] /= coef;
			}
			else
				mex[i][j] *= coef;
		}
	}
}

void divi(int mex[11][19], int coef)
{
	int i;
	int j;

	i = -1;
	while (++i < 11)
	{
		j = -1;
		while (++j < 19)
		{
			if (mex[i][j] < 0)
				mex[i][j] *= coef;
			else if (mex[i][j] / coef == 0)
				mex[i][j] *= -1;
			else
				mex[i][j] /= coef;
		}
	}
}

int cnt_len(char *w[200])
{
	int j;
	int nb;

	nb = 0;
	j = 0;

	while (*w[j])
	{
		++nb;
		while (*w[j] >= '0' && *w[j] <= '9')
			w[j]++;
		while (*w[j] == ' ')
			w[j]++;
	}
	return (nb);
}

void line(int x,int y,int x2, int y2, void *mlx_ptr, void *win_ptr, int col)
{
	int tmp;

	if (x2 < x || (y2 < y && x2 == x))
	{
		tmp = x;
		x = x2;
		x2 = tmp;
		tmp = y;
		y = y2;
		y2 = tmp;
	}
	int w = x2 - x;
	int h = y2 - y;
	double m = h/(double)w;
	double j = y;
	if (x2 == x)
	{
		double j = x;
		for (int i=y;i<=y2;i++)
		{
			if (col == 0)
				mlx_pixel_put(mlx_ptr, win_ptr, (int)j,(int)i, yellow);
			if (col == 1)
				mlx_pixel_put(mlx_ptr, win_ptr, (int)j,(int)i, blue);
			if (col == 2)
				mlx_pixel_put(mlx_ptr, win_ptr, (int)j,(int)i, red);
			if (col == 3)
				mlx_pixel_put(mlx_ptr, win_ptr, (int)j,(int)i, black);
			j += 0.001 ;
		}
	}
	else
	{
		for (int i=x;i<=x2;i++)
		{
			if (col == 0)
				PUT(yellow);
			if (col == 1)
				PUT(blue);
			if (col == 2)
				PUT(red);
			if (col == 3)
				PUT(black);
			j += m ;
		}
	}
}

void drawfig(int mex[11][19], int max, void *mlx_ptr, void *win_ptr, int fat, int beg[2], int angle)
{
	int len;
	int i;
	int j;
	int col;


	mlx_string_put(mlx_ptr, win_ptr, 0, 0, blue, ft_strjoin("angle: ", ft_itoa(angle % 360)));
	mlx_string_put(mlx_ptr, win_ptr, 0, 20, blue, ft_strjoin("zoom: x", ft_itoa(zoom)));
	if (zoom == 0)
		return ;
	j = -1;
	fat= cosdeg(angle) * fat;
	//len = cnt_len(w);
	while (++j < 11 - 1)
	{
		i = -1;
		while (++i < 19 - 1)
		{
			if (mex[j][i] != 0)
				col = 1;
			else
				col = 0;
			line(beg[0] + i * fat - mex[j][i] - tandeg(angle) * j * fat, beg[1] + j * fat - mex[j][i]+ tandeg(angle) * i * fat, beg[0] + i * fat - mex[j + 1][i]- tandeg(angle) * (j + 1) * fat, beg[1] + fat * (j + 1) - mex[j + 1][i] + tandeg(angle) * i * fat, mlx_ptr, win_ptr, col);
			line(beg[0] + i * fat - mex[j][i] - tandeg(angle) * j * fat, beg[1] + j * fat - mex[j][i]+ tandeg(angle) * i * fat, beg[0] + (i + 1) * fat - mex[j][i + 1] - tandeg(angle) * j * fat, beg[1] + fat * j - mex[j][i + 1] + tandeg(angle) * (1 + i) * fat, mlx_ptr, win_ptr, col);
		}
		line(beg[0] + i * fat - mex[j][i] - tandeg(angle) * j * fat, beg[1] + j * fat - mex[j][i]+ tandeg(angle) * i * fat, beg[0] + i * fat - mex[j + 1][i]- tandeg(angle) * (j + 1) * fat, beg[1] + fat * (j + 1) - mex[j + 1][i] + tandeg(angle) * i * fat, mlx_ptr, win_ptr, col);
	}
	i = -1;
	while (++i < 19 - 1)
		line(beg[0] + i * fat - mex[j][i] - tandeg(angle) * j * fat, beg[1] + j * fat - mex[j][i]+ tandeg(angle) * i * fat, beg[0] + (i + 1) * fat - mex[j][i + 1] - tandeg(angle) * j * fat, beg[1] + fat * j - mex[j][i + 1] + tandeg(angle) * (1 + i) * fat, mlx_ptr, win_ptr, col);
}
void delfig(int mex[11][19], int max, void *mlx_ptr, void *win_ptr, int fat, int beg[2], int angle)
{
	int len;
	int i;
	int j;
	int col;

	i = -1;
	while (++i < 150)
	{
		j = -1;
		while (++j < 150)
			mlx_pixel_put(mlx_ptr, win_ptr, (int)j,(int)i, black);
	}
	j = -1;
	fat= cosdeg(angle) * fat;
	//len = cnt_len(w);
	while (++j < 11 - 1)
	{
		i = -1;
		while (++i < 19 - 1)
		{
			line(beg[0] + i * fat - mex[j][i] - tandeg(angle) * j * fat, beg[1] + j * fat - mex[j][i]+ tandeg(angle) * i * fat, beg[0] + i * fat - mex[j + 1][i]- tandeg(angle) * (j + 1) * fat, beg[1] + fat * (j + 1) - mex[j + 1][i] + tandeg(angle) * i * fat, mlx_ptr, win_ptr, 3);
			line(beg[0] + i * fat - mex[j][i] - tandeg(angle) * j * fat, beg[1] + j * fat - mex[j][i]+ tandeg(angle) * i * fat, beg[0] + (i + 1) * fat - mex[j][i + 1] - tandeg(angle) * j * fat, beg[1] + fat * j - mex[j][i + 1] + tandeg(angle) * (1 + i) * fat, mlx_ptr, win_ptr, 3);
		}
		line(beg[0] + i * fat - mex[j][i] - tandeg(angle) * j * fat, beg[1] + j * fat - mex[j][i]+ tandeg(angle) * i * fat, beg[0] + i * fat - mex[j + 1][i]- tandeg(angle) * (j + 1) * fat, beg[1] + fat * (j + 1) - mex[j + 1][i] + tandeg(angle) * i * fat, mlx_ptr, win_ptr, 3);
	}
	i = -1;
	while (++i < 19 - 1)
		line(beg[0] + i * fat - mex[j][i] - tandeg(angle) * j * fat, beg[1] + j * fat - mex[j][i]+ tandeg(angle) * i * fat, beg[0] + (i + 1) * fat - mex[j][i + 1] - tandeg(angle) * j * fat, beg[1] + fat * j - mex[j][i + 1] + tandeg(angle) * (1 + i) * fat, mlx_ptr, win_ptr, 3);

	//makegrid(300, 10, mlx_ptr, win_ptr);
}


static int exitfct(void *in)
{
	free(in);
	return (0);
}

int deal_key(int key, void *param)
{
	//printf("angle %d\n", angle);
	if (key == 53)
		exit(0);

	if (key == 126)
	{
		delfig(mex, 11, mlx_ptr, win_ptr, zoom, beg, angle);
		beg[1] -= 5;
		drawfig(mex, 11, mlx_ptr, win_ptr, zoom, beg, angle);
	}
	if (key == 125)
	{

		delfig(mex, 11, mlx_ptr, win_ptr, zoom, beg, angle);
		beg[1] += 5;
		drawfig(mex, 11, mlx_ptr, win_ptr, zoom, beg, angle);

	}

	if (key == 123)
	{

		delfig(mex, 11, mlx_ptr, win_ptr, zoom, beg, angle);
		beg[0] -= 5;
		drawfig(mex, 11, mlx_ptr, win_ptr, zoom, beg, angle);
	}
	if (key == 124)
	{

		delfig(mex, 11, mlx_ptr, win_ptr, zoom, beg, angle);
		beg[0] += 5;
		drawfig(mex, 11, mlx_ptr, win_ptr, zoom, beg, angle);
	}

	if (key == 24)
	{	
		delfig(mex, 11, mlx_ptr, win_ptr, zoom, beg, angle);
		mult(mex, 2);
		drawfig(mex, 11, mlx_ptr, win_ptr, zoom, beg, angle);
	}
	if (key == 27)
	{
		delfig(mex, 11, mlx_ptr, win_ptr, zoom, beg, angle);
		divi(mex, 2);
		drawfig(mex, 11, mlx_ptr, win_ptr, zoom, beg, angle);
	}

	if (key == 86)
	{
		delfig(mex, 11, mlx_ptr, win_ptr, zoom, beg, angle);
		if (angle % 90 - 5 == 0)
			angle -= 10;
		else
			angle -= 5;
		drawfig(mex, 11, mlx_ptr, win_ptr, zoom, beg, angle);
	}

	if (key == 88)
	{
		delfig(mex, 11, mlx_ptr, win_ptr, zoom, beg, angle);
		if (angle % 90 - 5 == 0)
			angle += 10;
		else
			angle += 5;
		drawfig(mex, 11, mlx_ptr, win_ptr, zoom, beg, angle);
	}

	//printf("key is %d\n", key);
	return (0);
}

int deal_mouse(int key, void *param)
{

	if (key == 4)
	{
		delfig(mex, 11, mlx_ptr, win_ptr, zoom, beg, angle);
		zoom += 5;
		drawfig(mex, 11, mlx_ptr, win_ptr, zoom, beg, angle);
	}
	if (key == 5)
	{
		delfig(mex, 11, mlx_ptr, win_ptr, zoom, beg, angle);
		zoom -= 5;
		drawfig(mex, 11, mlx_ptr, win_ptr, zoom, beg, angle);
	}

	//printf("%d\n", key);
	return (0);
}

int get_len(char *s)
{
	int i;
	char *w;
	int fd;
	int ret;

	fd = open(s, O_RDONLY);
	i = 0;
	while ((ret = get_next_line(fd, &w) != 0))
	{
		if (ret == -1)
		return (0);
		++i;
	}
	free(w);
	return (i);
}

char **get_next_matrix(char *s)
{
	int len;

	if (!(len = get_len(s)))
	return (NULL);
	return (NULL);
}

int main(int argc, char **argv)
{
	int fd;
	char *s;
	char *w[200];
	int i;
	char **nums;
	int len;

	zoom = 30;
	i = -1;
	if (argc != 2)
		return (0);
	nums = get_next_matrix(argv[1]);
	fd = open(argv[1], O_RDONLY);
	printf("%d\n", len);
	while (get_next_line(fd, (&(w[++i]))) != 0 && w[i])
		;
	int o;
	int j = -1;
	while (++j < i)
	{
		o = -1;
		while (*w[j])
		{
			mex[j][++o] = atoi(w[j]);
			while (*w[j] >= '0' && *w[j] <= '9')
				w[j]++;
			while (*w[j] == ' ')
				w[j]++;
		}
	}
	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 1000, 1000, "mlx 42");
	beg[0] = 200;
	beg[1] = 200;
	double result = tan ( 45 * 3.14159265 / 180 );
	angle = 30;
	drawfig(mex, i, mlx_ptr, win_ptr, zoom, beg, angle);

	mlx_key_hook(win_ptr, deal_key, (void *)0);
	mlx_mouse_hook (win_ptr, deal_mouse, (void *)0);
	mlx_loop(mlx_ptr);
	return (exitfct(mlx_ptr));
}
