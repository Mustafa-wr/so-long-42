/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   par.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mradwan <mradwan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 21:51:28 by mradwan           #+#    #+#             */
/*   Updated: 2022/11/15 19:01:21 by mradwan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"

int	num_args(int ac, char **av)
{
	int	i;

	i = 0;
	if (ac == 2)
	{
		while (av[1][i])
		{	
			i++;
			if (av[1][i] == '.')
			{
				i++;
				if (av[1][i] != 'b')
				{
					ft_printf("there is no ber file");
					return (0);
				}
				if (av[1][i] == 'b' && av[1][i + 1] == 'e'
						&& av[1][i + 2] == 'r' && av[1][i + 3] == '\0')
					return (1);
			}
		}
	}
	return (0);
}

static int	init_map(t_map *info, char *k)
{
	int		fd;
	char	*line;
	int		i;

	fd = open(k, O_RDONLY);
	if (fd < 0)
		return (0);
	line = get_next_line(fd);
	free(line);
	info->y = 0;
	while (line != NULL)
	{
		line = get_next_line(fd);
		free(line);
		info->y++;
	}
	close(fd);
	i = 0;
	info->map = malloc(sizeof(char *) * (info->y + 1));
	info->tmb_map = malloc(sizeof(char *) * (info->y + 1));
	if (!info->tmb_map || !info->map)
		return (0);
	info->map[info->y] = NULL;
	return (1);
}

int	readable_map(t_map *info, char *k)
{
	int		fd;
	int		i;

	i = 0;
	if (!init_map(info, k))
		return (0);
	fd = open(k, O_RDONLY);
	if (fd < 0)
		return (0);
	while (i < info->y)
	{
		info->map[i] = get_next_line(fd);
		info->tmb_map[i] = ft_strdup(info->map[i]);
		info->map[i][ft_strlen(info->map[i])] = '\0';
		info->tmb_map[i][ft_strlen(info->map[i])] = '\0';
		i++;
	}
	info->x = ft_strlen(info->map[0]) - 1;
	close(fd);
	if (!check_the_td(info) || !check_player_and_exit(info) || \
		!valid_map_x(info) || !valid_map_y(info))
		return (0);
	check_the_coin_and_exit(info);
	return (1);
}

int	check_player_and_exit(t_map *map)
{
	int	i;
	int	x;
	int	y;

	y = 0;
	i = 0;
	while (map->map[y])
	{
		x = 0;
		while (map->map[y][x])
		{
			if (map->map[y][x] == 'P' || map->map[y][x] == 'E')
			{
				if (map->map[y][x] == 'P')
				{
					map->y_pos = y;
					map->x_pos = x;
				}
				i++;
			}
			x++;
		}
		y++;
	}
	return (i == 2);
}
