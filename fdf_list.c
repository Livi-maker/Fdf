/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_list.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldei-sva <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 19:21:37 by ldei-sva          #+#    #+#             */
/*   Updated: 2025/02/25 19:21:39 by ldei-sva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_node	*fdf_lstlast(t_node *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst -> next != NULL)
	{
		lst = lst -> next;
	}
	return (lst);
}

void	fdf_lstadd_back(t_node **lst, t_node *new)
{
	t_node	*pointer;

	if (lst == NULL || new == NULL)
		return ;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	pointer = fdf_lstlast(*lst);
	pointer -> next = new;
}

t_node	*fdf_lstnew(char *numbers, int x, int y)
{
	t_node	*line;

	line = malloc (sizeof(t_node));
	line->x = x * 30;
	line->y = y * 30;
	line->z = ft_atoi(numbers);
	line->or_x = line->x;
	line->or_y = line->y;
	line->or_z = line->z;
	line->next = NULL;
	return (line);
}

void	get_struct(char **numbers, int y, t_node **map)
{
	int				x;
	t_node			*node;

	x = 0;
	while (numbers[x])
	{
		node = fdf_lstnew(numbers[x], x, y);
		fdf_lstadd_back(map, node);
		free(numbers[x]);
		x++;
	}
	free (numbers);
}
