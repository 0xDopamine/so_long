/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaioumy <mbaioumy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 22:25:30 by mbaioumy          #+#    #+#             */
/*   Updated: 2022/06/28 00:11:12 by mbaioumy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <mlx.h>

int key_hook(int key, void *ptr)
{
    t_data  *data;
    t_str   *paths;

    data = (t_data *)ptr;
    if (key == 53)
    {
        mlx_clear_window(data->mlx, data->win);
        exit(1);
    }
    if (key == 13 || key == 126)
    {
        mlx_clear_window(data->mlx, data->win);
        draw(move_up(data), data, paths);
    }
    if (key == 2 || key == 124)
    {
        mlx_clear_window(data->mlx, data->win);
        draw(move_right(data), data, paths);
    }
    if (key == 1 || key == 125)
    {
        mlx_clear_window(data->mlx, data->win);
        draw(move_down(data), data, paths);
    }
    if (key == 0 || key == 123)
    {
        mlx_clear_window(data->mlx, data->win);
        draw(move_left(data), data, paths);
    }
    return (0);
}

