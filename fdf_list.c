#include "fdf.h"

t_coordinate	*fdf_lstlast(t_coordinate *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst -> next != NULL)
	{
		lst = lst -> next;
	}
	return (lst);
}

void	fdf_lstadd_back(t_coordinate **lst, t_coordinate *new)
{
	t_coordinate	*pointer;

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

t_coordinate	*fdf_lstnew(char *numbers, int x, int y)
{
	t_coordinate	*line;

	line = malloc (sizeof(t_coordinate));
	line-> x = x * 30;
	line-> y = y * 30;
	line-> z = ft_atoi(numbers);
	line-> next = NULL;
	return (line);
}

void	get_struct(char **numbers, int y, t_coordinate **map)
{
	int				x;
	t_coordinate	*node;

	x = 0;
	while (numbers[x])
	{
		node = fdf_lstnew(numbers[x], x, y);
		fdf_lstadd_back(map, node);
		//free(numbers[y]);
		x++;
	}
	//free (numbers);
}