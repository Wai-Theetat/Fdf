/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_checker.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdharmar <tdharmar@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 21:10:16 by tdharmar          #+#    #+#             */
/*   Updated: 2025/12/02 21:16:50 by tdharmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

bool	is_valid_file_type(char *filename)
{
	size_t	len;

	len = ft_strlen(filename);
	if (len < 5)
		return (false);
	if (ft_strncmp(&filename[len - 4], ".fdf", 5) != 0)
		return (false);
	return (true);
}