#include "fdf.h"

char	**get_matrix(int fd)
{
	char	*line;
	char	**matrix;
	int		n;

	matrix = malloc(25000 * sizeof(char *));
	line = get_next_line(fd);
	n = 0;
	while (line)
	{
		matrix[n] = line;
		line = get_next_line(fd);
		n++;
	}
	close(fd);
	return (matrix);
}

t_coordinate	**get_map(char **matrix)
{
	t_coordinate	**map;
	t_coordinate	*line;
	int				n;
	char			**numbers;

	n = 0;
	map = malloc(25000 * sizeof(t_coordinate *));
	while (matrix[n])
	{
		numbers = ft_split(matrix[n], ' ');
		free(matrix[n]);
		get_struct(numbers, n, map);
		n++;
	}
	free(matrix);
	return (map);
}

t_coordinate	**get_data(char *file)
{
	int				fd;
	char			**matrix;
	t_coordinate	**map;

	fd = open(file, O_RDONLY);
	matrix = get_matrix(fd);
	map = get_map(matrix);
	return (map);
}
