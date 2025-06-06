/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahapetro <ahapetro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 19:44:04 by ahapetro          #+#    #+#             */
/*   Updated: 2025/06/05 21:10:41 by ahapetro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_fa_player(t_m *m)
{
	int		i;
	int		j;
	char	**arr;

	arr = m->map;
	i = 0;
	j = 0;
	while (arr[i])
	{
		j = 0;
		while (arr[i][j])
		{
			if (arr[i][j] == 'P')
			{
				m->player_x = j;
				m->player_y = i;
				break ;
			}
			j++;
		}
		i++;
	}
}

void	ft_fa_player_ff(t_m *m)
{
	int		i;
	int		j;
	char	**arr;

	i = 0;
	arr = m->map_chek;
	while (arr[i])
	{
		j = 0;
		while (arr[i][j])
		{
			if (arr[i][j] == 'P')
			{
				m->player_x_ff = j;
				m->player_y_ff = i;
				break ;
			}
			j++;
		}
		i++;
	}
}

void	ft_count_p_e_c(char **arr, t_m *m)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	m->mm_player = 0;
	m->mm_coin = 0;
	m->mm_ex = 0;
	while (arr[i])
	{
		j = 0;
		while (arr[i][j])
		{
			if (arr[i][j] == 'P')
				m->mm_player++;
			else if (arr[i][j] == 'C')
				m->mm_coin++;
			else if (arr[i][j] == 'E')
				m->mm_ex++;
			j++;
		}
		i++;
	}
}

int	win_mouse(t_m *m)
{
	if (m->img_p)
		mlx_destroy_image(m->mlx_init, m->img_p);
	if (m->img_w)
		mlx_destroy_image(m->mlx_init, m->img_w);
	if (m->img_f)
		mlx_destroy_image(m->mlx_init, m->img_f);
	if (m->img_c)
		mlx_destroy_image(m->mlx_init, m->img_c);
	if (m->img_d)
		mlx_destroy_image(m->mlx_init, m->img_d);
	if (m->window)
	{
		mlx_destroy_window(m->mlx_init, m->window);
		mlx_destroy_display(m->mlx_init);
	}
	if (m->mlx_init)
	{
		free(m->mlx_init);
		m->mlx_init = NULL;
	}
	if (m->arr_m)
		ft_free(m->arr_m);
	if (m->map_chek)
		ft_free(m->map_chek);
	exit(0);
}
