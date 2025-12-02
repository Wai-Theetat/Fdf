/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdharmar <tdharmar@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 12:46:42 by tdharmar          #+#    #+#             */
/*   Updated: 2025/12/02 21:18:30 by tdharmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char **argv)
{
	if (argc != 2 || !is_valid_file_type(argv[1]))
		exit_error(FORMAT_ERR_MSG);

	return (0);
}
