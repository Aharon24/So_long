/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chek.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahapetro <ahapetro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 19:51:46 by ahapetro          #+#    #+#             */
/*   Updated: 2025/06/06 17:23:16 by ahapetro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_ber_path_chek(char *arr)
{
	int		i;
	int		j;
	char	str[5];

	ft_str_(str);
	i = 0;
	j = 0;
	while (arr[i])
		i++;
	i--;
	while ((arr[i] >= 9 && arr[i] <= 13) || arr[i] == 32)
		i--;
	i = i - 3;
	while (str[j] && arr[i] == str[j] && ft_sp(arr[i]))
	{
		i++;
		j++;
	}
	if (!ft_sp(arr[i]))
	{
		i--;
		j--;
	}
	return (arr[i] - str[j]);
}

int	ft_len_maap_chek(char *ber, int fd, int x, t_m *m)
{
	int	const_x;
	int	y;

	y = 0;
	const_x = 0;
	ber = get_next_line(fd);
	while (ber)
	{
		x = ft_count_ber(ber);
		if (const_x == 0)
			const_x = ft_count_ber(ber);
		if (x != const_x)
		{
			get_next_line(-42);
			free(ber);
			return (0);
		}
		free(ber);
		ber = get_next_line(fd);
		y++;
	}
	free(ber);
	m->m_x = x;
	m->m_y = y;
	return (1);
}

char	**ft_map_chek(char **arr, int x, int y, t_m *m)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (ft_chek_map_1(arr, x, y) == NULL)
	{
		ft_free(arr);
		return (NULL);
	}
	if (ft_chek_mapp_2(arr, m) == 2)
	{
		ft_free(arr);
		return (NULL);
	}
	return (arr);
}

int	ft_chek_start(char **arr, t_m *m)
{
	int	r;

	r = 0;
	m->map_chek = ft_arr_copy(arr, m);
	ft_fa_player_ff(m);
	m->map_chek = ft_flodd_file(m, m->map_chek, m->player_x_ff, m->player_y_ff);
	r = ft_chek_mid(m->map_chek);
	if (r == 0)
	{
		ft_free(arr);
		ft_free(m->map_chek);
	}
	return (r);
}

int	ft_chek_mid(char **arr)
{
	int	i;
	int	j;

	i = 0;
	while (arr[i])
	{
		j = 0;
		while (arr[i][j])
		{
			if (arr[i][j] != '1' && arr[i][j] != 'F' && arr[i][j] != '\n' && arr[i][j] != '0')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
