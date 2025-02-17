#include "fdf.h"

void	print_map(t_coordinate **map)
{
	while (*map)
	{
		ft_printf("x: %d, y: %d, z: %d\n", (*map)-> x, (*map)->y, (*map)->z);
		*map = (*map)->next;
	}
}

int	get_lenline(t_coordinate *map)
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

t_coordinate	*get_nextnode(t_coordinate *map, int len)
{
	while (len >= 0)
	{
		if  (map->next == NULL)
			return (NULL);
		map = map -> next;
		len--;
	}
	return (map);
}

int	get_position(t_coordinate *node, t_coordinate **map)
{
	int				index;
	t_coordinate	*copy;

	index = 0;
	copy = *map;
	while (copy != node)
	{
		index++;
		copy = copy -> next;
	}
	return (index);
}