/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmoghadd <pmoghadd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 14:59:58 by pmoghadd          #+#    #+#             */
/*   Updated: 2022/09/10 20:39:47 by pmoghadd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/fdf.h"

void	print_keys(t_data	*img)
{
	char	*str;

	str = "Q: Zoom-in    W: Zoom-out       E:  Zoom-Z-in       R: Zoom-Z-out\n";
	mlx_string_put(img->mlx, img->mlx_win, 5, 10, 0x00aaffbb, str);
	str = "Up: Moveup   Down: Move down   Right: Move right   Left: Move left\n";
	mlx_string_put(img->mlx, img->mlx_win, 5, 30, 0x00bbffcc, str);
	str = "A: Rotate right     S: Rotate left\n";
	mlx_string_put(img->mlx, img->mlx_win, 5, 50, 0x00ccffdd, str);
	str = "ESC: Exit            CTRL: Default zoom view\n";
	mlx_string_put(img->mlx, img->mlx_win, 5, 70, 0x00ddffee, str);
}

void	draw_sub_function2(t_data *a, t_data	*img, int i, int j)
{
	a->x = img->zoom * i;
	a->y = img->zoom * j;
	a->z = img->zoom_z * img->data[j][i];
	make_isometric(a, img);
}

void	draw_sub_function1(t_data *a, t_data *b, t_data *img)
{
	draw_sub_function2(a, img, img->x, img->y);
	draw_sub_function2(b, img, img->x + 1, img->y);
	bresenham(a, b, *img, img->color[img->y][img->x]);
}

void	draw_sub_function3(t_data *a, t_data *b, t_data *img)
{
	draw_sub_function2(a, img, img->x, img->y);
	draw_sub_function2(b, img, img->x, img->y + 1);
	bresenham(a, b, *img, img->color[img->y][img->x]);
}

void	draw(t_data *img)
{
	t_data	a;
	t_data	b;

	img->y = 0;
	img->x = 0;
	while (img->y < img->rows)
	{
		while (img->x < img->cols)
		{
			if (img->x < img->cols - 1)
				draw_sub_function1(&a, &b, img);
			if (img->y < img->rows - 1)
				draw_sub_function3(&a, &b, img);
			img->x++;
		}
		img->x = 0;
		img->y++;
	}
	mlx_put_image_to_window(img->mlx, img->mlx_win, img->img, 0, 0);
	print_keys(img);
}
