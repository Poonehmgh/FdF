/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmoghadd <pmoghadd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 18:03:43 by pmoghadd          #+#    #+#             */
/*   Updated: 2022/09/10 20:39:53 by pmoghadd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/fdf.h"

void	zoom_map(int key_code, t_data *img)
{
	if (key_code == 12)
		img->zoom += 0.5;
	if (key_code == 13)
		img->zoom -= 0.5;
	if (key_code == 14)
		img->zoom_z += 1;
	if (key_code == 15)
		img->zoom_z -= 1;
	redraw(img);
}

void	move_map_helper(t_data *img)
{
	if (img->img)
	{
		mlx_destroy_image(img->mlx, img->img);
		img->img = mlx_new_image(img->mlx, SCREEN_WIDTH, SCREEN_HIGHT);
	}
	draw(img);
}

void	move_map(int key_code, t_data *img)
{
	if (key_code == 126)
	{
		img->offset_y += 10;
		move_map_helper(img);
	}
	if (key_code == 125)
	{
		img->offset_y -= 10;
		move_map_helper(img);
	}
	if (key_code == 124)
	{
		img->offset_x -= 10;
		move_map_helper(img);
	}
	if (key_code == 123)
	{
		img->offset_x += 10;
		move_map_helper(img);
	}
}

void	rotate_map(int key_code, t_data *img)
{
	if (key_code == 0)
		img->angle += 0.1;
	if (key_code == 1)
		img->angle -= 0.1;
	if (key_code == 256)
		initialize_values(img);
	redraw(img);
}

int	key_hook(int key_code, t_data *img)
{
	if (key_code == 53)
	{
		if (img->img)
			mlx_destroy_image(img->mlx, img->img);
		if (img->mlx_win)
			mlx_destroy_window(img->mlx, img->mlx_win);
		exit(1);
	}
	if (key_code == 126 || key_code == 125 || key_code == 124
		|| key_code == 123)
		move_map(key_code, img);
	if (key_code == 12 || key_code == 13 || key_code == 14 || key_code == 15)
		zoom_map(key_code, img);
	if (key_code == 0 || key_code == 1 || key_code == 256)
		rotate_map(key_code, img);
	return (0);
}
