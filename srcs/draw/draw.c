/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdharmar <tdharmar@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 15:37:31 by tdharmar          #+#    #+#             */
/*   Updated: 2025/12/22 11:03:29 by tdharmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

void	iso_project(double *x, double *y, double z, t_map *map)
{
	double	prev_x;
	double	prev_y;

	prev_x = *x;
	prev_y = *y;
	*x = (prev_x - prev_y) * cos(0.523599);
	*y = -z + (prev_x + prev_y) * sin(0.523599);
	*x = (*x * map->zoom) + map->shift_x;
	*y = (*y * map->zoom) + map->shift_y;
}

void	draw_line(t_fdf *env, t_point_3D p1, t_point_3D p2)
{
	double	x_step;
	double	y_step;
	double	max;
	int		color;

	rotate_xyz(&p1.x, &p1.y, &p1.z, env->map);
	rotate_xyz(&p2.x, &p2.y, &p2.z, env->map);
	iso_project(&p1.x, &p1.y, p1.z, env->map);
	iso_project(&p2.x, &p2.y, p2.z, env->map);
	x_step = p2.x - p1.x;
	y_step = p2.y - p1.y;
	max = ft_max(ft_abs((int)x_step), ft_abs((int)y_step));
	x_step /= max;
	y_step /= max;
	if (env->map->color_mode)
		color = p1.pre_def_color;
	else
		color = p1.altitude_color;
	while ((int)(max--) >= 0)
	{
		if (p1.x >= 0 && p1.x < WIDTH && p1.y >= 0 && p1.y < HEIGHT)
			mlx_put_pixel(env->screen, (int)p1.x, (int)p1.y, color);
		p1.x += x_step;
		p1.y += y_step;
	}
}

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
				draw_line(fdf, fdf->map->map_3d[y][x], \
fdf->map->map_3d[y][x + 1]);
			if (y < fdf->map->row - 1)
				draw_line(fdf, fdf->map->map_3d[y][x], \
fdf->map->map_3d[y + 1][x]);
			x++;
		}
		y++;
	}
}
