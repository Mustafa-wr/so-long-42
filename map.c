/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mradwan <mradwan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 17:27:08 by mradwan           #+#    #+#             */
/*   Updated: 2022/11/15 19:02:03 by mradwan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	read_map(t_map *map)
{
	map->mlx_init = mlx_init();
	map->width = 64;
	map->height = 64;
	map->mlx_win = mlx_new_window(map->mlx_init, map->x * 64, \
		map->y * 64, "so_long");
	map->wall = mlx_xpm_file_to_image(map->mlx_init, "xpm/wall.xpm", \
		&map->width, &map->height);
	map->player = mlx_xpm_file_to_image(map->mlx_init, "xpm/samurai.xpm", \
		&map->width, &map->height);
	map->empty = mlx_xpm_file_to_image(map->mlx_init, "xpm/space.xpm", \
		&map->width, &map->height);
	map->coin = mlx_xpm_file_to_image(map->mlx_init, "xpm/coin.xpm", \
		&map->width, &map->height);
	map->exit = mlx_xpm_file_to_image(map->mlx_init, "xpm/exit.xpm", \
		&map->width, &map->height);
}

char	*ft_strdup(char *src)
{
	char	*new;
	int		i;
	int		size;

	size = 0;
	new = malloc(sizeof(char) * (ft_strlen(src) + 1));
	if (!new)
		return (NULL);
	i = 0;
	while (src[i])
	{
		new[i] = src[i];
		i++;
	}
	new[i] = '\0';
	return (new);
}

void	destroy(char **map)
{
	t_map	m;
	int		y;

	y = 0;
	while (y < m.y)
	{
		free(map[y]);
		y++;
	}
	free(map);
}
