/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_moves.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaioumy <mbaioumy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 21:10:43 by mbaioumy          #+#    #+#             */
/*   Updated: 2022/06/27 01:22:10 by mbaioumy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <mlx.h>

int     *get_coordinates_enemy(t_data *data)
{
	int *coordinates;
	int i;
	int j;

	i = 0;
	coordinates = (int *)malloc(sizeof(int) * 2);
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] == 'B')
			{
				coordinates[0] = i;
				coordinates[1] = j;
				break ;
			}
			j++;
		}
		i++;
	}
	return (coordinates);
}

char    **move_up_enemy(t_data *data)
{
	int *coordinates;
	int i;
	int j;

	coordinates = (int *)malloc(sizeof(int) * 2);
	coordinates = get_coordinates_enemy(data);
	i = coordinates[0];
	j = coordinates[1];
	if (data->map[i - 1][j] != '1' && data->map[i - 1][j] != 'E'
	&& data->map[i - 1][j] != 'C')
	{
		data->map[i][j] = '0';
		data->map[i - 1][j] = 'B';
	}
	else
		data->map[i][j] = 'B';
	if (data->map[i - 1][j] == 'P')
	{
		printf("You Lose!");
		exit(0);
	} 
	return (data->map);
}

char    **move_right_enemy(t_data *data)
{
    int *coordinates;
    int i;
    int j;

    coordinates = (int *)malloc(sizeof(int) * 2);
    coordinates = get_coordinates_enemy(data);
    i = coordinates[0];
    j = coordinates[1];
    if (data->map[i][j + 1] != '1' && data->map[i][j + 1] != 'E'
	&& data->map[i][j + 1] != 'C')
    {
        data->map[i][j] = '0';
        data->map[i][j + 1] = 'B';
    }
    else
        data->map[i][j] = 'B';
	if (data->map[i][j + 1] == 'P')
	{
		printf("You Lose!");
		exit(0);
	}
    return (data->map);
}

char    **move_down_enemy(t_data *data)
{
    int *coordinates;
    int i;
    int j;

    coordinates = (int *)malloc(sizeof(int) * 2);
    coordinates = get_coordinates_enemy(data);
    i = coordinates[0];
    j = coordinates[1];
    if (data->map[i + 1][j] != '1' && data->map[i + 1][j] != 'E'
	&& data->map[i + 1][j] != 'C')
    {
        data->map[i][j] = '0';
        data->map[i + 1][j] = 'B';
    }
    else
        data->map[i][j] = 'B';
	if (data->map[i + 1][j] == 'P')
	{
		printf("You Lose!");
		exit(0);
	}
    return (data->map);
}

char    **move_left_enemy(t_data *data)
{
    int *coordinates;
    int i;
    int j;

    coordinates = (int *)malloc(sizeof(int) * 2);
    coordinates = get_coordinates_enemy(data);
    i = coordinates[0];
    j = coordinates[1];
    if (data->map[i][j - 1] != '1' && data->map[i][j - 1] != 'E'
	&& data->map[i][j - 1] != 'C')
    {
        data->map[i][j] = '0';
        data->map[i][j - 1] = 'B';
    }
    else
        data->map[i][j] = 'B';
	if (data->map[i][j - 1] == 'P')
	{
		printf("You Lose!");
		exit(0);
	}
    return (data->map);
}