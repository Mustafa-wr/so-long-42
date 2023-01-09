/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mradwan <mradwan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 15:56:50 by mradwan           #+#    #+#             */
/*   Updated: 2022/11/15 20:27:29 by mradwan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	player_move_up(t_map *move)
{
	if (move->map[--move->y_pos][move->x_pos] != '1')
	{
		if (move->map[move->y_pos][move->x_pos] == 'E' && move->col == 0)
		{
			ft_printf("total moves %d\n", move->counter++);
			mlx_destroy_window(move->mlx_init, move->mlx_win);
			destroy(move->map);
			destroy_all(move);
		}
		else if (move->map[move->y_pos][move->x_pos] == 'C')
			move->col--;
		else if (move->map[move->y_pos][move->x_pos] == 'E' && move->col != 0)
		{
			move->y_pos++;
			draw_to_screen(move);
			return ;
		}
		ft_printf("total moves %d\n", move->counter++);
		mlx_clear_window(move->mlx_init, move->mlx_win);
		move->map[move->y_pos][move->x_pos] = 'P';
		move->map[move->y_pos + 1][move->x_pos] = '0';
	}
	else
		move->y_pos++;
	draw_to_screen(move);
}

void	player_move_down(t_map *move)
{
	if (move->map[++move->y_pos][move->x_pos] != '1')
	{
		if (move->map[move->y_pos][move->x_pos] == 'E' && move->col == 0)
		{
			ft_printf("total moves %d\n", move->counter++);
			mlx_destroy_window(move->mlx_init, move->mlx_win);
			destroy(move->map);
			destroy_all(move);
		}
		else if (move->map[move->y_pos][move->x_pos] == 'C')
			move->col--;
		else if (move->map[move->y_pos][move->x_pos] == 'E' && move->col != 0)
		{
			move->y_pos--;
			draw_to_screen(move);
			return ;
		}
		ft_printf("total moves %d\n", move->counter++);
		mlx_clear_window(move->mlx_init, move->mlx_win);
		move->map[move->y_pos][move->x_pos] = 'P';
		move->map[move->y_pos - 1][move->x_pos] = '0';
	}
	else
		move->y_pos--;
	draw_to_screen(move);
}

void	player_move_right(t_map *move)
{
	if (move->map[move->y_pos][++move->x_pos] != '1')
	{
		if (move->map[move->y_pos][move->x_pos] == 'E' && move->col == 0)
		{
			ft_printf("total moves %d\n", move->counter++);
			mlx_destroy_window(move->mlx_init, move->mlx_win);
			destroy(move->map);
			destroy_all(move);
		}
		else if (move->map[move->y_pos][move->x_pos] == 'C')
			move->col--;
		else if (move->map[move->y_pos][move->x_pos] == 'E' && move->col != 0)
		{
			move->x_pos--;
			draw_to_screen(move);
			return ;
		}
		ft_printf("total moves %d\n", move->counter++);
		mlx_clear_window(move->mlx_init, move->mlx_win);
		move->map[move->y_pos][move->x_pos] = 'P';
		move->map[move->y_pos][move->x_pos - 1] = '0';
	}
	else
		move->x_pos--;
	draw_to_screen(move);
}

void	player_move_left(t_map *move)
{
	if (move->map[move->y_pos][--move->x_pos] != '1')
	{
		if (move->map[move->y_pos][move->x_pos] == 'E' && move->col == 0)
		{
			ft_printf("total moves %d\n", move->counter++);
			mlx_destroy_window(move->mlx_init, move->mlx_win);
			destroy(move->map);
			destroy_all(move);
		}
		else if (move->map[move->y_pos][move->x_pos] == 'C')
			move->col--;
		else if (move->map[move->y_pos][move->x_pos] == 'E' && move->col != 0)
		{
			move->x_pos++;
			draw_to_screen(move);
			return ;
		}
		ft_printf("total moves %d\n", move->counter++);
		mlx_clear_window(move->mlx_init, move->mlx_win);
		move->map[move->y_pos][move->x_pos] = 'P';
		move->map[move->y_pos][move->x_pos + 1] = '0';
	}
	else
		move->x_pos++;
	draw_to_screen(move);
}
