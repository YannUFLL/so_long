/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydumaine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 22:32:24 by ydumaine          #+#    #+#             */
/*   Updated: 2022/04/13 02:05:54 by ydumaine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_data	data;
	//int width;
	//int height;
	if (argc < 1 || argc > 2)
	{
		ft_printf("Error");
		return (0);
	}
	data.map = ft_create_tab(argv[1]);
	if(ft_check_map(data.map))
		return (0);
	data.mlx = mlx_init();
	ft_printf("height : %d", ft_map_height(data.map));
	data.win = mlx_new_window(data.mlx, ft_map_length(data.map),ft_map_height(data.map), "so_long");
	//mlx_key_hook(vars.win, key_hook, &vars);
	//data.exit = mlx_png_file_to_image(data.mlx, "./img/exit.png", &width, &height);
	ft_img_init(&data);
	ft_print_map(&data);		
	//mlx_put_image_to_window(data.mlx, data.win, data.exit, 50, 50);

	mlx_loop(data.mlx);
}

char **ft_create_tab(char *file)
{
	int fd;
	char *ptr;
	char **map;
	char *ex_ptr;

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
