/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_a_d_w_s.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahapetro <ahapetro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 20:45:23 by ahapetro          #+#    #+#             */
/*   Updated: 2025/06/05 22:07:59 by ahapetro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_new_map_a(t_m *m)
{
	char	**arr;
	int		i;
	int		j;

	i = m->player_y;
	j = m->player_x;
	arr = m->map;
	if (arr[i][j - 1] != '1' || arr[i][j - 1] == '0' || arr[i][j - 1] == 'C')
	{
		ft_printf("count: %d\n", m->count);
		ft_new_map_aa(m, arr, i, j);
		ft_put(arr[i][j - 1], (j - 1) * 64, m, i * 64);
		ft_put(arr[i][j], j * 64, m, i * 64);
		if (m->player_coin == 0)
		{
			ft_ex_e(arr, m);
		}
	}
	if (m->player_ex == 0 && m->player_coin == 0)
	{
		win_close(m);
		exit(0);
	}
}

void	ft_new_map_d(t_m *m)
{
	char	**arr;
	int		i;
	int		j;

	i = m->player_y;
	j = m->player_x;
	arr = m->map;
	if (arr[i][j + 1] != '1' || arr[i][j + 1] == '0' || arr[i][j + 1] == 'C')
	{
		ft_printf("count: %d\n", m->count);
		ft_new_map_dd(m, arr, i, j);
		ft_put(arr[i][j + 1], (j + 1) * 64, m, i * 64);
		ft_put(arr[i][j], j * 64, m, i * 64);
		if (m->player_coin == 0)
		{
			ft_ex_e(arr, m);
		}
	}
	if (m->player_ex == 0 && m->player_coin == 0)
	{
		win_close(m);
		exit(0);
	}
}

void	ft_new_map_s(t_m *m)
{
	char	**arr;
	int		i;
	int		j;

	i = m->player_y;
	j = m->player_x;
	arr = m->map;
	if (arr[i + 1][j] != '1' || arr[i + 1][j] == '0' || arr[i + 1][j] == 'C')
	{
		ft_printf("count: %d\n", m->count);
		ft_new_map_ss(m, arr, i, j);
		ft_put(arr[i +1][j], j * 64, m, (i + 1) * 64);
		ft_put(arr[i][j], j * 64, m, i * 64);
		if (m->player_coin == 0)
		{
			ft_ex_e(arr, m);
		}
	}
	if (m->player_ex == 0 && m->player_coin == 0)
	{
		win_close(m);
		exit(0);
	}
}

void	ft_new_map_w(t_m *m)
{
	char	**arr;
	int		i;
	int		j;

	i = m->player_y;
	j = m->player_x;
	arr = m->map;
	if (arr[i - 1][j] != '1' || arr[i - 1][j] == '0' || arr[i - 1][j] == 'C')
	{
		ft_printf("count: %d\n", m->count);
		ft_new_map_ww(m, arr, i, j);
		ft_put(arr[i - 1][j], j * 64, m, (i - 1) * 64);
		ft_put(arr[i][j], j * 64, m, i * 64);
		if (m->player_coin == 0)
		{
			ft_ex_e(arr, m);
		}
	}
	if (m->player_ex == 0 && m->player_coin == 0)
	{
		win_close(m);
		exit(0);
	}
}
