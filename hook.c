/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldei-sva <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 19:25:31 by ldei-sva          #+#    #+#             */
/*   Updated: 2025/02/25 19:25:33 by ldei-sva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	rotations(int keycode, t_info *info)
{
	if (keycode == 65431)
		info->rotx += 1;
	if (keycode == 65433)
		info->rotx -= 1;
	if (keycode == 65430)
		info->roty -= 1;
	if (keycode == 65432)
		info->roty += 1;
	if (keycode == 65434)
		info->rotz -= 1;
}

void	orthografic_view(int keycode, t_info *info)
{
	if (keycode == 49)
	{
		info->roty = 0;
		info->rotx = 0;
		info->rotz = 0;
	}
	if (keycode == 50)
	{
		info->roty = 0;
		info->rotx = 90;
		info->rotz = 0;
	}
	if (keycode == 51)
	{
		info->rotx = 0;
		info->roty = 90;
		info->rotz = -90;
	}
}

int	key_hook(int keycode, t_info *info)
{
	t_data	*data;

	data = info->img;
	if (keycode == 65307)
		free_all(info);
	ft_bzero(data->addr, (1920 * 1080) * ((data->bits_per_pixel) / 8));
	if (keycode == 65363 && info->x <= 1900)
		info->x += 20;
	if (keycode == 65362 && info->y >= 20)
		info->y -= 20;
	if (keycode == 65364 && info->y <= 1060)
		info->y += 20;
	if (keycode == 65361 && info->x >= 20)
		info->x -= 20;
	if (keycode == 61 || keycode == 65451)
		info->height += 2;
	if (keycode == 45 || keycode == 65453)
		info->height -= 2;
	rotations(keycode, info);
	orthografic_view(keycode, info);
	update_map(info);
	draw_image(*(info->img), *(info->map), info, info->mlx);
	return (0);
}

int	mouse_hook(int keycode, int x, int y, t_info *info)
{
	t_data	*data;

	data = info->img;
	ft_bzero(data->addr, (1920 * 1080) * ((data->bits_per_pixel) / 8));
	if (keycode == 4)
		info->zoom_in += 1;
	if (keycode == 5)
		info->zoom_out += 1;
	if (keycode == 1)
	{
		info->x = x;
		info->y = y;
	}
	update_map(info);
	draw_image(*(info->img), *(info->map), info, info->mlx);
	return (0);
}
