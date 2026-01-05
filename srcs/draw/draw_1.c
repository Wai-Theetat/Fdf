/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdharmar <tdharmar@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 15:37:31 by tdharmar          #+#    #+#             */
/*   Updated: 2026/01/05 10:55:45 by tdharmar         ###   ########.fr       */
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

static int	interpolate_channel(int start, int end, double t)
{
	return ((int)(start + t * (end - start)));
}

static int	interpolate_color(unsigned int start, unsigned int end, double t)
{
	int	res_r;
	int	res_g;
	int	res_b;
	int	res_a;

	res_r = interpolate_channel((start >> 24) & 0xFF, (end >> 24) & 0xFF, t);
	res_g = interpolate_channel((start >> 16) & 0xFF, (end >> 16) & 0xFF, t);
	res_b = interpolate_channel((start >> 8) & 0xFF, (end >> 8) & 0xFF, t);
	res_a = interpolate_channel(start & 0xFF, end & 0xFF, t);
	return ((res_r << 24) | (res_g << 16) | (res_b << 8) | res_a);
}

static void	draw_line_pixels(t_fdf *env, t_point_3D p1, t_point_3D p2,
		double max)
{
	double	x_step;
	double	y_step;
	double	current_step;
	int		color;

	x_step = (p2.x - p1.x) / max;
	y_step = (p2.y - p1.y) / max;
	current_step = 0;
	while ((int)current_step <= (int)max)
	{
		if (env->map->color_mode)
			color = interpolate_color(p1.pre_def_color,
					p2.pre_def_color, current_step / max);
		else
			color = interpolate_color(p1.altitude_color,
					p2.altitude_color, current_step / max);
		if (p1.x >= 0 && p1.x < WIDTH && p1.y >= 0 && p1.y < HEIGHT)
			mlx_put_pixel(env->screen, (int)p1.x, (int)p1.y, color);
		p1.x += x_step;
		p1.y += y_step;
		current_step++;
	}
}

void	draw_line(t_fdf *env, t_point_3D p1, t_point_3D p2)
{
	double	x_diff;
	double	y_diff;
	double	max;

	rotate_xyz(&p1.x, &p1.y, &p1.z, env->map);
	rotate_xyz(&p2.x, &p2.y, &p2.z, env->map);
	iso_project(&p1.x, &p1.y, p1.z, env->map);
	iso_project(&p2.x, &p2.y, p2.z, env->map);
	x_diff = p2.x - p1.x;
	y_diff = p2.y - p1.y;
	max = ft_max(ft_abs((int)x_diff), ft_abs((int)y_diff));
	draw_line_pixels(env, p1, p2, max);
}
