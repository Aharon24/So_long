/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chek_three.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahapetro <ahapetro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 20:10:05 by ahapetro          #+#    #+#             */
/*   Updated: 2025/06/04 17:35:14 by ahapetro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_count_ber(char	*arr_g_ber)
{
	int	i;

	i = 0;
	while (arr_g_ber[i] != '\0' && arr_g_ber[i] != '\n')
		i++;
	return (i);
}

void	ft_str_(char *str)
{
	str[0] = '.';
	str[1] = 'b';
	str[2] = 'e';
	str[3] = 'r';
	str[4] = '\0';
}

int	ft_sp(char c)
{
	if ((c >= 9 && c <= 13) || c == 32)
		return (0);
	return (1);
}

char	**ft_flodd_file(t_m *m, char **arr, int x, int y)
{
	if (!arr)
		arr = m->map_chek;
	if (x <= 0 || y <= 0 || arr[y][x] == '1')
		return (NULL);
	if (arr[y][x] == 'F')
		return (NULL);
	if (arr[y][x] != '1')
		arr[y][x] = 'F';
	if (x <= m->x && y <= m->y)
	{
		ft_flodd_file(m, arr, x + 1, y);
		ft_flodd_file(m, arr, x - 1, y);
		ft_flodd_file(m, arr, x, y + 1);
		ft_flodd_file(m, arr, x, y - 1);
	}
	return (arr);
}
