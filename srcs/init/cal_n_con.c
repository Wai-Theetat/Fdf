/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cal_n_con.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdharmar <tdharmar@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/07 14:21:09 by tdharmar          #+#    #+#             */
/*   Updated: 2025/12/10 22:19:42 by tdharmar         ###   ########.fr       */
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
	while (point[i] >= '0' && point[i] <= 9)
}
