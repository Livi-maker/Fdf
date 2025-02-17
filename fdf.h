/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldei-sva <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 15:54:33 by ldei-sva          #+#    #+#             */
/*   Updated: 2025/01/15 15:55:12 by ldei-sva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <math.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/stat.h>
# include "libft.h"
# include "ft_printf.h"
# include "mlx.h"
# include "get_next_line.h"

typedef struct	s_data {
	void	*img;
	void	*win;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct	s_coordinate {
	int		y;
	int		x;
	int		z;
	struct s_coordinate	*next;
}				t_coordinate;

typedef struct	s_parameters {
	int	x;
	int	y;
}				t_parameters;

typedef struct	s_vars {
	void	*mlx;
	void	*win;
}				t_vars;

t_coordinate	**get_data(char *map);
void			get_struct(char **numbers, int x, t_coordinate **map);
int				get_lenline(t_coordinate *map);
t_coordinate	*get_nextnode(t_coordinate *map, int len);
void			update_map(t_coordinate *map);
void			print_map(t_coordinate **map);
int				get_position(t_coordinate *node, t_coordinate **map);
int				key_hook(int keycode, t_parameters *parameters);
void			set_parameters(t_parameters *parameters);

#endif
