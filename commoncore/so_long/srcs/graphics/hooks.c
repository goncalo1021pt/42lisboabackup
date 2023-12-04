/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfontao- <gfontao-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 14:54:58 by gfontao-          #+#    #+#             */
/*   Updated: 2023/12/04 11:00:35 by gfontao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

int	close_window(t_mlx_start *par)
{
	mlx_destroy_window(par->mlx, par->mlx_win);
	freemap(par->map, NULL, 0);
	return (0);
}

void move_packman(t_mlx_start *par, char direction)
{
	if (direction == 'a' && par->map->map[(par->packman->y - BORDER) / SCALE][(par->packman->x - 10 - BORDER) / SCALE] != '1')
		if (((par->packman->y - BORDER) % SCALE) == 0 || par->map->map[(par->packman->y - BORDER) / SCALE + 1][(par->packman->x - 10 - BORDER) / SCALE] != '1')
			par->packman->x -= 10;
	if (direction == 'd' && par->map->map[(par->packman->y - BORDER) / SCALE][(par->packman->x - BORDER) / SCALE + 1] != '1')
		if (((par->packman->y - BORDER) % SCALE) == 0 || par->map->map[(par->packman->y - BORDER) / SCALE + 1][(par->packman->x - BORDER) / SCALE + 1] != '1')
			par->packman->x += 10;
	if (direction == 'w' && par->map->map[(par->packman->y - 10 - BORDER) / SCALE][(par->packman->x - BORDER) / SCALE] != '1')
		if (((par->packman->x - BORDER) % SCALE) == 0 || par->map->map[(par->packman->y - 10 - BORDER) / SCALE][(par->packman->x - BORDER) / SCALE + 1] != '1')
			par->packman->y -= 10;
	if (direction == 's' && par->map->map[(par->packman->y - BORDER) / SCALE + 1][(par->packman->x - BORDER) / SCALE] != '1')
		if (((par->packman->x - BORDER) % SCALE) == 0 || par->map->map[(par->packman->y - BORDER) / SCALE + 1][(par->packman->x - BORDER) / SCALE + 1] != '1')
			par->packman->y += 10;
	check_collectables(par);
}

void	check_collectables(t_mlx_start *par)
{
	int	x;
	int	y;

	x = (par->packman->x - BORDER) / SCALE;
	y = (par->packman->y - BORDER) / SCALE;
	if ((par->packman->y - BORDER) % SCALE != 0 || (par->packman->x - BORDER) % SCALE != 0)
		return ;
	if (par->map->map[y][x] == 'C')
	{
		par->map->map[y][x] = '0';
		par->map->collectibles_count--;
	}
	if (par->map->collectibles_count == 0 && par->map->map[y][x] == 'E')
	{
		ft_printf("You win!\n");
		mlx_destroy_window(par->mlx, par->mlx_win);
		freemap(par->map, NULL, 0);
	}
}

int	key_hook(int keycode, t_mlx_start *par)
{
	if (keycode == 65307)
	{
		mlx_destroy_window(par->mlx, par->mlx_win);
		freemap(par->map, NULL, 0);
	}
	if (keycode == 'a')
		move_packman(par, 'a');
	if (keycode == 'd')
		move_packman(par, 'd');
	if (keycode == 'w')
		move_packman(par, 'w');
	if (keycode == 's')
		move_packman(par, 's');
	else
		ft_printf("%i\n", keycode);
	printf("x: %i\ny: %i\n", par->packman->x, par->packman->y);
	put_image(par);
	return (0);
}