/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parameters.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldei-sva <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 19:26:32 by ldei-sva          #+#    #+#             */
/*   Updated: 2025/02/25 19:26:34 by ldei-sva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	set_info(t_info *info, t_node **map, t_data *img, int len)
{
	info->height = 20;
	info->map = map;
	info->img = img;
	info->len = len;
	info->roty = 30;
	info->rotx = 45;
	info->rotz = 0;
	info->zoom_in = 1;
	info->zoom_out = 1;
	info->x = 960;
	info->y = 540;
}

void	print_instructions(void)
{
	ft_printf("rotate left = 4\nrotate right = 6\n");
	ft_printf("rotate up = 8\nrotate down = 2\n");
	ft_printf("choose position = mouse left botton\n");
	ft_printf("translate up|down|left|right = arrows\n");
	ft_printf("Orthographic projection = 1 or 2 or 3 on\
	left side of the keyboard");
}

int	decide_color(int z)
{
	if (z <= 0)
		return (0x0000FF);
	if (z > 0)
		return (0xA020F0);
	return (0x0000FF);
}
