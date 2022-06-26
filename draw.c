/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaioumy <mbaioumy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 17:49:43 by mbaioumy          #+#    #+#             */
/*   Updated: 2022/06/26 20:48:13 by mbaioumy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <mlx.h>

void	img_to_window (t_data *data, char *path)
{
	int	img_height;
	int	img_width;
	data->img = mlx_xpm_file_to_image(data->mlx, path, &img_width, &img_height); 		
	mlx_put_image_to_window(data->mlx, data->win, data->img, data->y, data->x);
}

void	draw(char **map, int x, int y, t_data *data)
{
	//char	*road_path = "/Users/mbaioumy/Documents/so_long/Assets/road.xpm";
	char	*border_path = "/Users/mbaioumy/Documents/so_long/Assets/border.xpm";
	char	*player_path = "/Users/mbaioumy/Documents/so_long/Assets/homer.xpm";
	char	*collectible_path = "/Users/mbaioumy/Documents/so_long/Assets/donut.xpm";
	char	*exit_path = "/Users/mbaioumy/Documents/so_long/Assets/moesbar_108047.xpm";
	char	*enemy_path = "/Users/mbaioumy/Documents/so_long/Assets/MrBurns.xpm";
	int		i;
	int		j;

	i = 0;
	y++;
	data->x = 0;
	while (map[i])
	{
		j = 0;
		data->y = 0;
		while (map[i][j])
		{
			if (map[i][j] == '1')
				img_to_window(data, border_path);
			// else if (map[i][j] == '0')
			// {
			// 	img_to_window(data, road_path);
			// 	// img.img = mlx_xpm_file_to_image(mlx, road_path, &img_width, &img_height); 		
			// 	// mlx_put_image_to_window(mlx, data.win, data.img, 0, 0);
			// 	// printf("printed road\n %d", j);
			// }
			else if (map[i][j] == 'P')
				img_to_window(data, player_path);
			// else if (map[i][j] == 'C')
			// 	img_to_window(data, collectible_path);
			else if (map[i][j] == 'E')
				img_to_window(data, exit_path);
			else if (map[i][j] == 'B')
				img_to_window(data, enemy_path);
			j++;
			data->y += 70;
		}
		data->x += 70;
		i++;
	}
}