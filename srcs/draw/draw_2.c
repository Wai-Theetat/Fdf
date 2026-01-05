/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdharmar <tdharmar@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 10:10:47 by tdharmar          #+#    #+#             */
/*   Updated: 2026/01/05 10:12:07 by tdharmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_map(t_fdf *fdf)
{
	int	x;
	int	y;

	y = 0;
	while (y < fdf->map->row)
	{
		x = 0;
		while (x < fdf->map->col)
		{
			if (x < fdf->map->col - 1)
				draw_line(fdf, fdf->map->map_3d[y][x],
					fdf->map->map_3d[y][x + 1]);
			if (y < fdf->map->row - 1)
				draw_line(fdf, fdf->map->map_3d[y][x],
					fdf->map->map_3d[y + 1][x]);
			x++;
		}
		y++;
	}
}
