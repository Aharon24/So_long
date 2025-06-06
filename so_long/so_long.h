/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahapetro <ahapetro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 17:25:50 by ahapetro          #+#    #+#             */
/*   Updated: 2025/06/06 15:27:54 by ahapetro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include <stdio.h>
# include <fcntl.h>
# include "get_next_line/get_next_line.h"
# include <stdlib.h>
# include "minilibx-linux/mlx.h"
# include "ft_printf/ft_printf.h"

typedef struct m
{
	int		x;
	int		y;
	int		m_x;
	int		m_y;
	int		mm_player;
	int		mm_coin;
	int		mm_ex;
	char	**arr_m;
	void	*mlx_init;
	void	*window;
	int		img_whet;
	int		img_h;
	int		size_x;
	int		size_y;
	int		print_x_point;
	int		print_y_point;
	int		neative_x;
	int		neative_y;
	int		h_c;
	int		w_c;
	char	*player;
	char	*wall;
	char	*floor;
	char	*coin;
	char	*door;
	void	*img_p;
	void	*img_w;
	void	*img_f;
	void	*img_c;
	void	*img_d;
	int		x_pix;
	int		y_pix;
	void	*img_pah_xpm;
	void	*key_data;
	int		point_player;
	char	**map;
	char	**map_chek;
	int		player_x;
	int		player_y;
	int		player_coin;
	int		player_ex;
	int		player_x_ff;
	int		player_y_ff;
	int		map_e_chek;
	int		count;
	int		map_chek_1;
	int		ex_i;
	int		ex_j;
	int		ei;
	int		ej;
}	t_m;

//function
int		ft_count_ber(char *arr_g_ber);
char	**ft_m_arr(int y, char **arr);
char	**ft_set_arr(char **arr, int y, char *path);
char	**ft_map_chek(char **arr, int x, int y, t_m *map);
int		ft_chek_mapp_2(char **arr, t_m *map);
int		ft_chek_start(char **arr, t_m *map);
char	**ft_arr_copy(char **arr, t_m *map);
int		ft_chek_mid(char **arr);
int		ft_create_img(t_m *map);
int		ft_put_map(char **arr, int x, int y, t_m *map);
void	ft_create_map(char *str, t_m *map, int y);
int		ft_finish_map(t_m *map, char **arr, int x, int y);
void	ft_size_map(int x, int y, t_m *map);
void	ft_map_iterator(char **arr, t_m *map);
void	ft_put(char n_x, int size, t_m *map, int y);
void	ft_hook(t_m *map);
int		ft_key(int keycode, t_m *map);
void	ft_new_map(t_m *rile_taime);
void	ft_fa_player(t_m *rile_taime);
void	ft_new_map_a(t_m *map);
void	ft_new_map_d(t_m *map);
void	ft_new_map_s(t_m *map);
void	ft_new_map_w(t_m *map);
void	ft_new_map_aa(t_m *m, char **arr, int i, int j);
void	ft_new_map_dd(t_m *m, char **arr, int i, int j);
void	ft_new_map_ww(t_m *m, char **arr, int i, int j);
void	ft_new_map_ss(t_m *m, char **arr, int i, int j);
void	ft_find_ex(char **arr, t_m *m);
void	ft_ex_e(char **arr, t_m	*m);
char	**ft_flodd_file(t_m *map, char **arr, int x, int y);
void	ft_fa_player_ff(t_m *map);
void	win_close(t_m *m);
int		ft_open_gnl(char *arr, t_m *m);
int		ft_open_red(t_m *m, int fd, int x);
char	**ft_make(t_m *m, char **ber_arr, char *path_argv);
int		ft_return_ex(t_m *m, int i);
char	**ft_chek_map_1(char **arr, int x, int y);
void	ft_count_p_e_c(char **arr, t_m *m);
int		ft_len_maap_chek(char *ber, int fd, int x, t_m *m);
int		ft_ber_path_chek(char *arr);
int		ft_sp(char c);
void	ft_str_(char *str);
int		ft_chek_img_path(t_m *m);
int		ft_chek_img_cmp(char *str1, char *str2);
int		ft_img_m_m(t_m *m);
void	ft_exit_player_case(t_m *m);
void	ft_free(char **arr);
int		win_mouse(t_m *m);
#endif