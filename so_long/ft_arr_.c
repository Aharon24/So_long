/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arr_.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahapetro <ahapetro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 19:39:39 by ahapetro          #+#    #+#             */
/*   Updated: 2025/06/05 19:18:28 by ahapetro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**ft_m_arr(int y, char **arr)
{
	if (y == 0)
		return (NULL);
	if (!arr)
		arr = (char **)malloc((y + 1) * sizeof(char *));
	if (!arr)
		return (NULL);
	arr[y] = NULL;
	return (arr);
}

char	**ft_set_arr(char **arr, int y, char *p)
{
	int		i;
	int		fd;
	char	*arr_r;

	arr_r = NULL;
	i = 0;
	fd = 0;
	fd = open(p, O_RDONLY);
	arr_r = get_next_line(fd);
	while (arr_r && i < y)
	{
		arr[i] = arr_r;
		i++;
		arr_r = get_next_line(fd);
	}
	arr[i] = NULL;
	close(fd);
	return (arr);
}

char	**ft_arr_copy(char **arr, t_m *map)
{
	int		i;
	int		j;
	char	**arr_;

	i = 0;
	j = 0;
	arr_ = NULL;
	i = 0;
	arr_ = ft_m_arr(map->m_y, arr_);
	while (arr[i])
	{
		j = 0;
		arr_[i] = malloc((map->x + 1) * sizeof(char));
		while (arr[i][j] && j < map->x)
		{
			arr_[i][j] = arr[i][j];
			j++;
		}
		arr_[i][j] = '\0';
		i++;
	}
	arr_[i] = NULL;
	return (arr_);
}
