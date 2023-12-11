/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfontao- <gfontao-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 14:54:58 by gfontao-          #+#    #+#             */
/*   Updated: 2023/12/11 13:17:31 by gfontao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

t_bool move_packman(t_mlx_start *par, char direction, int status)
{
	t_bool flag;
	int x;
	int y;

	x = par->packman->x;
	y = par->packman->y;
	flag = FALSE;
	if (direction == 'a' && par->map->map[(par->packman->y - BORDER) / SCALE][(par->packman->x - MOVE_SPEED - BORDER) / SCALE] != '1')
		if (((par->packman->y - BORDER) % SCALE) == 0 || par->map->map[(par->packman->y - BORDER) / SCALE + 1][(par->packman->x - MOVE_SPEED - BORDER) / SCALE] != '1')
			par->packman->x -= MOVE_SPEED;
	if (direction == 'd' && par->map->map[(par->packman->y - BORDER) / SCALE][(par->packman->x - BORDER) / SCALE + 1] != '1')
		if (((par->packman->y - BORDER) % SCALE) == 0 || par->map->map[(par->packman->y - BORDER) / SCALE + 1][(par->packman->x - BORDER) / SCALE + 1] != '1')
			par->packman->x += MOVE_SPEED;
	if (direction == 'w' && par->map->map[(par->packman->y - MOVE_SPEED - BORDER) / SCALE][(par->packman->x - BORDER) / SCALE] != '1')
		if (((par->packman->x - BORDER) % SCALE) == 0 || par->map->map[(par->packman->y - MOVE_SPEED - BORDER) / SCALE][(par->packman->x - BORDER) / SCALE + 1] != '1')
			par->packman->y -= MOVE_SPEED;
	if (direction == 's' && par->map->map[(par->packman->y - BORDER) / SCALE + 1][(par->packman->x - BORDER) / SCALE] != '1')
		if (((par->packman->x - BORDER) % SCALE) == 0 || par->map->map[(par->packman->y - BORDER) / SCALE + 1][(par->packman->x - BORDER) / SCALE + 1] != '1')
			par->packman->y += MOVE_SPEED;
	if (x != par->packman->x || y != par->packman->y)
	{
		if (status == 0)
			par->packman->dir = par->packman->next;
		par->packman->prev = par->packman->dir;
		check_collectables(par);
		create_all(par, par->load_img);
		flag = TRUE;
	}
	else
		par->packman->dir = par->packman->prev;
	return (flag);
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
		mlx_exit(par, NULL, 0);
	}
}

int	key_hook(int keycode, t_mlx_start *par)
{
	par->packman->prev = par->packman->dir;
	if (keycode == 65307)
		mlx_exit(par, NULL, 0);
	if (keycode == 'a')
		par->packman->next = 'l';
	if (keycode == 'd')
		par->packman->next = 'r';
	if (keycode == 'w')
		par->packman->next = 'u';
	if (keycode == 's')
		par->packman->next = 'd';
	return (0);
}

int const_move(t_mlx_start *par)
{
	int flag = FALSE;

	if (par->packman->next == 'l')
		flag = move_packman(par, 'a', 0);
	else if (par->packman->next == 'r')
		flag = move_packman(par, 'd', 0);
	else if (par->packman->next == 'u')
		flag = move_packman(par, 'w', 0);
	else if (par->packman->next == 'd')
		flag = move_packman(par, 's', 0);
	if (flag == TRUE)
		return (0);
	if (par->packman->dir == 'l')
		flag = move_packman(par, 'a', 1);
	else if (par->packman->dir == 'r')
		flag = move_packman(par, 'd', 1);
	else if (par->packman->dir == 'u')
		flag = move_packman(par, 'w', 1);
	else if (par->packman->dir == 'd')
		flag = move_packman(par, 's', 1);
	return (0);
}
