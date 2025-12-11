/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdharmar <tdharmar@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 11:40:05 by tdharmar          #+#    #+#             */
/*   Updated: 2025/12/11 16:12:05 by tdharmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_fdf	*init_fdf(char *file)
{
	static t_fdf	env;

	env.map = parse_dime(file);
	parse_map(env.map, file);
	create_point_n_spacing(env.map);
	convert_point_to_3d(env.map);
	set_altitude_color(env.map);
	adjust_window(env.map);
	//initiate_mlx()
	return (&env);
}

void	init_map_value(t_map *map)
{
	map->row = 0;
	map->col = 0;
	map->highest = INT_MIN;
	map->lowest = INT_MAX;
	map->spacing = 0;
	map->zoom = 0;
    map->shift_x = 0;
    map->shift_y = 0;
    map->angle_x = 0;
    map->angle_y = 0;
	map->angle_z = 0;
	map->z_scale = 1.0;
	map->map_2d = NULL;
	map->map_3d = NULL;
	map->map_str = NULL;
}

void	init_map_dime(t_map *map, int fd)
{
	char	*line;

	line = get_next_line(fd);
	if (!line)
		return ;
	if (line[ft_strlen(line) - 1] == '\n')
		line[ft_strlen(line) - 1] = '\0';
	map->col = ft_word_count(line, ' ');
	while (line)
	{
		if (line[ft_strlen(line) - 1] == '\n')
			line[ft_strlen(line) - 1] = '\0';
		if (ft_word_count(line, ' ') == 0)
			;
		else if (map->col != (int) ft_word_count(line, ' '))
		{
			gnl_cleanup(fd);
			free(line);
			exit_map(map, fd, ERR_MAP_MSG);
		}
		free(line);
		line = get_next_line(fd);
		map->row++;
	}
}
