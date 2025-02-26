/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldei-sva <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 19:05:37 by ldei-sva          #+#    #+#             */
/*   Updated: 2025/02/25 19:05:40 by ldei-sva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	bigger(int dx, int dy, t_node *node, t_info *info)
{
	int	p;
	int	i;
	int	x;
	int	y;

	i = -1;
	p = 2 * abs(dx) - abs(dy);
	x = node->x;
	y = node->y;
	while (++i < abs(dy))
	{
		if (dy > 0)
			y += 1;
		else
			y -= 1;
		if (p < 0)
			p = p + 2 * abs(dx);
		else
			increase_xy(dx, dy, &x, &p);
		my_pixel_put(info->img, x + info->x - info->map_width, \
		y + info->y - info->map_height, node->or_z);
	}
}

void	slope_less_then_one(int dx, int dy, t_node *node, t_info *info)
{
	int	p;
	int	i;
	int	x;
	int	y;

	i = -1;
	p = 2 * abs(dy) - abs(dx);
	x = node->x;
	y = node->y;
	while (++i < abs(dx))
	{
		if (dx > 0)
			x += 1;
		else
			x -= 1;
		if (p < 0)
			p = p + 2 * abs(dy);
		else
			increase_xy(dy, dx, &y, &p);
		my_pixel_put(info->img, x + info->x - info->map_width, \
		y + info->y - info->map_height, node->or_z);
	}
}

void	draw_line(t_node *node, t_node *nextnode, t_data img, t_info *info)
{
	int	dx;
	int	dy;

	if (!nextnode)
		return ;
	dx = nextnode->x - node->x;
	dy = nextnode->y - node->y;
	if (abs(dx) > abs(dy))
		slope_less_then_one(dx, dy, node, info);
	else
		bigger(dx, dy, node, info);
}

void	draw_image(t_data img, t_node *map, t_info *info, void *mlx)
{
	int	r;

	r = info -> len;
	while (map && r >= 0)
	{
		draw_line(map, get_nextnode(map, info->len), img, info);
		if (r > 0)
			draw_line(map, map->next, img, info);
		map = map-> next;
		if (r == 0)
			r = info->len;
		else
			r--;
	}
	mlx_put_image_to_window(mlx, img.win, img.img, 0, 0);
}
