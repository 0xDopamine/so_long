/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaioumy <mbaioumy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 20:55:47 by mbaioumy          #+#    #+#             */
/*   Updated: 2022/06/27 01:24:11 by mbaioumy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <mlx.h>

int     *get_coordinates(t_data *data)
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
			if (data->map[i][j] == 'P')
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

char    **move_up(t_data *data)
{
	int *coordinates;
	int i;
	int j;

	coordinates = (int *)malloc(sizeof(int) * 2);
	coordinates = get_coordinates(data);
	i = coordinates[0];
	j = coordinates[1];
	if (data->map[i - 1][j] != '1' && data->map[i - 1][j] != 'E')
	{
		data->map[i][j] = '0';
		data->map[i - 1][j] = 'P';
	}
	else
		data->map[i][j] = 'P';
	if (data->map[i - 1][j] == 'E')
	{
		printf("You Win!");
		exit(0);
	}
	else if (data->map[i - 1][j] == 'B')
	{
		printf("You Lose!");
		exit(0);
	}
	return (data->map);
}

char    **move_right(t_data *data)
{
    int *coordinates;
    int i;
    int j;

    coordinates = (int *)malloc(sizeof(int) * 2);
    coordinates = get_coordinates(data);
    i = coordinates[0];
    j = coordinates[1];
    if (data->map[i][j + 1] != '1' && data->map[i][j + 1] != 'E')
    {
        data->map[i][j] = '0';
        data->map[i][j + 1] = 'P';
    }
    else
        data->map[i][j] = 'P';
	if (data->map[i][j + 1] == 'E')
	{
		printf("You Win!");
		exit(0);
	}
	else if (data->map[i][j + 1] == 'B')
	{
		printf("You Lose!");
		exit(0);
	} 
    return (data->map);
}

char    **move_down(t_data *data)
{
    int *coordinates;
    int i;
    int j;

    coordinates = (int *)malloc(sizeof(int) * 2);
    coordinates = get_coordinates(data);
    i = coordinates[0];
    j = coordinates[1];
    if (data->map[i + 1][j] != '1' && data->map[i + 1][j] != 'E')
    {
        data->map[i][j] = '0';
        data->map[i + 1][j] = 'P';
    }
    else
        data->map[i][j] = 'P';
	if (data->map[i + 1][j] == 'E')
	{
		printf("You Win!");
		exit(0);
	}
	else if (data->map[i + 1][j] == 'B')
	{
		printf("You Lose!");
		exit(0);
	}
    return (data->map);
}

char    **move_left(t_data *data)
{
    int *coordinates;
    int i;
    int j;

    coordinates = (int *)malloc(sizeof(int) * 2);
    coordinates = get_coordinates(data);
    i = coordinates[0];
    j = coordinates[1];
    if (data->map[i][j - 1] != '1' && data->map[i][j - 1] != 'E')
    {
        data->map[i][j] = '0';
        data->map[i][j - 1] = 'P';
    }
    else
        data->map[i][j] = 'P';
	if (data->map[i][j - 1] == 'E')
	{
		printf("You Win!");
		exit(0);
	}
	else if (data->map[i][j - 1] == 'B')
	{
		printf("You Lose!");
		exit(0);
	}
    return (data->map);
}