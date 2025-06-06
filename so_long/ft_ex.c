/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahapetro <ahapetro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 17:09:51 by ahapetro          #+#    #+#             */
/*   Updated: 2025/06/06 15:42:10 by ahapetro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_ex_e(char **arr, t_m *m)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	i = m->ex_i;
	j = m->ex_j;
	m->map[i][j] = 'E';
	ft_put(arr[i][j], j * 64, m, i * 64);
}

void	ft_find_ex(char **arr, t_m *m)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (arr[i])
	{
		j = 0;
		while (arr[i][j])
		{
			if (arr[i][j] == 'E')
			{
				m->ex_i = i;
				m->ex_j = j;
				break ;
			}
			j++;
		}
		i++;
	}
}

void	win_close(t_m *m)
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

void	ft_free(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

int	ft_return_ex(t_m *m, int i)
{
	ft_printf("Error\n");
	if (i == 1)
		win_close(m);
	return (0);
}
