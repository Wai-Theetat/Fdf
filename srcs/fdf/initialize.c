/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdharmar <tdharmar@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 11:40:05 by tdharmar          #+#    #+#             */
/*   Updated: 2025/12/05 13:08:21 by tdharmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_fdf *init_fdf(char *file)
{
	static t_fdf	env;

	env.map = parse_dime(file);
	parse_map(env.map, file);
}

void	init_map_value(t_map *map)
{
	map->row = 0;
	map->col = 0;
	map->high = INT_MIN;
	map->map_2d = NULL;
	map->map_3d = NULL;
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
