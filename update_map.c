/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldei-sva <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 19:27:22 by ldei-sva          #+#    #+#             */
/*   Updated: 2025/02/25 19:27:24 by ldei-sva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

double	rad(int a)
{
	double		rad;
	double		p;

	p = 3.14159265 / 180;
	rad = a * p;
	return (rad);
}

void	rotation_x(t_info *info, t_node *map)
{
	if (info->rotx != 0)
	{
		map->y = map->y * cos(rad(info->rotx)) - map->z * sin(rad(info->rotx));
		map->z = map->y * sin(rad(info->rotx)) + map->z * cos(rad(info->rotx));
	}
}

void	rotation_y(t_info *info, t_node *map)
{
	if (info->roty != 0)
	{
		map->x = map->x * cos(rad(info->roty)) + map->z * sin(rad(info->roty));
		map->z = -map->x * sin(rad(info->roty)) + map->z * cos(rad(info->roty));
	}
}

void	rotation_z(t_info *info, t_node *map)
{
	if (info->rotz != 0)
	{
		map->x = map->x * cos(rad(info->rotz)) - map->y * sin(rad(info->rotz));
		map->y = map->x * sin(rad(info->rotz)) + map->y * cos(rad(info->rotz));
	}
}

void	update_map(t_info *info)
{
	t_node	*map;

	map = *(info->map);
	while (map)
	{
		map->y = map->or_y * info->zoom_in / info->zoom_out;
		map->x = map->or_x * info->zoom_in / info->zoom_out;
		map->z = map->or_z * info->height * info->zoom_in / info->zoom_out;
		rotation_z(info, map);
		rotation_x(info, map);
		rotation_y(info, map);
		if (map->next == NULL)
		{
			info->map_width = map->x / 2;
			info->map_height = map->y / 2;
		}
		map = map->next;
	}
}
