/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_free.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldei-sva <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 19:18:55 by ldei-sva          #+#    #+#             */
/*   Updated: 2025/02/25 19:18:57 by ldei-sva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	free_struct(t_node **map)
{
	t_node	*temp;

	while (*map)
	{
		temp = *map;
		*map = (*map)->next;
		free (temp);
	}
	free (map);
}

int	free_all(t_info *info)
{
	mlx_destroy_window(info->mlx, (info->img)->win);
	mlx_destroy_display(info->mlx);
	free_struct(info->map);
	free(info);
	exit(0);
}
