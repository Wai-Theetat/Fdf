/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdharmar <tdharmar@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 12:46:42 by tdharmar          #+#    #+#             */
/*   Updated: 2025/12/10 22:09:41 by tdharmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char **argv)
{
	t_fdf	*env;

	if (argc != 2 || !is_valid_file_type(argv[1]))
		exit_error(ERR_FORMAT_MSG);
	env = init_fdf(argv[1]);
	return (0);
}
