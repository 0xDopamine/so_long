/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaioumy <mbaioumy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 17:49:43 by mbaioumy          #+#    #+#             */
/*   Updated: 2022/06/28 00:11:16 by mbaioumy         ###   ########.fr       */
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

void	draw(char **map, t_data *data, t_str *paths)
{
	paths->border = "/Users/mbaioumy/Documents/so_long/Assets/border.xpm";
	paths->player = "/Users/mbaioumy/Documents/so_long/Assets/homer.xpm";
	paths->collectible = "/Users/mbaioumy/Documents/so_long/Assets/donut.xpm";
	paths->exit = "/Users/mbaioumy/Documents/so_long/Assets/moesbar_108047.xpm";
	paths->enemy = "/Users/mbaioumy/Documents/so_long/Assets/MrBurns.xpm";
	int		i;
	int		j;

	i = 0;
	data->x = 0;
	while (map[i])
	{
		j = 0;
		data->y = 0;
		while (map[i][j])
		{
			if (map[i][j] == '1')
				img_to_window(data, paths->border);
			else if (map[i][j] == 'P')
				img_to_window(data, paths->player);
			else if (map[i][j] == 'C')
				img_to_window(data, paths->collectible);
			else if (map[i][j] == 'E')
				img_to_window(data, paths->exit);
			else if (map[i][j] == 'B')
				img_to_window(data, paths->enemy);
			j++;
			data->y += 70;
		}
		data->x += 70;
		i++;
	}
}