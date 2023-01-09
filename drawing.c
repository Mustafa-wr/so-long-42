/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mradwan <mradwan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 22:02:53 by mradwan           #+#    #+#             */
/*   Updated: 2022/11/15 17:40:34 by mradwan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw_to_screen(t_map *m)
{
	m->x = 0;
	m->y = 0;
	while (m->map[m->y])
	{
		m->x = 0;
		while (m->map[m->y][m->x])
		{
			draw_helper(m);
			m->x++;
		}
		m->y++;
	}
}

static void	draw_helper_tow(t_map *m)
{
	if (m->map[m->y][m->x] == 'C')
	{
		mlx_put_image_to_window(m->mlx_init, m->mlx_win, \
			m->empty, m->x * 64, m->y * 64);
		mlx_put_image_to_window(m->mlx_init, m->mlx_win, \
			m->coin, m->x * 64, m->y * 64);
	}
	if (m->map[m->y][m->x] == 'E')
	{
		mlx_put_image_to_window(m->mlx_init, m->mlx_win, \
			m->empty, m->x * 64, m->y * 64);
		mlx_put_image_to_window(m->mlx_init, m->mlx_win, \
			m->exit, m->x * 64, m->y * 64);
	}
}

void	draw_helper(t_map *m)
{
	if (m->map[m->y][m->x] == '1')
		mlx_put_image_to_window(m->mlx_init, m->mlx_win, \
			m->wall, m->x * 64, m->y * 64);
	if (m->map[m->y][m->x] == 'P')
	{
		m->x_pos = m->x;
		m->y_pos = m->y;
		mlx_put_image_to_window(m->mlx_init, m->mlx_win, \
			m->empty, m->x_pos * 64, m->y_pos * 64);
		mlx_put_image_to_window(m->mlx_init, m->mlx_win, \
			m->player, m->x_pos * 64, m->y_pos * 64);
	}
	if (m->map[m->y][m->x] == '0')
		mlx_put_image_to_window(m->mlx_init, m->mlx_win, \
			m->empty, m->x * 64, m->y * 64);
	draw_helper_tow(m);
}
