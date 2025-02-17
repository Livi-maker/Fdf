#include "fdf.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	find_y(int x, t_coordinate *node, t_coordinate *nextnode)
{
	float	parameter;
	int		y;

	parameter = ((float)x - (float)node->x)/((float)nextnode->x - (float)node->x);
	parameter = parameter * ((float)nextnode->y - (float)node->y) + (float)node->y;
	y = parameter;
	return (y);
}

int	find_x(int y, t_coordinate *node, t_coordinate *nextnode)
{
	float	parameter;
	int	x;

	parameter = ((float)y - (float)node->y)/((float)nextnode->y - (float)node->y);
	parameter = parameter * ((float)nextnode->x - (float)node->x) + (float)node->x;
	x = parameter;
	return (x);
}

void	draw_vertical(t_coordinate *node, t_data img, int len, t_parameters *parameters)
{

	t_coordinate	*nextnode;
	int				x;
	int				y;

	x = node -> x;
	y = node -> y;
	nextnode = get_nextnode(node, len);
	if (!nextnode)
		return ;
	while (y != nextnode -> y)
	{
		my_mlx_pixel_put(&img, x + parameters->x, y + parameters->y, 0x0000FF);
		if (x == nextnode -> x)
		{
			y++;
		}
		else
		{
			if (x < nextnode -> x)
				x++;
			else if (x > nextnode -> x)
				x--;
			y = find_y(x, node, nextnode);
		}

	}
}

void	draw_horizontal(t_coordinate *node, t_coordinate *nextnode, t_data img, t_parameters *parameters)
{
	int	x;
	int	y;

	if (!nextnode)
		return ;
	x = node->x;
	y = node->y;
	while (x != nextnode -> x)
	{
		my_mlx_pixel_put(&img, x + parameters->x, y + parameters->y, 0x0000FF);
		if (y == nextnode -> y)
		{
			x++;
		}
		else
		{
			if (y < nextnode -> y)
				y++;
			else if (y > nextnode -> y)
				y--;
			x = find_x(y, node, nextnode);
		}
	}
}

void	create_window(t_coordinate **map, int len, t_parameters *parameters)
{
	void			*mlx;
	t_coordinate	new;
	t_data			img;
	int				r;
	t_coordinate	**copy;

	copy = map;
	r = len;
	mlx = mlx_init();
	img.win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
	img.img = mlx_new_image(mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	mlx_key_hook(img.win, key_hook, parameters);
	while (*map && r >= 0)
	{
		draw_vertical(*map, img, len, parameters);
		if (r > 0)
			draw_horizontal(*map, (*map)->next, img, parameters);
		(*map) = (*map)-> next;
		if (r == 0)
			r = len;
		else
			r--;
	}
	mlx_put_image_to_window(mlx, img.win, img.img, 0, 0);
	mlx_loop(mlx);
}

int	main(int ac, char **av)
{
	t_coordinate	**map;
	int				len;
	t_parameters	*parameters;

	parameters = malloc(sizeof(t_parameters));
	map = get_data(av[1]);
	len = get_lenline(*map);
	set_parameters(parameters);
	update_map(*map);
	create_window(map, len, parameters);
}