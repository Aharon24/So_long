/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_graphics.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahapetro <ahapetro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 18:57:40 by ahapetro          #+#    #+#             */
/*   Updated: 2025/06/04 17:19:08 by ahapetro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_put(char n_x, int size, t_m *m, int y)
{
	if (n_x == '1')
		mlx_put_image_to_window(m->mlx_init, m->window, m->img_w, size, y);
	else if (n_x == '0')
		mlx_put_image_to_window(m->mlx_init, m->window, m->img_f, size, y);
	else if (n_x == 'P')
	{
		mlx_put_image_to_window(m->mlx_init, m->window, m->img_f, size, y);
		mlx_put_image_to_window(m->mlx_init, m->window, m->img_p, size, y);
	}
	else if (n_x == 'C')
		mlx_put_image_to_window(m->mlx_init, m->window, m->img_c, size, y);
	else if (n_x == 'E')
	{
		mlx_put_image_to_window(m->mlx_init, m->window, m->img_d, size, y);
	}
}

void	ft_create_map(char *str, t_m *m, int y)
{
	int			i;
	int			size;
	static int	y_y = 0;

	i = 0;
	size = 0;
	m->h_c = 0;
	m->w_c = 0;
	if (y == 0)
		y_y = 0;
	while (str[i])
		i++;
	i = 0;
	while (str[i])
	{
		ft_put(str[i], size, m, y_y);
		size += 64;
		i++;
	}
	y_y += 64;
}

void	ft_map_iterator(char **arr, t_m *m)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		ft_create_map(arr[i], m, i);
		i++;
	}
}

int	ft_put_map(char **arr, int x, int y, t_m *m)
{
	ft_size_map(x, y, m);
	m->mlx_init = mlx_init();
	if (ft_create_img(m) == 0)
		return (0);
	m->window = mlx_new_window(m->mlx_init, m->size_x, m->size_y, "So_long");
	ft_map_iterator(arr, m);
	return (1);
}

int	ft_create_img(t_m *m)
{
	m->coin = "xpm/c.xpm";
	m->player = "xpm/p.xpm";
	m->floor = "xpm/f.xpm";
	m->wall = "xpm/w.xpm";
	m->door = "xpm/d.xpm";
	if (ft_chek_img_path(m) == 0)
	{
		win_close(m);
		return (0);
	}
	else
	{
		if (ft_img_m_m(m) == 0)
			return (0);
	}
	return (1);
}
