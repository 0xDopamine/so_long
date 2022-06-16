/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaioumy <mbaioumy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 22:25:30 by mbaioumy          #+#    #+#             */
/*   Updated: 2022/06/16 19:16:20 by mbaioumy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <mlx.h>

int key_hook(int key, int x, int y, void *ptr)
{
    // t_data *data;
    
    // data = (t_data *)ptr;
    // mlx_destroy_window(data->mlx, data->win);
    printf("abida is here %d", key);
    return (0);
}

