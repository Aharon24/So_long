/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_aa_dd_ss_ww.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahapetro <ahapetro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 14:31:04 by ahapetro          #+#    #+#             */
/*   Updated: 2025/06/05 21:09:44 by ahapetro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_new_map_aa(t_m *m, char **arr, int i, int j)
{
	m->count++;
	if (arr[i][j - 1] == 'C')
		m->player_coin--;
	else if (arr[i][j - 1] == 'E' && m->player_coin == 0)
		m->player_ex--;
	if (arr[i][j - 1] == 'E' && m->player_coin == 0)
	{
		arr[i][j - 1] = 'P';
		arr[i][j] = '0';
	}
	if (arr[i][j - 1] == 'E' && m->player_coin != 0)
	{
		m->ei = i;
		m->ej = j - 1;
		arr[i][j - 1] = 'P';
		arr[i][j] = 'E';
	}
	else
	{
		arr[i][j - 1] = 'P';
		arr[i][j] = '0';
	}
}

void	ft_new_map_dd(t_m *m, char **arr, int i, int j)
{
	m->count++;
	if (arr[i][j + 1] == 'C')
		m->player_coin--;
	else if (arr[i][j + 1] == 'E' && m->player_coin == 0)
		m->player_ex--;
	if (arr[i][j + 1] == 'E' && m->player_coin == 0)
	{
		arr[i][j + 1] = 'P';
		arr[i][j] = '0';
	}
	if (arr[i][j + 1] == 'E' && m->player_coin != 0)
	{
		m->ei = i;
		m->ej = j + 1;
		arr[i][j + 1] = 'P';
		arr[i][j] = 'E';
	}
	else
	{
		arr[i][j + 1] = 'P';
		arr[i][j] = '0';
	}
}

void	ft_new_map_ss(t_m *m, char **arr, int i, int j)
{
	m->count++;
	if (arr[i + 1][j] == 'C')
		m->player_coin--;
	else if (arr[i + 1][j] == 'E' && m->player_coin == 0)
		m->player_ex--;
	if (arr[i +1][j] == 'E' && m->player_coin == 0)
	{
		arr[i + 1][1] = 'P';
		arr[i][j] = '0';
	}
	if (arr[i + 1][j] == 'E' && m->player_coin != 0)
	{
		m->ei = i + 1;
		m->ej = j;
		arr[i + 1][j] = 'P';
		arr[i][j] = 'E';
	}
	else
	{
		arr[i + 1][j] = 'P';
		arr[i][j] = '0';
	}
}

void	ft_new_map_ww(t_m *m, char **arr, int i, int j)
{
	m->count++;
	if (arr[i - 1][j] == 'C')
		m->player_coin--;
	else if (arr[i - 1][j] == 'E' && m->player_coin == 0)
		m->player_ex--;
	if (arr[i - 1][j] == 'E' && m->player_coin == 0)
	{
		arr[i - 1][1] = 'P';
		arr[i][j] = '0';
	}
	if (arr[i - 1][j] == 'E' && m->player_coin != 0)
	{
		m->ei = i - 1;
		m->ej = j;
		arr[i - 1][j] = 'P';
		arr[i][j] = 'E';
	}
	else
	{
		arr[i - 1][j] = 'P';
		arr[i][j] = '0';
	}
}

void	ft_exit_player_case(t_m *m)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	ft_find_ex(m->map, m);
	i = m->ex_i;
	j = m->ex_j;
	m->map[i][j] = '0';
}
