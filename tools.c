/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaioumy <mbaioumy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 22:17:46 by mbaioumy          #+#    #+#             */
/*   Updated: 2022/06/30 22:24:03 by mbaioumy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	collectibles_counter(t_data *data)
{
	int	i;
	int	j;

	data->collectibles_c = 0;
	i = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] == 'C')
				data->collectibles_c++;
			j++;
		}
		i++;
	}
	return (data->collectibles_c);
}

int	game_over(t_data *data)
{
	if (data->collectibles_c == data->collected)
		return (1);
	else
		return (0);
}