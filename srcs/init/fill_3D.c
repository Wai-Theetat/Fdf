/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_3D.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdharmar <tdharmar@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/07 13:54:54 by tdharmar          #+#    #+#             */
/*   Updated: 2025/12/22 10:17:22 by tdharmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	convert_point_to_3d(t_map *map)
{
	int			row;
	int			col;
	t_point_3D	*point;
	double		z;

	row = -1;
	while (++row < map->row)
	{
		col = -1;
		while (++col < map->col)
		{
			point = &(map->map_3d[row][col]);
			point->x = calc_x(col, map);
			point->y = calc_y(row, map);
			z = (double)ft_atoi(map->map_str[row][col]) * (map->spacing);
			point->z = z;
			point->pre_def_color = conv_rgba(map->map_str[row][col], map);
		}
	}
}
