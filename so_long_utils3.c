/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydumaine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 18:34:57 by ydumaine          #+#    #+#             */
/*   Updated: 2022/04/17 20:49:03 by ydumaine         ###   ########.fr       */
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

void	ft_img_init2(t_data *data)
{
	int	width;
	int	height;

	data->monster1 = mlx_png_file_to_image(data->mlx, "./img/monster1.png",
			&width, &height);
	data->monster2 = mlx_png_file_to_image(data->mlx, "./img/monster2.png",
			&width, &height);
	data->monster3 = mlx_png_file_to_image(data->mlx, "./img/monster3.png",
			&width, &height);
	data->monster4 = mlx_png_file_to_image(data->mlx, "./img/monster4.png",
			&width, &height);
}

void	ft_choose_sprite(t_data	*data, int x, int y)
{
	static int	img;

	if (img == 0)
		mlx_put_image_to_window(data->mlx, data->win, data->monster1, x, y);
	if (img == 1)
		mlx_put_image_to_window(data->mlx, data->win, data->monster2, x, y);
	if (img == 2)
		mlx_put_image_to_window(data->mlx, data->win, data->monster3, x, y);
	if (img == 3)
		mlx_put_image_to_window(data->mlx, data->win, data->monster4, x, y);
	if (img == 3)
	{
		img = 0;
		ft_ia(data->map, data->k);
		ft_print_map(data);
	}
	else
		img++;
}

void	ft_exit(char **map)
{
	free(map);
	exit (0);
}
