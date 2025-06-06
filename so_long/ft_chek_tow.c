/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chek_tow.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahapetro <ahapetro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 19:58:14 by ahapetro          #+#    #+#             */
/*   Updated: 2025/06/05 19:57:11 by ahapetro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_img_m_m(t_m *m)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	m->img_p = mlx_xpm_file_to_image(m->mlx_init, m->player, &x, &y);
	if (!m->img_p)
		return (0);
	m->img_w = mlx_xpm_file_to_image(m->mlx_init, m->wall, &x, &y);
	if (!m->img_w)
		return (0);
	m->img_f = mlx_xpm_file_to_image(m->mlx_init, m->floor, &x, &y);
	if (!m->img_f)
		return (0);
	m->img_c = mlx_xpm_file_to_image(m->mlx_init, m->coin, &x, &y);
	if (!m->img_c)
		return (0);
	m->img_d = mlx_xpm_file_to_image(m->mlx_init, m->door, &x, &y);
	if (!m->img_d)
		return (0);
	return (1);
}

int	ft_chek_img_cmp(char *str1, char *str2)
{
	int	i;

	if (!str1 || !str2)
		return (1);
	i = 0;
	while (str1[i] && str1[i] == str2[i])
		i++;
	return (str1[i] - str2[i]);
}

int	ft_chek_img_path(t_m *m)
{
	if (ft_chek_img_cmp(m->coin, "xpm/c.xpm") != 0)
		return (0);
	if (ft_chek_img_cmp(m->player, "xpm/p.xpm") != 0)
		return (0);
	if (ft_chek_img_cmp(m->floor, "xpm/f.xpm") != 0)
		return (0);
	if (ft_chek_img_cmp(m->wall, "xpm/w.xpm") != 0)
		return (0);
	if (ft_chek_img_cmp(m->door, "xpm/d.xpm") != 0)
		return (0);
	return (1);
}

char	**ft_chek_map_1(char **arr, int x, int y)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < y)
	{
		j = 0;
		while (j < x)
		{
			if (i == 0 || i == y - 1)
			{
				if (arr[i][j] != '1')
					return (NULL);
			}
			if (i > 0 || i < y - 1)
			{
				if ((j == x - 1 || j == 0) && arr[i][j] != '1')
					return (NULL);
			}
			j++;
		}
		i++;
	}
	return (arr);
}

int	ft_chek_mapp_2(char **arr, t_m *m)
{
	int	player;
	int	coin;
	int	ex;

	player = 0;
	coin = 0;
	ex = 0;
	ft_count_p_e_c(arr, m);
	if (m->mm_coin == 0)
		return (2);
	else if (m->mm_player == 0 || m->mm_player > 1)
		return (2);
	else if (m->mm_ex == 0 || m->mm_ex > 1)
		return (2);
	m->player_coin = m->mm_coin;
	m->player_ex = m->mm_ex;
	return (1);
}
