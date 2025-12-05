/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdharmar <tdharmar@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 15:19:59 by tdharmar          #+#    #+#             */
/*   Updated: 2025/12/05 15:27:40 by tdharmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	create_point_n_spacing(t_map *map)
{
	int	i;

	i = -1;
	map->map_3d = ft_calloc(map->row, sizeof(t_point_3D *));
	map->map_2d = ft_calloc(map->row, sizeof(t_point_2D *));
	if (!(map->map_2d) || !(map->map_3d))
	{
		free_map(map);
		exit_error(ERR_MAL_MSG);
	}
	while (++i < map->row)
	{
		map->map_3d[i] = ft_calloc(map->col, sizeof(t_point_3D));
		map->map_2d[i] = ft_calloc(map->col, sizeof(t_point_2D));
		if (!(map->map_3d[i]) || !(map->map_2d[i]))
		{
			free_map(map);
			exit_error(ERR_MAL_MSG);
		}
	}
	map->spacing = ft_min(WIDTH / map->col, HEIGHT / map->row) / 2;
	map->spacing = ft_max(2, map->spacing);
}
