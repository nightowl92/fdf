/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_matrix.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stherkil <stherkil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/15 15:18:11 by stherkil          #+#    #+#             */
/*   Updated: 2019/06/15 20:23:40 by stherkil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		get_len(char *s)
{
	int		i;
	char	*w;
	int		fd;
	int		ret;

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

int		lnsp(char *s)
{
	int	*out;
	int	len;

	len = 0;
	while (*s)
	{
		++len;
		while (*s >= '0' && *s <= '9')
			s++;
		while (*s == ' ')
			s++;
	}
	return (len);
}

int		*toint(char *s)
{
	int	*out;
	int	i;

	i = -1;
	out = (int*)malloc(sizeof(int) * lnsp(s));
	while (*s)
	{
		out[++i] = ft_atoi(s);
		while ((*s >= '0' && *s <= '9') || *s == '-')
			s++;
		while (*s == ' ')
			s++;
	}
    g_cols = i;
	return (out);
}

int		**get_next_matrix(char *s, int i)
{
	int		fd;
	int		len;
	int		ret;
	int		**out;
	char	*w;

	if (!(len = get_len(s)))
		return (NULL);
	out = (int**)malloc(sizeof(int*) * len);
	fd = open(s, O_RDONLY);
	while ((ret = get_next_line(fd, &w) != 0))
		out[++i] = toint(w);
    g_rows = i;
	free(w);
	return (out);
}
