/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldei-sva <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 19:24:39 by ldei-sva          #+#    #+#             */
/*   Updated: 2025/02/25 19:24:41 by ldei-sva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

char	**get_matrix(int fd, t_info *info)
{
	char	*line;
	char	*temp;
	char	*matrix;
	int		n;
	char	**map;

	matrix = ft_calloc(1, 1);
	line = get_next_line(fd);
	n = 0;
	while (line)
	{
		temp = matrix;
		matrix = ft_strjoin(matrix, line);
		free(temp);
		free(line);
		line = get_next_line(fd);
		n++;
	}
	info->map_height = n;
	map = ft_split(matrix, '\n');
	free(matrix);
	return (map);
}

t_node	**get_map(char **matrix, t_info *info)
{
	t_node	**map;
	t_node	*line;
	int		n;
	char	**numbers;

	n = 0;
	map = ft_calloc(info->map_height, sizeof(t_node *));
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

t_node	**get_data(char *file, t_info *info)
{
	int				fd;
	char			**matrix;
	t_node			**map;

	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		free(info);
		perror("Error");
		exit(0);
	}
	matrix = get_matrix(fd, info);
	close(fd);
	map = get_map(matrix, info);
	return (map);
}
