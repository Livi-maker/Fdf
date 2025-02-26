/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldei-sva <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 19:23:51 by ldei-sva          #+#    #+#             */
/*   Updated: 2025/02/25 19:23:53 by ldei-sva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	print_map(t_node **map)
{
	while (*map)
	{
		ft_printf("x: %d, y: %d, z: %d\n", (*map)-> x, (*map)->y, (*map)->z);
		*map = (*map)->next;
	}
}

int	get_lenline(t_node *map)
{
	int				d;

	d = 0;
	while (map->y == ((map->next))->y)
	{
		map = map->next;
		d++;
	}
	return (d);
}

t_node	*get_nextnode(t_node *map, int len)
{
	while (len >= 0)
	{
		if (map->next == NULL)
			return (NULL);
		map = map -> next;
		len--;
	}
	return (map);
}

int	get_position(t_node *node, t_node **map)
{
	int				index;
	t_node			*copy;

	index = 0;
	copy = *map;
	while (copy != node)
	{
		index++;
		copy = copy -> next;
	}
	return (index);
}

void	increase_xy(int dx, int dy, int *v, int *p)
{
	if (dx > 0)
		*v += 1;
	else
		*v -= 1;
	*p = *p + 2 * abs(dx) - 2 * abs(dy);
}
