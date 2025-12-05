/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdharmar <tdharmar@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 12:01:11 by tdharmar          #+#    #+#             */
/*   Updated: 2025/12/05 13:11:19 by tdharmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_map	*parse_dime(char *file)
{
	int		fd;
	t_map	*map;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		exit_error(ERR_FILE_MSG);
	map = malloc(sizeof(t_map));
	if (!map)
	{
		close(fd);
		exit_error(ERR_MAL_MSG);
	}
	init_map_value(map);
	init_map_dime(map, fd);
	if (map->row == 0 || map->col == 0)
		exit_map(map, fd, ERR_MAP_MSG);
	close(fd);
	return (map);
}

void	parse_map(t_map *map, char *file)
{
	int	fd;
	char *line;
	int	row;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		exit_map(map, fd, ERR_FILE_MSG);
}