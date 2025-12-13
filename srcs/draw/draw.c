/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdharmar <tdharmar@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 15:37:31 by tdharmar          #+#    #+#             */
/*   Updated: 2025/12/13 16:18:53 by tdharmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

void	draw_map(t_fdf *env)
{
	int	x;
	int	y;

	y = 0;
	while (y < env->map->row)
	{
		x = 0;
		while (x < env->map->col)
		{
			if (x < env->map->col - 1)
				draw_line(env, env->map->map_3d[y][x], env->map->map_3d[y][x + 1]);
			if (y < env->map->row - 1)
				draw_line(env, env->map->map_3d[y][x], env->map->map_3d[y + 1][x]);
			x++;
		}
		y++;
	}
}
