/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahapetro <ahapetro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 13:13:05 by ahapetro          #+#    #+#             */
/*   Updated: 2025/06/05 21:09:08 by ahapetro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char *argv[])
{
	char	**ber_arr;
	t_m		m;

	ber_arr = NULL;
	if (argc != 2)
		return (ft_return_ex(&m, 0));
	if (ft_open_gnl(argv[1], &m) == 0)
		return (ft_return_ex(&m, 0));
	ber_arr = ft_make(&m, ber_arr, argv[1]);
	if (ber_arr == NULL)
		return (ft_return_ex(&m, 0));
	if (m.player_ex == 0 && ber_arr)
		ft_free(ber_arr);
	return (0);
}

int	ft_open_gnl(char *path, t_m *m)
{
	int		fd;
	int		x;

	m->count = 0;
	x = 0;
	fd = 0;
	if (ft_ber_path_chek(path) != 0)
		return (0);
	fd = open(path, O_RDONLY);
	if (fd <= 0)
		return (0);
	if (ft_open_red(m, fd, x) == 0)
	{
		close(fd);
		return (0);
	}
	close(fd);
	return (1);
}

int	ft_open_red(t_m *m, int fd, int x)
{
	char	*ber;

	ber = NULL;
	if (ft_len_maap_chek(ber, fd, x, m) == 0)
		return (0);
	return (1);
}

char	**ft_make(t_m *m, char **ber_arr, char *path_argv)
{
	int	i;

	i = 0;
	m->map_e_chek = 1;
	ber_arr = ft_m_arr(m->m_y, ber_arr);
	if (ber_arr == NULL)
		return (NULL);
	i = 0;
	ber_arr = ft_set_arr(ber_arr, m->m_y, path_argv);
	i = 0;
	m->arr_m = ber_arr;
	m->x = m->m_x;
	m->y = m->m_y;
	if (ft_map_chek(m->arr_m, m->m_x, m->m_y, m) == NULL)
		return (NULL);
	if (ft_chek_start(m->arr_m, m))
		m->map = m->arr_m;
	else
		return (NULL);
	if (ft_finish_map(m, m->arr_m, m->m_x, m->m_y) == 0)
		return (NULL);
	ft_hook(m);
	return (ber_arr);
}
