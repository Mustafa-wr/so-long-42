/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mradwan <mradwan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 16:47:20 by mradwan           #+#    #+#             */
/*   Updated: 2022/11/15 20:20:41 by mradwan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	last_check(int ac, char **av)
{
	t_map	info;
	int		d;

	d = num_args(ac, av);
	if (d == 0)
	{
		ft_printf("error");
		return (0);
	}
	if (readable_map(&info, av[1]) == 1)
		return (1);
	else
		ft_printf("fail");
	return (0);
}

static int	exit_x(t_map *map)
{
	mlx_destroy_window(map->mlx_init, map->mlx_win);
	destroy(map->map);
	destroy_all(map);
	exit(0);
	return (0);
}

void	destroy_all(t_map *all)
{
	mlx_destroy_image(all->mlx_init, all->coin);
	mlx_destroy_image(all->mlx_init, all->player);
	mlx_destroy_image(all->mlx_init, all->wall);
	mlx_destroy_image(all->mlx_init, all->empty);
	exit(0);
}

int	closet(int key, t_map *vars)
{
	if (key == 53)
	{
		mlx_destroy_window(vars->mlx_init, vars->mlx_win);
		destroy(vars->map);
		destroy_all(vars);
	}
	if (key == 13 || key == 126)
		player_move_up(vars);
	if (key == 1 || key == 125)
		player_move_down(vars);
	if (key == 2 || key == 124)
		player_move_right(vars);
	if (key == 0 || key == 123)
		player_move_left(vars);
	return (0);
}

int	main(int ac, char **av)
{
	t_map	map;

	map.counter = 1;
	if (!last_check(ac, av))
		return (0);
	if (readable_map(&map, av[1]))
	{
		read_map(&map);
		if (!all_paths_valid(&map))
			return (0);
		if (map.x == map.y)
		{
			ft_printf("\nerror the map should be rectangle");
			return (0);
		}
		draw_to_screen(&map);
	}
	mlx_hook(map.mlx_win, 2, 1L << 0, closet, &map);
	mlx_hook(map.mlx_win, 17, 0, exit_x, &map);
	mlx_loop(map.mlx_init);
}
