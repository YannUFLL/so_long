/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_printmap.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydumaine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 20:31:51 by ydumaine          #+#    #+#             */
/*   Updated: 2022/04/15 18:57:41 by ydumaine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


int	ft_map_height(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		i++;
	i = i * 64;
	return (i);
}

int	ft_map_length(char **map)
{
	int	i;

	i = 0;
	while (map[0][i])
	{
		i++;
	}
	i = i * 64;
	return (i);
}


void	ft_img_init(t_data *data)
{
	int width; 
	int height; 

	data->grass = mlx_png_file_to_image(data->mlx, "./img/grass.png", &width,
		   	&height);
	data->tree = mlx_png_file_to_image(data->mlx, "./img/tree.png", &width, 
			&height);
	data->exit = mlx_png_file_to_image(data->mlx, "./img/exit.png", &width,
		   	&height);
	data->item = mlx_png_file_to_image(data->mlx, "./img/item.png", &width,
		   	&height);
	data->player = mlx_png_file_to_image(data->mlx, "./img/player.png", &width,
		   	&height);
}



void ft_choose_img(t_data *data, char c, int x, int y)
{
		if (c == '1')
			mlx_put_image_to_window(data->mlx, data->win, data->tree, x, y);
		if (c == '0')
			mlx_put_image_to_window(data->mlx, data->win, data->grass, x, y);
		if (c == 'E')
			mlx_put_image_to_window(data->mlx, data->win, data->exit, x, y);
		if (c == 'C')
			mlx_put_image_to_window(data->mlx, data->win, data->item, x, y);
		if (c == 'P')
			mlx_put_image_to_window(data->mlx, data->win, data->player, x, y);
}

int	ft_choose_xyvalue(int x, int y, int a)
{
	if (a == 1)
	{
		if (x == 384)
			x = x + 63;
		else 
			x = x + 64;
		return (x);
	}
	if ( a == 0)
	{
		if (y == 128)
			y = y + 63;
		else 
			y = y + 64;
		return (y);
	}
	return (0);
}


void	ft_print_map(t_data *data)
{
	int x;
	int y;
	int i;
	int u;
	char **ptr; 

	y = 0;
	i = 0;
	u = 0;
	ptr = data->map;
	while (ptr[i])
	{
		u = 0;
		x = 0;
		while (ptr[i][u])
		{
			ft_choose_img(data, ptr[i][u], x, y);
			u++;
			x = ft_choose_xyvalue(x, y, 1);
		}
		y  = ft_choose_xyvalue(x, y, 0);
		i++;
	}
	ft_print_footsteps(data);
}
