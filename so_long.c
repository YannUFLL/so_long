/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydumaine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 22:32:24 by ydumaine          #+#    #+#             */
/*   Updated: 2022/04/17 23:31:39 by ydumaine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_data	data;
	int		collect;
	int		random;

	if (argc < 1 || argc > 2)
	{
		ft_printf("Error");
		return (0);
	}
	random = 0;
	data.map = ft_create_tab(argv[1]);
	if (ft_check_map(data.map))
		return (0);
	collect = ft_number_item(data.map);
	data.collect = &collect;
	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx, ft_map_length(data.map),
			ft_map_height(data.map), "so_long");
	ft_img_init(&data);
	ft_print_map(&data);
	mlx_key_hook(data.win, ft_key_hook, &data);
	mlx_loop_hook(data.mlx, ft_sprite_monster, &data);
	mlx_loop(data.mlx);
}

char	**ft_create_tab(char *file)
{
	int		fd;
	char	*ptr;
	char	**map;
	char	*ex_ptr;

	fd = open(file, O_RDONLY);
	ptr = NULL;
	ex_ptr = get_next_line(fd);
	while (ex_ptr)
	{
		ptr = ft_strjoin_andfree_s1(ptr, ex_ptr);
		free(ex_ptr);
		ex_ptr = get_next_line(fd);
	}
	map = ft_split(ptr, '\n');
	free(ptr);
	return (map);
}
