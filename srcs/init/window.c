/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdharmar <tdharmar@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 15:35:20 by tdharmar          #+#    #+#             */
/*   Updated: 2025/12/11 16:13:25 by tdharmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void    adjust_window(t_map *map)
{
	double	map_w;
	double	map_h;
	double	zoom_x;
	double	zoom_y;

	map_w = (map->col + map->row) * cos(0.523599) * map->spacing;
    map_h = ((map->col + map->row) * sin(0.523599) + \
			ft_abs(map->highest - map->lowest)) * map->spacing;
	zoom_x = (WIDTH * 0.5) / map_w;
	zoom_y = (HEIGHT * 0.5) / map_h;
	if (zoom_x < zoom_y)
		map->zoom = zoom_x;
	else
		map->zoom = zoom_y;
	if (map->zoom < 0.1)
		map->zoom = 0.1;
	map->shift_x = WIDTH / 2;
	map->shift_y = HEIGHT / 2;
}
