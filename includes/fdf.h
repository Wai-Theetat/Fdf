/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdharmar <tdharmar@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 12:47:40 by tdharmar          #+#    #+#             */
/*   Updated: 2025/12/22 12:11:55 by tdharmar         ###   ########.fr       */
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

# define ERR_FORMAT_MSG "Error:Invalid format : ./fdf <filename>.fdf"
# define ERR_FILE_MSG "Error: File cannot opened"
# define ERR_MAL_MSG "Error: Failed to malloc"
# define ERR_MAP_MSG "Error: Invalid map"
# define ERR_MLX_MSG "Error: MLX Failed"

# define WHITE 0xFFFFFFFF
# define COLOR_LOW 0x0000FFFF  // Blue
# define COLOR_HIGH 0xFF0000FF // Red

typedef struct s_point_3D
{
	double			x;
	double			y;
	double			z;
	unsigned int	pre_def_color;
	unsigned int	altitude_color;
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
	int			lowest;
	int			highest;
	double		spacing;
	double		zoom;
	int			shift_x;
	int			shift_y;
	double		angle_x;
	double		angle_y;
	double		angle_z;
	double		z_scale;
	t_point_2D	**map_2d;
	t_point_3D	**map_3d;
	char		***map_str;
	bool		color_mode;
}	t_map;

typedef struct s_fdf
{
	mlx_t		*mlx;
	mlx_image_t	*screen;
	t_map		*map;
}	t_fdf;

void	exit_error(char *err_msg);
void	exit_map(t_map *m, int fd, char *err_msg);

bool	is_valid_file_type(char *filename);

//Initialize
t_fdf	*init_fdf(char *file);
t_map	*parse_dime(char *file);
void	init_map_value(t_map *map);
void	init_map_dime(t_map *map, int fd);
void	parse_map(t_map *map, char *file);
void	create_point_n_spacing(t_map *map);
void	convert_point_to_3d(t_map *map);
void	adjust_window(t_map *map);

//Drawing
void	draw_map(t_fdf *fdf);
void	draw_line(t_fdf *fdf, t_point_3D p1, t_point_3D p2);
void	iso_project(double *x, double *y, double z, t_map *map);

// Hooks
void	key_hook(mlx_key_data_t keydata, void *param);
void	clear_image(t_fdf *env);

// Rotate
void	rotate_xyz(double *x, double *y, double *z, t_map *map);

//Convert and Calculation
double	calc_x(int col_in, t_map *map);
double	calc_y(int row_in, t_map *map);
double	conv_rgba(char *point, t_map *map);

// color
int		get_hex_val(char c);
int		ft_atoi_base_hex(const char *str);
void	str_to_upper(char *str);

// set-color
void	set_altitude_color(t_map *map);

//Misc
int		ft_word_count(const char *str, char c);
int		ft_min(int a, int b);
int		ft_max(int a, int b);
int		ft_abs(int a);

//Free
// Map
void	free_map(t_map *map);
void	free_str_arr(char ***arr);
void	free_map3d(t_point_3D **map3d, int n);
void	free_map2d(t_point_2D **map2d, int n);

#endif