/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldei-sva <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 19:15:11 by ldei-sva          #+#    #+#             */
/*   Updated: 2025/02/25 19:15:12 by ldei-sva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	my_pixel_put(t_data *data, int x, int y, int z)
{
	char	*dst;

	if (x <= 1920 && y <= 1080 && x >= 0 && y >= 0)
	{
		dst = data->addr + (y * data->lenght + x * (data->bits_per_pixel / 8));
		*(unsigned int *)dst = decide_color(z);
	}
}

void	create_window(t_node *map, int len, t_info *info)
{
	void			*mlx;
	t_node			new;
	t_data			img;
	int				r;

	r = len;
	mlx = mlx_init();
	img.win = mlx_new_window(mlx, 1920, 1080, "Fdf");
	img.img = mlx_new_image(mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, \
	&img.lenght, &img.endian);
	info->img = &img;
	info->mlx = mlx;
	draw_image(img, map, info, mlx);
	mlx_mouse_hook(img.win, mouse_hook, info);
	mlx_hook(img.win, 17, 0L, free_all, info);
	mlx_hook(img.win, 2, 1L << 0, key_hook, info);
	mlx_loop(mlx);
}

int	main(int ac, char **av)
{
	t_node	**map;
	int		len;
	t_info	*info;

	info = malloc(sizeof(t_info));
	map = get_data(av[1], info);
	len = get_lenline(*map);
	print_instructions();
	set_info(info, map, NULL, len);
	update_map(info);
	create_window(*map, len, info);
	free_all(info);
}
