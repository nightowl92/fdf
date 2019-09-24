/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   import.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stherkil <stherkil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/13 13:17:15 by stherkil          #+#    #+#             */
/*   Updated: 2019/07/19 13:25:28 by stherkil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int		freestr(char **s)
{
	free(*s);
	return (0);
}

static int		checkstring(char *s, int i)
{
	while (*s)
	{
		if (*s == '-')
			s++;
		if (!ft_isdigit(*s))
			return (0);
		while (ft_isdigit(*s))
			s++;
		if (*s == ',')
		{
			s++;
			if (!(ft_isalnum(*s)))
				return (0);
			while (ft_isalnum(*s))
				s++;
		}
		if (*s)
			if (*s != ' ')
				return (0);
		while (*s == ' ')
			s++;
		++i;
	}
	return (i);
}

static int		get_rows(char *s, int *value, int value2, int i)
{
	int		fd;
	char	*w;
	int		ret;
	int		j;

	j = 0;
	fd = open(s, O_RDONLY);
	if (fd < 0)
		return (0);
	while ((ret = get_next_line(fd, &w)) != 0)
	{
		if (ret == -1)
			return (0);
		while (w[j] == ' ')
			j++;
		if (!(*value = checkstring(w + j, 0)))
			return (freestr(&w));
		if (value2 != 0)
			if (*value != value2)
				return (freestr(&w));
		++i;
		free(w);
		value2 = *value;
	}
	return (i);
}

static int		*ctoi(char *s, int col, int i)
{
	int	*out;

	if (!(out = malloc(sizeof(int) * col)))
		return (0);
	while (*s)
	{
		while (*s == ' ')
			s++;
		out[i] = ft_atoi(s);
		if (*s == '-')
			s++;
		while (ft_isdigit(*s))
			s++;
		if (*s == ',')
		{
			s++;
			while (ft_isalnum(*s))
				s++;
		}
		while (*s == ' ')
			s++;
		++i;
	}
	return (out);
}

int				get_points(t_data **points, char *s, int i)
{
	int		fd;
	char	*w;

	if (!((*points)->row = get_rows(s, &((*points)->col), 0, 0)))
		return (0);
	if (!((*points)->m = malloc(sizeof(int*) * (*points)->row)))
		return (0);
	if (!((*points)->m_cp = malloc(sizeof(int*) * (*points)->row)))
		return (0);
	fd = open(s, O_RDONLY);
	if (fd < 0)
		return (0);
	while (get_next_line(fd, &w) != 0 && ++i < (*points)->row)
	{
		if (!(((*points)->m)[i] = ctoi(w, (*points)->col, 0)))
			return (freestr(&w));
		if (!(((*points)->m_cp)[i] = ctoi(w, (*points)->col, 0)))
			return (freestr(&w));
		free(w);
	}
	return (1);
}
