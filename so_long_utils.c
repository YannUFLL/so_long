/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydumaine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 16:01:46 by ydumaine          #+#    #+#             */
/*   Updated: 2022/04/15 20:00:32 by ydumaine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_get_pos(char **map, int *line, int *column)
{
	int stop;
	int x; 
	int y;

	y = 0;
	x = 0;	
	stop = 0;
	while (map[y][x] && !stop) 
	{
		while (map[y][x] && !stop)
		{
			if (map[y][x] == 'P')
			{
				stop = 1;
				break ;
			}
			x++;
		}
		if (stop == 1)
			break ; 
		x = 0;
		y++;
	}
	*line = y;
	*column = x;
}

void	ft_if_items(t_data *data, int line, int column, char a) 
{
	if ((data->map)[line - 1][column] == 'C' && (a == 'w'))
		*(data->collect) = *(data->collect) - 1;
	if ((data->map)[line + 1][column] == 'C' && (a == 's'))
		*(data->collect) = *(data->collect) - 1;
	if ((data->map)[line][column - 1] == 'C' && (a == 'a'))
		*(data->collect) = *(data->collect) - 1;
	if ((data->map)[line][column + 1] == 'C' && (a == 'd'))
		*(data->collect) = *(data->collect) - 1;
}

void	ft_print_footsteps(t_data *data)
{
	static int foot;
	char *ptr;

	foot = foot + 1;
	
	ptr = ft_itoa(foot - 1);
	mlx_string_put(data->mlx, data->win, 10, 15, 0x00FFFFFF, "Nombre de pas :");
	mlx_string_put(data->mlx, data->win, 170, 15, 0x00FFFFFF, ptr);
	free(ptr);

}

int	ft_if_end(t_data *data, int line, int column)
{
	if ((data->map)[line][column] == 'E' && *data->collect == 0)
		exit (0);
	else if ((data->map)[line][column] == 'E')
		return (1);
	else
		return (0);
}


int	ft_number_item(char** map)
{
	int u;
	int i;
	int C;

	i = 0;
	C = 0;
	while (map[i])
	{
		u = 0;
		while (map[i][u])
		{
			if (map[i][u] == 'C')
				C++;
			u++;
		}
		i++;
	}
	return (C);
}
