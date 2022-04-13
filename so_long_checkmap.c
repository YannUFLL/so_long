/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_checkmap.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydumaine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 20:24:17 by ydumaine          #+#    #+#             */
/*   Updated: 2022/04/13 01:33:18 by ydumaine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_check_rectangle(char **map)
{
	int i;
	int	u;
	int	control; 

	i = 0;
	u = 0;
	while (map[0][i])
		i++; 
	control = i;
	map++; 
	while (map[u])
	{
		while (map[u][i])
			i++;
		if (control != i)
			return (1);
		u++;
	}
	return (0);
}

int	ft_check_wall(char **map)
{
	int	length;
   	int	u;	

	length = 0;
	u = 0;
	while ((map[0][length]))
	{
		if (map[0][length] != '1')
			return (1);
		length++;
	}
	while(map[u + 1] != NULL)
	{
		if (map[u][0] != '1' || map[u][length - 1] != '1')
			return (1);
		u++;
	}
	length = 0;
	while (map[u][length])
	{
		if (map[u][length] != '1')
			return (1);
		length++;
	}
	return (0);
}

int	ft_check_item(char **map)
{
	int u;
	int i;
	int C;
	int E;
	int P;

	i = 0;
	C = 0;
	E = 0;
	P = 0;
	while (map[i])
	{
		u = 0;
		while (map[i][u])
		{
			if (map[i][u] == 'C')
				C = 1;
			if (map[i][u] == 'E')
				E = 1;
			if (map[i][u] == 'P')
				P = 1;
			u++;
		}
		i++;
	}
	if (C == 1 && E == 1 && P == 1)
		return (0);
	return (1);
}

int	ft_check_map(char **map)
{
	if (map == NULL) 
		return (1);
	if (ft_check_rectangle(map))
	{
		ft_printf("Error\nThe map is not rectangular.");
		return (1);
	}
	if (ft_check_wall(map))
	{
	  	ft_printf("Error\nThe map is not wall framed");	  
		return (1);
	}
	if (ft_check_item(map))
	{
		ft_printf("Error\nMissing items");
		return (1);
	}
	return (0);
}
