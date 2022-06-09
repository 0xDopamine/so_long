/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaioumy <mbaioumy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 06:04:24 by mbaioumy          #+#    #+#             */
/*   Updated: 2022/06/07 06:04:24 by mbaioumy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include "libft.h"

int	check_player(char **map)
{
	int	i;
	int	j;
	int	player_count;

	i = 0;
	player_count = 0;
	while (map[i])
	{
		j = 0;
		while(map[i][j])
		{
			if (map[i][j] == 'P')
				player_count++;
			j++;
		}
		i++;
	}
	if (player_count == 1)
		return (1);
	else
		return (0);		
}

int	check_exit(char **map)
{
	int	i;
	int	j;
	int	exit_count;

	i = 0;
	exit_count = 0;
	while (map[i])
	{
		j = 0;
		while(map[i][j])
		{
			if (map[i][j] == 'E')
				exit_count++;
			j++;
		}
		i++;
	}
	if (exit_count == 1)
		return (1);
	else
		return (0);	
}

int	check_collectibles(char **map)
{
	int	i;
	int	j;
	int	collect_count;

	i = 0;
	collect_count = 0;
	while (map[i])
	{
		j = 0;
		while(map[i][j])
		{
			if (map[i][j] == 'C')
				collect_count++;
			j++;
		}
		i++;
	}
	if (collect_count < 1)
		return (0);
	else
		return (1);	
}

int	check_borders_sides(char **map, int x)
{
	int	i;

	i = 0;
	while (map[i])
	{
		if (map[i][0] != '1')
			return (0);
		if (map[i][x] != '1')
			return (0);
		i++;
	}
	return (1);
}

int	check_borders_top(char **map, int y)
{
	int	i;

	i = 0;
	while (map[0][i])
	{
		if (map[0][i] != '1')
			return (0);
		i++;
	}
	i = 0;
	while (map[y][i])
	{
		if (map[y][i] != '1')
			return (0);
		i++;
	}
	return (1);
}

int	get_x(char **map)
{
	int	x;
	int	i;
	int	temp;

	i = 0;
	x = ft_strlen(map[i]);
	while (map[++i])
	{
		temp = ft_strlen(map[i]);
		if (x != temp)
			return (0);
	}
	return (x);
}

int	get_y(char **map)
{
	int	y;

	y = 0;
	while (map[y])
		y++;
	return (y);
}

int main()
{
	int		i;
	int		file;
	char	*arr;
	char	*buff;
	char	**map;
	int		x;
	int		y;

	y = 0;
	buff = ft_strdup("");
	arr = ft_strdup("");
	while (y < 6)
	{
		file = open("map.ber", O_RDONLY);
		buff = get_next_line(file);
		arr = ft_strjoin(arr, buff);
		y++;
	}
	map = ft_split(arr, '\n');
	x = get_x(map) - 1;
	y = get_y(map) - 1;
	if (check_borders_sides(map, x) && check_borders_top(map, y)
		&& check_collectibles(map) && check_exit(map) && check_player(map))
		printf("map is valid\n");
	else
		printf("invalid map\n");

	return 0;
}