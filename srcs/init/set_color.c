/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdharmar <tdharmar@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 14:21:10 by tdharmar          #+#    #+#             */
/*   Updated: 2025/12/11 15:33:29 by tdharmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	get_light(int start, int end, double percentage)
{
	return ((int)((1 - percentage) * start + percentage * end));
}

static int	get_color(int z, t_map *map)
{
	double	percentage;
	int		red;
	int		green;
	int		blue;

	if (map->highest == map->lowest)
		return (COLOR_LOW);
	percentage = (double)(z - map->lowest) / (map->highest - map->lowest);
	red = get_light((COLOR_LOW >> 24) & 0xFF, \
					(COLOR_HIGH >> 24) & 0xFF, percentage);
	green = get_light((COLOR_LOW >> 16) & 0xFF, \
					(COLOR_HIGH >> 16) & 0xFF, percentage);
	blue = get_light((COLOR_LOW >> 8) & 0xFF, \
					(COLOR_HIGH >> 8) & 0xFF, percentage);
	return ((red << 24) | (green << 16) | (blue << 8) | 0xFF);
}

void	set_altitude_color(t_map *map)
{
	int	row;
	int	col;
	int	z;

	row = 0;
	while (row < map->row)
	{
		col = 0;
		while (col < map->col)
		{
			z = ft_atoi(map->map_str[row][col]);
			map->map_3d[row][col].altitude_color = get_color(z, map);
			col++;
		}
		row++;
	}
}
