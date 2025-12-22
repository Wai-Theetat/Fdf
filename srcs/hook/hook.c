/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdharmar <tdharmar@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/20 14:31:52 by tdharmar          #+#    #+#             */
/*   Updated: 2025/12/22 10:27:28 by tdharmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	clear_image(t_fdf *env)
{
	ft_bzero(env->screen->pixels, WIDTH * HEIGHT * sizeof(int));
}

static void	hook_translate(mlx_key_data_t keydata, t_fdf *env)
{
	if (keydata.key == MLX_KEY_UP)
		env->map->shift_y -= 10;
	else if (keydata.key == MLX_KEY_DOWN)
		env->map->shift_y += 10;
	else if (keydata.key == MLX_KEY_LEFT)
		env->map->shift_x -= 10;
	else if (keydata.key == MLX_KEY_RIGHT)
		env->map->shift_x += 10;
}

static void	hook_controls(mlx_key_data_t keydata, t_fdf *env)
{
	if (keydata.key == MLX_KEY_Q)
		env->map->angle_z -= 0.05;
	else if (keydata.key == MLX_KEY_E)
		env->map->angle_z += 0.05;
	else if (keydata.key == MLX_KEY_W)
		env->map->z_scale += 0.1;
	else if (keydata.key == MLX_KEY_S)
		env->map->z_scale -= 0.1;
	else if (keydata.key == MLX_KEY_SPACE && keydata.action == MLX_PRESS)
		env->map->color_mode = !env->map->color_mode;
}

static void	hook_zoom(mlx_key_data_t keydata, t_fdf *env)
{
	if (keydata.key == MLX_KEY_EQUAL)
		env->map->zoom += 0.05;
	else if (keydata.key == MLX_KEY_MINUS)
		env->map->zoom -= 0.05;
}

void	key_hook(mlx_key_data_t keydata, void *param)
{
	t_fdf	*env;

	env = (t_fdf *)param;
	if (keydata.action == MLX_RELEASE && keydata.key != MLX_KEY_SPACE)
		return ;
	if (keydata.key == MLX_KEY_ESCAPE)
		mlx_close_window(env->mlx);
	hook_translate(keydata, env);
	hook_controls(keydata, env);
	hook_zoom(keydata, env);
	clear_image(env);
	draw_map(env);
}
