/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_finish_win.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahapetro <ahapetro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 19:58:33 by ahapetro          #+#    #+#             */
/*   Updated: 2025/06/05 22:09:27 by ahapetro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_hook(t_m *m)
{
	mlx_hook(m->window, 2, 1L << 0, ft_key, m);
	mlx_hook(m->window, 17, 0, win_mouse, m);
	mlx_loop(m->mlx_init);
}

int	ft_finish_map(t_m *m, char **arr, int x, int y)
{
	m->neative_x = 0;
	m->neative_y = 0;
	ft_exit_player_case(m);
	if (ft_put_map(arr, x, y, m) == 0)
		return (0);
	return (1);
}

void	ft_size_map(int x, int y, t_m *m)
{
	m->size_x = 64 * (x);
	m->size_y = 64 * (y);
}

void	ft_key_put(int key, t_m *m)
{
	if (key == 97 || key == 65361)
	{
		ft_fa_player(m);
		ft_new_map_a(m);
	}
	else if (key == 100 || key == 65363)
	{
		ft_fa_player(m);
		ft_new_map_d(m);
	}
	else if (key == 115 || key == 65364)
	{
		ft_fa_player(m);
		ft_new_map_s(m);
	}
	else if (key == 119 || key == 65362)
	{
		ft_fa_player(m);
		ft_new_map_w(m);
	}
}

int	ft_key(int keycode, t_m *m)
{
	m->point_player = keycode;
	if (keycode == 65307)
		win_close(m);
	ft_key_put(keycode, m);
	return (keycode);
}
