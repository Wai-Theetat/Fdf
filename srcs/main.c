/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdharmar <tdharmar@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 12:46:42 by tdharmar          #+#    #+#             */
/*   Updated: 2025/12/20 16:30:18 by tdharmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char **argv)
{
	int		i;
	t_fdf	*env;

	if (argc != 2 || !is_valid_file_type(argv[1]))
		exit_error(ERR_FORMAT_MSG);
	env = init_fdf(argv[1]);
	if (!env->screen || mlx_image_to_window(env->mlx, env->screen, 0, 0) < 0)
	{
		mlx_terminate(env->mlx);
		exit_map(env->map, -1, ERR_MLX_MSG);
	}
	draw_map(env);
	mlx_key_hook(env->mlx, key_hook, env);
	mlx_loop(env->mlx);
	mlx_terminate(env->mlx);
	free_map(env->map);
	return (0);
}
