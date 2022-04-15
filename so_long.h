/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydumaine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 20:07:56 by ydumaine          #+#    #+#             */
/*   Updated: 2022/04/15 20:01:09 by ydumaine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include <fcntl.h>
# include "libft.h"
# include "libftprintf.h"
# include "get_next_line.h"


typedef struct data {
	void	*grass;
	void 	*tree;
	void 	*exit;
	void 	*item;
	void 	*player;
	void	*mlx;
	void	*win;
	char	**map;
	int		*collect; 
}				t_data;

void	ft_print_map(t_data *data);
void	ft_img_init(t_data *data);
int		ft_map_length(char **map);
int		ft_map_height(char **map);
int		ft_check_map(char **map);
char	**ft_create_tab(char *file);
int 	ft_key_hook(int keycode, t_data *data);
int		ft_number_item(char **map);
void	ft_get_pos(char **map, int *line, int *column);
void	ft_if_items(t_data *data, int line, int column, char a); 
void	ft_print_footsteps(t_data *data);
int		ft_if_end(t_data *data, int line, int column);


#endif 
