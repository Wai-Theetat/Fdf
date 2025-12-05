/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdharmar <tdharmar@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 12:47:40 by tdharmar          #+#    #+#             */
/*   Updated: 2025/12/05 11:44:51 by tdharmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../libft/libft.h"
# include "../libft/get_next_line.h"
# include "MLX42/MLX42.h"
# include "MLX42/MLX42_Int.h"
# include <stdbool.h>
# include <string.h>
# include <limits.h>
# include <fcntl.h>
# include <math.h>

# define WIDTH 1920
# define HEIGHT 1080

# define FORMAT_ERR_MSG "Error:Invalid format : ./fdf <filename>.fdf"

typedef struct s_point_3D
{
	double			x;
	double			y;
	double			z;
	unsigned int	map_color;
	unsigned int	z_color;
}	t_point_3D;

typedef struct s_point_2D
{
	double			x;
	double			y;
	unsigned int	rgba;
}	t_point_2D;

typedef struct s_map
{
	int			row;
	int			col;
	int			high;
	int			low;
	bool		use_z_color;
	double		x_offset;
	double		y_offset;
	double		interval;
	double		alpha;
	double		beta;
	double		x_rotate;
	double		y_rotate;
	double		z_rotate;
	double		zoom;
	double		z_scale;
	t_point_2D	**map2d;
	t_point_3D	**map3d;
	char		***map_str;
}	t_map;


typedef struct s_fdf
{
	mlx_t		*mlx;
	mlx_image_t	*screen;
	t_map		*map;
}	t_fdf;

void	exit_error(char *err_msg);
bool	is_valid_file_type(char *filename);

#endif