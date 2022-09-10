/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmoghadd <pmoghadd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 13:12:22 by pmoghadd          #+#    #+#             */
/*   Updated: 2022/09/10 20:57:32 by pmoghadd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/fdf.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	if (x < SCREEN_WIDTH && y < SCREEN_HIGHT && x > 0 && y > 0)
	{
		dst = data->addr + (y * data->line_length
				+ x * (data->bits_per_pixel / 8));
		*(unsigned int *)dst = color;
	}
}

void	initialize_points(t_data	*a, t_data	*b, t_data *img, int *i)
{
	a->delta_x = abs(a->x - b->x);
	a->delta_y = abs(a->y - b->y);
	img->decision_factor = 2 * a->delta_y - a->delta_x;
	*i = 0;
}

void	draw_x(t_data	*a, t_data	*b, t_data img, int color)
{
	int	i;

	initialize_points(a, b, &img, &i);
	while (i <= a->delta_x && abs(a->x) <= SCREEN_WIDTH
		&& abs(a->y) <= SCREEN_HIGHT)
	{
		if (a->x < b->x)
			a->x++;
		else
			a->x--;
		if (img.decision_factor < 0)
			img.decision_factor = img.decision_factor + 2 * a->delta_y;
		else
		{
			if (a->y < b->y)
				a->y++;
			else
				a->y--;
			img.decision_factor = img.decision_factor
				+ 2 * a->delta_y - 2 * a->delta_x;
		}
		i++;
		my_mlx_pixel_put(&img, 2 * img.offset_x + a->x,
			2 * img.offset_y + a->y, color);
	}
}

void	draw_y(t_data	*a, t_data	*b, t_data img, int color)
{
	int	i;

	initialize_points(a, b, &img, &i);
	while (i <= a->delta_y && abs(a->x) <= SCREEN_WIDTH
		&& abs(a->y) <= SCREEN_HIGHT)
	{
		if (a->y < b->y)
			a->y++;
		else
			a->y--;
		if (img.decision_factor < 0)
			img.decision_factor = img.decision_factor + 2 * a->delta_x;
		else
		{
			if (a->x < b->x)
				a->x++;
			else
				a->x--;
			img.decision_factor = img.decision_factor
				+ 2 * a->delta_x - 2 * a->delta_y;
		}
		i++;
		my_mlx_pixel_put(&img, 2 * img.offset_x + a->x,
			2 * img.offset_y + a->y, color);
	}
}

/* draws the line with bresenham algorithm*/

void	bresenham(t_data	*a, t_data	*b, t_data img, int color)
{
	int	delta_x;
	int	delta_y;

	delta_x = abs(a->x - b->x);
	delta_y = abs(a->y - b->y);
	if (delta_x > delta_y)
		draw_x(a, b, img, color);
	else
		draw_y(a, b, img, color);
}
