/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handle.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdharmar <tdharmar@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 21:06:12 by tdharmar          #+#    #+#             */
/*   Updated: 2025/12/05 14:30:24 by tdharmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	exit_error(char *err_msg)
{
	ft_putstr_fd(err_msg, 2);
	exit(EXIT_FAILURE);
}

void	exit_map(t_map *m, int fd, char *err_msg)
{
	free_map(m);
	if (fd < 0)
		close(fd);
	exit_error(err_msg);
}

