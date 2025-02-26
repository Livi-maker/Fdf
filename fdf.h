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

typedef struct s_data
{
	void	*img;
	void	*win;
	char	*addr;
	int		bits_per_pixel;
	int		lenght;
	int		endian;
}				t_data;

typedef struct s_node
{
	int				y;
	int				x;
	int				z;
	int				or_x;
	int				or_y;
	int				or_z;
	struct s_node	*next;
}				t_node;

typedef struct s_info
{
	int				x;
	int				y;
	int				height;
	int				rotx;
	int				roty;
	int				rotz;
	int				zoom_in;
	int				zoom_out;
	t_node			**map;
	t_data			*img;
	int				len;
	void			*mlx;
	int				map_height;
	int				map_width;

}				t_info;

typedef struct s_vars
{
	void	*mlx;
	void	*win;
}				t_vars;

t_node			**get_data(char *map, t_info *info);
void			get_struct(char **numbers, int x, t_node **map);
int				get_lenline(t_node *map);
t_node			*get_nextnode(t_node *map, int len);
void			update_map(t_info *info);
void			print_map(t_node **map);
int				get_position(t_node *node, t_node **map);
int				key_hook(int keycode, t_info *info);
void			set_info(t_info *info, t_node **map, t_data *img, int len);
void			draw_image(t_data img, t_node *map, t_info *info, void *mlx);
void			my_pixel_put(t_data *data, int x, int y, int z);
void			update_height(t_info *info);
void			fdf_lstadd_back(t_node **lst, t_node *new);
int				decide_color(int z);
int				mouse_hook(int keycode, int x, int y, t_info *info);
void			free_struct(t_node **map);
void			print_instructions(void);
int				free_all(t_info *info);
void			increase_xy(int dx, int dy, int *v, int *p);

#endif
