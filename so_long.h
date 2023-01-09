/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mradwan <mradwan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 17:17:20 by mradwan           #+#    #+#             */
/*   Updated: 2022/11/15 19:13:59 by mradwan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "mlx/mlx.h"
# include "ft_printf/ft_printf.h"
# include "gnl/get_next_line.h"

typedef struct t_map
{
	char	**map;
	char	**tmb_map;
	void	*wall;
	void	*coin;
	void	*empty;
	void	*player;
	void	*exit;
	int		width;
	int		height;
	void	*mlx_init;
	void	*mlx_win;
	int		x;
	int		y;
	int		x_pos;
	int		y_pos;
	int		col;
	int		exit_door;
	int		counter;
}	t_map;

int		num_args(int ac, char **av);
int		readable_map(t_map *info, char *k);
int		last_check(int ac, char **av);
void	read_map(t_map *map);
void	draw_to_screen(t_map *m);
void	player_move_up(t_map *move);
void	player_move_down(t_map *move);
void	player_move_right(t_map *move);
int		check_the_td(t_map *info);
void	player_move_left(t_map *move);
int		check_player_and_exit(t_map *map);
int		valid_map_x(t_map *m);
void	walking_in_map(int px, int py, char **map, t_map *path);
int		valid_map_y(t_map *m);
int		all_paths_valid(t_map *path);
void	checking_the_position(t_map *map);
void	tmb_tow_d(t_map *tmb);
char	*ft_strdup(char *src);
void	check_the_coin_and_exit(t_map *map);
void	draw_helper(t_map *m);
void	destroy_all(t_map *all);
void	destroy(char **map);

#endif