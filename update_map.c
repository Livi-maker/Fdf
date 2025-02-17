#include "fdf.h"

void	update_map(t_coordinate *map)
{
	while (map)
	{
		if (map->z != 0)
		{

			map->x = (map->x - map->z);
			map->y = (map->y - map->z);
		}
		//map->x = map->x * cos(45) - map->y * sin(45);
		//map->y = map->x * sin(45) + map->y * cos(45);
		map = map->next;
	}
}