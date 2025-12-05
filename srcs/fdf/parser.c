/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdharmar <tdharmar@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 12:01:11 by tdharmar          #+#    #+#             */
/*   Updated: 2025/12/05 13:48:36 by tdharmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void update_map_HL(t_map *m)
{
	int	row;
	int	col;
	int	altitude;

	row = -1;
	while (++row < m->row)
	{
		col = -1;
		while (++col < m->col)
		{
			altitude = ft_atoi(m->map_str[row][col]);
			m->lowest = ft_min(m->lowest, altitude);
			m->highest = ft_max(m->highest, altitude);
		}
	}
}

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

	row = -1;
	fd = open(file, O_RDONLY);
	if (fd < 0)
		exit_map(map, fd, ERR_FILE_MSG);
	map->map_str = ft_calloc(map->row + 1, sizeof(char **));
	if (!(map->map_str))
		exit_map(map, fd, ERR_MAL_MSG);
	while (++row < map->row)
	{
		line = get_next_line(fd);
		if (!line)
			exit_map(map, fd, ERR_MAL_MSG);
		if (line[ft_strlen(line) - 1] == '\n')
			line[ft_strlen(line) - 1] = '\0';
		map->map_str[row] = ft_split(line, ' ');
		if (!map->map_str[row])
			exit_map(map, fd, ERR_MAL_MSG);
		free(line);
	}
	gnl_cleanup(fd);
	update_map_HL(map);
}

