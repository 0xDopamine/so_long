/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaioumy <mbaioumy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 18:42:53 by mbaioumy          #+#    #+#             */
/*   Updated: 2022/06/26 21:29:57 by mbaioumy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	rotate_donut(t_data *data, char *path)
{	
	int	i = 0;
	int	j;

	data->x = 0;
	while (data->map[i])
	{
		data->y = 0;
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] == 'C')
			{
				img_to_window(data, "/Users/mbaioumy/Documents/so_long/Assets/noir.xpm");
				img_to_window(data, path);
			}
			data->y += 70;
			j++;
		}
		data->x += 70;
		i++;
	}
}

void	enemy_moves(t_data *data)
{
	int		file;
	char	rand;
	
	file = open("/dev/random", O_RDONLY); 
	read(file, &rand, 1);
	if ((rand >= -128) && (rand <= -64))
	{
		mlx_clear_window(data->mlx, data->win);
		draw(move_left_enemy(data), data->x, data->y, data);
	}
	else if ((rand >= -63) && (rand <= 0))
	{	
		mlx_clear_window(data->mlx, data->win);
		draw(move_right_enemy(data), data->x, data->y, data);
	}
	else if ((rand >= 1) && (rand <= 64))
	{
		mlx_clear_window(data->mlx, data->win);
		draw(move_up_enemy(data), data->x, data->y, data);
	}
	else if ((rand >= 65) && (rand <= 127))
	{
		mlx_clear_window(data->mlx, data->win);
		draw(move_down_enemy(data), data->x, data->y, data);
	}
}

int	animation(t_data *data)
{
	static int	c;
	static int	id;

	if (c > 2000)
	{
		if (id == 1)
		{
			rotate_donut(data, "/Users/mbaioumy/Documents/so_long/Assets/donut.xpm");
			id = 0;
		}
		else if (id == 0)
		{
			rotate_donut(data, "/Users/mbaioumy/Documents/so_long/Assets/donut2.xpm");
			id = 1;
		}
		//enemy_moves(data);
		c = 0;
	}
	else
		c++;
	return (0);
}