/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaioumy <mbaioumy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 17:49:43 by mbaioumy          #+#    #+#             */
/*   Updated: 2022/06/13 01:03:31 by mbaioumy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <mlx.h>

void	img_to_window (t_data data, char *path)
{
	int	img_height;
	int	img_width;
	data.img = mlx_xpm_file_to_image(data.mlx, path, &img_width, &img_height); 		
	mlx_put_image_to_window(data.mlx, data.win, data.img, 0, 0);
	data.addr = mlx_get_data_addr(data.img, &data.bits_per_pixel, &data.line_length, &data.endian);
	mlx_loop(data.mlx);
}

void	draw(char **map, int x, int y)
{
	t_data	data;
	char	*road_path = "/Users/mbaioumy/Documents/so_long/Assets/road.xpm";
	char	*border_path = "/Users/mbaioumy/Documents/so_long/Assets/border.xpm";
	char	*player_path = "/Users/mbaioumy/Documents/so_long/Assets/homer.xpm";
	int		i, j;

	i = 0;
	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx, x * 70, y * 70, "test");
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == '1')
			{
				img_to_window(data, player_path);
				// data.img = mlx_xpm_file_to_image(mlx, border_path, &img_width, &img_height); 		
				// mlx_put_image_to_window(mlx, data.win, data.img, 0, 0);
				// printf("printed border %d\n", j);
			}
			else if (map[i][j] == '0')
			{
				img_to_window(data, road_path);
				// img.img = mlx_xpm_file_to_image(mlx, road_path, &img_width, &img_height); 		
				// mlx_put_image_to_window(mlx, data.win, data.img, 0, 0);
				// printf("printed road\n %d", j);
			}
			else if (map[i][j] == 'P')
			{
				img_to_window(data, player_path);
				// img.img = mlx_xpm_file_to_image(mlx, player_path, &img_width, &img_height); 		
				// mlx_put_image_to_window(mlx, data.win, data.img, 0, 0);
				// printf("printed homer %d", j);
			}
			else
			{
				img_to_window(data, border_path);
				// img.img = mlx_xpm_file_to_image(mlx, road_path, &img_width, &img_height); 		
				// mlx_put_image_to_window(mlx, win, img.img, 0, 0);
				// printf("printed else");
			}
			j++;
		}
		i++;
	}
	mlx_loop(data.mlx);
}