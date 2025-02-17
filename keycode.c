#include "fdf.h"

int	key_hook(int keycode, t_parameters *parameters)
{
	if (keycode == 65307)
		exit(0);
	if (keycode == 65363)
		parameters->x += 10;
	printf("%d\n", keycode);
	return (0);
}