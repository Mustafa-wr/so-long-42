/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_all_valid.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mradwan <mradwan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 19:26:20 by mradwan           #+#    #+#             */
/*   Updated: 2022/11/15 17:00:19 by mradwan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	valid_map_x(t_map *m)
{
	int	i;
	int	w;

	i = 0;
	while (m->map[0][i] && m->map[0][i] != '\n')
	{
		if (m->map[0][i] != '1')
			return (0);
		i++;
	}
	i = 0;
	while (m->map[i])
		i++;
	i--;
	w = 0;
	while (m->map[i][w])
	{
		if (m->map[i][w] != '1')
			return (0);
		w++;
	}
	return (1);
}

int	valid_map_y(t_map *m)
{
	int	i;
	int	w;

	i = 0;
	while (m->map[i])
	{
		if (m->map[i][0] != '1')
			return (0);
		i++;
	}
	i = 0;
	w = 0;
	while (m->map[i][w] && m->map[i][w] != '\n')
		w++;
	w--;
	while (m->map[i])
	{
		if (m->map[i][w] != '1')
			return (0);
		i++;
	}
	return (1);
}

int	check_the_td(t_map *info)
{
	int	i;
	int	x;

	i = 0;
	x = 0;
	while (info->map[i])
	{
		x = 0;
		while (info->map[i][x])
		{
			if (info->map[i][x] == 'C' || info->map[i][x] == 'P' \
				|| info->map[i][x] == '1' || info->map[i][x] == '0' \
					|| info->map[i][x] == 'E' || info->map[i][x] == '\n')
					x++;
			else
				return (0);
		}
		i++;
	}
	return (1);
}

void	check_the_coin_and_exit(t_map *map)
{
	int	x;
	int	y;

	y = 0;
	x = 0;
	map->col = 0;
	map->exit_door = 0;
	while (map->map[y])
	{
		x = 0;
		while (map->map[y][x])
		{
			if (map->map[y][x] == 'C')
				map->col++;
			if (map->map[y][x] == 'E')
				map->exit_door++;
			x++;
		}
		y++;
	}
}
