/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfontao- <gfontao-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 11:15:39 by gfontao-          #+#    #+#             */
/*   Updated: 2023/12/04 13:52:32 by gfontao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	check_line(t_map *map)
{
	int	ctd;

	map->cols = ft_strlen(map->map[0]);
	ctd = 0;
	while (ctd < map->rows)
		if (ft_strlen(map->map[ctd++]) != (size_t)map->cols)
			freemap(map, "Map must be rectangular", 1);
}

void	check_map(t_map *map)
{
	int			ctd;
	int			ctd2;

	ctd = -1;
	map->check.player = 0;
	map->check.exit = 0;
	map->collectibles_count = 0;
	while (map->map[++ctd])
	{
		ctd2 = -1;
		while (map->map[ctd][++ctd2])
		{
			if (ft_strchr(LEGAL_CHARS, map->map[ctd][ctd2]) == NULL)
				freemap(map, "Invalid character in map", 1);
			if (map->map[ctd][ctd2] == 'P')
				map->check.player++;
			else if (map->map[ctd][ctd2] == 'E')
				map->check.exit++;
			else if (map->map[ctd][ctd2] == 'C')
				map->collectibles_count++;
		}
	}
	if (map->check.player != 1)
		freemap(map, "Invalid number of players", 1);
	if (map->check.exit != 1)
		freemap(map, "Invalid number of exits", 1);
}

void	read_map(t_map *map, int count, int fd)
{
	char	*line;

	line = get_next_line(fd);
	if (line != NULL)
		read_map(map, count + 1, fd);
	else
	{
		if (count == 0)
			error_message("Empty file");
		map->map = malloc(sizeof(char *) * (count + 1));
		if (map->map == NULL)
			error_message("Error allocating memory");
		map->rows = count;
	}
	if (line)
	{
		map->map[count] = ft_strtrim(line, "\n");
		free(line);
	}
	else
		map->map[count] = NULL;
}

void initiate_flood(t_map *map)
{
	if (map->map[map->check.player_x][map->check.player_y] == 'P')
	{
		allocate_visited(map);
		map->check.collectibles = map->collectibles_count;
		flood_fill(map, map->check.player_x, map->check.player_y);
		free_matrix(map, 0, map->rows - 1);
		if (map->check.collectibles != 0 || map->check.exit != 0)
			freemap(map, "Exit or collectibles not reachable", 1);
	}
}

void	read_input(int argc, char **argv, t_map *map)
{
	int	input_len;
	int	fd;

	if (argc != 2)
		error_message("Invalid number of arguments");
	input_len = ft_strlen(argv[1]);
	if (input_len < 5 || ft_strncmp(argv[1] + input_len - 4, ".ber", 4) != 0)
		error_message("Invalid file, must be a .ber file");
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		error_message("Error opening file");
	read_map(map, 0, fd);
	close(fd);
	validate_map(map);
	initiate_flood(map);
}
