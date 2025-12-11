/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cal_n_con.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdharmar <tdharmar@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/07 14:21:09 by tdharmar          #+#    #+#             */
/*   Updated: 2025/12/11 14:20:40 by tdharmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

double	calc_x(int col_in, t_map *map)
{
	int	centre;

	centre = (map->col - 1) * (map->spacing) / 2;
	return ((double)col_in *(map->spacing) - centre);
}

double	calc_y(int row_in, t_map *map)
{
	int	centre;

	centre = (map->row - 1) * (map->spacing) / 2;
	return ((double)row_in *(map->spacing) - centre);
}

double	conv_rgba(char *point, t_map *map)
{
	int	i;
	int	rgba;

	i = 0;
	while (point[i] && (ft_isdigit(point[i]) || point[i] == '-'))
		i++;
	if (point[i] != ',')
		return (WHITE);
	if (ft_strncmp(&point[i], ",0x", 3) != 0
		&& ft_strncmp(&point[i], ",0X", 3) != 0)
		exit_map(map, -1, ERR_MAP_MSG);
	i += 3;
	str_to_upper(&point[i]);
	rgba = ft_atoi_base_hex(&point[i]);
	return ((rgba << 8) | 0xFF);
}
