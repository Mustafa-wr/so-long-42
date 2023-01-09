/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mradwan <mradwan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 14:00:40 by mradwan           #+#    #+#             */
/*   Updated: 2022/11/15 19:12:21 by mradwan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	walking_in_map(int px, int py, char **map, t_map *path)
{
	if (map[py][px] == '1' || map[py][px] == 'X')
		return ;
	if (map[py][px] == 'C')
		path->col--;
	else if (map[py][px] == 'E')
	{
		path->exit_door--;
		return ;
	}
	map[py][px] = 'X';
	walking_in_map(px + 1, py, map, path);
	walking_in_map(px - 1, py, map, path);
	walking_in_map(px, py - 1, map, path);
	walking_in_map(px, py + 1, map, path);
}

int	all_paths_valid(t_map *path)
{
	int		valid_collect;
	int		valid_exit;
	int		row;

	row = -1;
	valid_collect = path->col;
	valid_exit = path->exit_door;
	walking_in_map(path->x_pos, path->y_pos,
		path->tmb_map, path);
	while (++row < path->y)
		free(path->tmb_map[row]);
	free(path->tmb_map);
	if (path->col > 0 || path->exit_door > 0)
	{
		ft_printf("Error\nMap has one or more invalid path\nExiting");
		return (0);
	}
	path->col = valid_collect;
	path->exit_door = valid_exit;
	return (1);
}
