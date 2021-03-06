/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaioumy <mbaioumy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 06:04:24 by mbaioumy          #+#    #+#             */
/*   Updated: 2022/06/30 22:32:55 by mbaioumy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	x -= 1;
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
	y -= 1;
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

void	print_map(char **map)
{
	int	i;
	
	i = 0;
	while (map[i])
	{
		printf("%s\n", map[i]);
		i++;
	}
}

void	check_ber(char *argv)
{
	int	i;

	i = 0;
	while (argv[i] != '.')
		i++;
	printf("%c\n", argv[i]);
	if (ft_strncmp(".ber", argv + i, ft_strlen(argv + i)) == 0)
		return ;
	else
		printf("map file invalid\n");
	exit(1);
}

int main(int argc, char **argv)
{
	int		file;
	char	*arr;
	char	*buff;
	char	**map;
	t_str	*paths;
	t_data	*data;

	data = malloc(sizeof(t_data));
	paths = malloc(sizeof(t_str));
	data->counter = 0;
	data->collected = 0;
	buff = ft_strdup("");
	arr = ft_strdup("");
	check_ber(argv[1]);
	file = open(argv[1], O_RDONLY);
	buff = get_next_line(file);
	while (buff)
	{
		arr = ft_strjoin(arr, buff);
		buff = get_next_line(file);
	}
	data->map = ft_split(arr, '\n');
	data->x = get_x(data->map);
	data->y = get_y(data->map);
	data->collectibles_c = collectibles_counter(data);
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, data->x * 70, data->y * 70, "test");
	if (check_borders_sides(data->map, data->x) && check_borders_top(data->map, data->y)
		&& check_collectibles(data->map) && check_exit(data->map) && check_player(data->map))
		draw(data->map, data, paths);
	else
	{
		printf("invalid map\n");
		return 0;
	}
	mlx_key_hook(data->win, key_hook, data);
	mlx_loop_hook(data->mlx, animation, data);
	mlx_loop(data->mlx);
	return (0);
}