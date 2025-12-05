/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdharmar <tdharmar@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 14:28:48 by tdharmar          #+#    #+#             */
/*   Updated: 2025/12/05 14:30:14 by tdharmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	free_map2d(t_point_2D **map2d, int n)
{
	int	i;

	if (!map2d)
		return ;
	i = -1;
	while (++i < n && map2d[i])
		free(map2d[i]);
	free(map2d);
}

void	free_map3d(t_point_3D **map3d, int n)
{
	int	i;

	if (!map3d)
		return ;
	i = -1;
	while (++i < n && map3d[i])
		free(map3d[i]);
	free(map3d);
}

void	free_str_arr(char ***arr)
{
	int	row;
	int	col;

	if (!arr)
		return ;
	row = 0;
	while (arr[row])
	{
		col = 0;
		while (arr[row][col])
		{
			free(arr[row][col]);
			col++;
		}
		free(arr[row]);
		row++;
	}
	free(arr);
}

void	free_map(t_map *map)
{
	if (!map)
		return ;
	if (map->map_2d)
		free_map2D(map->map_2d, map->row);
	if (map->map_3d)
		free_map3d(map->map_3d, map->row);
	if (map->map_str)
		free_str_arr(map->map_str);
	free(map);
}