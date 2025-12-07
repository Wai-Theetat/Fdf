/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_3D.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdharmar <tdharmar@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/07 13:54:54 by tdharmar          #+#    #+#             */
/*   Updated: 2025/12/07 14:37:40 by tdharmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	convert_point_to_3d(t_map *map)
{
	int			row;
	int			col;
	t_point_3D	*point;
	double		z;

	row = 0;
	while (row++ < map->row)
	{
		col = 0;
		while (col++ < map->col)
		{
			point = &(map->map_3d[row][col]);
			point->x = calc_x(col, map);
			//point->y = calc_y();
			//z = ...
			//point->z = z
			//point->pre_def_color = conv_rgba();
		}
	}
}
