/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdharmar <tdharmar@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 12:47:40 by tdharmar          #+#    #+#             */
/*   Updated: 2025/12/02 21:32:37 by tdharmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../libft/libft.h"
# include "MLX42/MLX42.h"
# include "MLX42/MLX42_Int.h"
# include <stdbool.h>
# include <string.h>
# include <limits.h>
# include <fcntl.h>
# include <math.h>


# define FORMAT_ERR_MSG "Error:Invalid format : ./fdf <filename>.fdf"

typedef struct s_point_3D
{

	
}	t_point_3D;

typedef struct s_point_2D
{
	
}	t_point_2D;


void	exit_error(char *err_msg);
bool	is_valid_file_type(char *filename);


#endif