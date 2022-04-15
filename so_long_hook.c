/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_hook.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydumaine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 17:03:54 by ydumaine          #+#    #+#             */
/*   Updated: 2022/04/15 20:02:39 by ydumaine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_go_up(t_data *data)
{
	int	line;
	int column;

	ft_get_pos(data->map, &line, &column);
	if ((data->map)[line - 1][column] != '1')
	{
		ft_if_items(data, line, column, 'w');
		if (ft_if_end(data, line - 1, column))
			return ;
		(data->map)[line - 1][column] = 'P';
		(data->map)[line][column] = '0';
		ft_print_map(data);
	}
}

void	ft_go_down(t_data *data)
{
	int	line;
	int column;

	ft_get_pos(data->map, &line, &column);
	if ((data->map)[line + 1][column] != '1')
	{
		ft_if_items(data, line, column, 's');
		if (ft_if_end(data, line + 1, column))
			return ;
		ft_if_end(data, line + 1, column);
		(data->map)[line + 1][column] = 'P';
		(data->map)[line][column] = '0';
		ft_print_map(data);
	}
}

void	ft_go_left(t_data *data)
{
	int	line;
	int column;

	ft_get_pos(data->map, &line, &column);
	if ((data->map)[line][column - 1] != '1')
	{
		ft_if_items(data, line, column, 'a');
		if (ft_if_end(data, line, column - 1))
			return ;
		(data->map)[line][column - 1] = 'P';
		(data->map)[line][column] = '0';
		ft_print_map(data);
	}
}

void	ft_go_right(t_data *data)
{
	int	line;
	int column;

	ft_get_pos(data->map, &line, &column);
	if ((data->map)[line][column + 1] != '1')
	{
		ft_if_items(data, line, column, 'd');
		if (ft_if_end(data, line, column + 1))
			return ;
		(data->map)[line][column + 1] = 'P';
		(data->map)[line][column] = '0';
		ft_print_map(data);
	}
}

int ft_key_hook(int keycode, t_data *data)
{
	if (keycode == 13)
		ft_go_up(data);
	if (keycode == 0)
		ft_go_left(data);
	if (keycode == 2)
		ft_go_right(data); 
	if (keycode == 1)
		ft_go_down(data);
	if (keycode == 53)
		exit (0);
	return (0);
}
