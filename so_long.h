/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydumaine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 20:07:56 by ydumaine          #+#    #+#             */
/*   Updated: 2022/04/13 01:45:42 by ydumaine         ###   ########.fr       */
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
}				t_data;

void	ft_print_map(t_data *data);
void	ft_img_init(t_data *data);
int		ft_map_length(char **map);
int		ft_map_height(char **map);
int		ft_check_map(char **map);
char	**ft_create_tab(char *file);


#endif 
