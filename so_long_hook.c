/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_hook.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydumaine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 17:03:54 by ydumaine          #+#    #+#             */
/*   Updated: 2022/04/11 21:07:40 by ydumaine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_hook(int keycode, t_mlx *vmlx)
{
	if (keycode == 'w')
		ft_go_up(vmlx->mlx, vmlx->win, map);
	if (keycode == 'q')
		ft_go_left(vmlx->mlx, vmlx->win, map);
	if (keycode == 'd')
		ft_go_right(vmlx->mlx, vmlx->win, map); 
	if (keycode == 's')
		ft_do_down(vmlx->mlx, vmlx->win, map);
	if (keycode == 27)
		vmlx->stop = 1;

}
