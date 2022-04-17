/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_printmap.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydumaine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 20:31:51 by ydumaine          #+#    #+#             */
/*   Updated: 2022/04/17 23:33:30 by ydumaine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_img_init(t_data *data)
{
	int	width;
	int	height;

	data->grass = mlx_png_file_to_image(data->mlx, "./img/grass.png", &width,
			&height);
	data->tree = mlx_png_file_to_image(data->mlx, "./img/tree.png", &width,
			&height);
	data->exit = mlx_png_file_to_image(data->mlx, "./img/exit.png", &width,
			&height);
	data->item = mlx_png_file_to_image(data->mlx, "./img/item.png", &width,
			&height);
	data->pfront = mlx_png_file_to_image(data->mlx, "./img/pfront.png", &width,
			&height);
	data->pback = mlx_png_file_to_image(data->mlx, "./img/pback.png", &width,
			&height);
	data->pleft = mlx_png_file_to_image(data->mlx, "./img/pleft.png", &width,
			&height);
	data->pright = mlx_png_file_to_image(data->mlx, "./img/pright.png", &width,
			&height);
	ft_img_init2(data);
}

void	ft_choose_img(t_data *data, char c, int x, int y)
{
	if (c == '1')
		mlx_put_image_to_window(data->mlx, data->win, data->tree, x, y);
	if (c == '0')
		mlx_put_image_to_window(data->mlx, data->win, data->grass, x, y);
	if (c == 'E')
		mlx_put_image_to_window(data->mlx, data->win, data->exit, x, y);
	if (c == 'C')
		mlx_put_image_to_window(data->mlx, data->win, data->item, x, y);
	if (c == 'W')
		mlx_put_image_to_window(data->mlx, data->win, data->pback, x, y);
	if (c == 'P')
		mlx_put_image_to_window(data->mlx, data->win, data->pfront, x, y);
	if (c == 'A')
		mlx_put_image_to_window(data->mlx, data->win, data->pright, x, y);
	if (c == 'D')
		mlx_put_image_to_window(data->mlx, data->win, data->pleft, x, y);
	if (c == 'M')
		ft_sprite_monster(data);
}

int	ft_choose_xyvalue(int x, int y, int a)
{
	if (a == 1)
	{
		if (x == 384 || x == 1087)
			x = x + 63;
		else
			x = x + 64;
		return (x);
	}
	if (a == 0)
	{
		if (y == 128 || y == 191)
			y = y + 63;
		else
			y = y + 64;
		return (y);
	}
	return (0);
}

int	ft_sprite_monster(t_data *data)
{
	int			y;
	int			x;
	long int	i;

	i = 0;
	ft_get_posm(data->map, &y, &x);
	x = x * 64;
	y = y * 64;
	while (i++ < 92233720)
		;
	ft_choose_sprite(data, x, y);
	return (0);
}

void	ft_print_map(t_data *data)
{
	int		x;
	int		y;
	int		i;
	int		u;
	char	**ptr;

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
		y = ft_choose_xyvalue(x, y, 0);
		i++;
	}
	ft_print_footsteps(data, 'b');
}
