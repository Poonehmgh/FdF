/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmoghadd <pmoghadd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 20:57:47 by pmoghadd          #+#    #+#             */
/*   Updated: 2022/09/10 20:34:59 by pmoghadd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/fdf.h"

int	ft_strlen_array(char	**s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i - 1);
}

void	get_map_size(char	*name, t_data *img)
{
	char	*s;
	int		i;
	int		fd;
	char	**d;

	i = 1;
	fd = open(name, O_RDONLY, 0);
	while (1)
	{
		s = get_next_line(fd);
		if (!s)
			break ;
		if (ft_strchr(s, '.'))
			error_exit("\nError! Map has float numbers.\n\n");
		d = ft_split(s, ' ');
		img->cols = 1 + ft_strlen_array(d);
		free2d(d);
		i++;
		free(s);
	}
	close(fd);
	img->rows = i - 1;
	if (img->rows <= 1 || img->cols <= 1)
		error_exit("\nError! Invalid map input!\n\n");
}

void	initialize_values(t_data *img)
{
	if (img->cols < 20)
	{
		img->zoom = 30;
	}
	else if (img->cols <= 40)
		img->zoom = 20;
	else if (img->cols <= 210)
		img->zoom = 4;
	else
		img->zoom = 1;
	img->zoom_z = 2;
	img->angle = 0.5;
}

void	make_isometric(t_data	*img, t_data *main)
{
	float	ax;
	float	ay;

	(*img).x_iso = ((*img).x - (*img).y) * cos((*main).angle);
	ax = img->x_iso;
	(*img).y_iso = ((*img).x_iso + (*img).y) * sin((*main).angle) - (*img).z;
	ay = img->y_iso;
	img->x = ax;
	img->y = ay;
}

int	main(int argc, char **argv)
{
	t_data	img;

	if (argc != 2)
		error_exit("\nError! Invalid map input!\n\n");
	img.mlx = mlx_init();
	if (!img.mlx)
		errors("\nError!\n\n", &img);
	get_map_size(argv[1], &img);
	initialize_values(&img);
	img.mlx_win = mlx_new_window(img.mlx, SCREEN_WIDTH, SCREEN_HIGHT, "FdF");
	if (!img.mlx_win)
		errors("\nError!\n\n", &img);
	img.img = mlx_new_image(img.mlx, SCREEN_WIDTH, SCREEN_HIGHT);
	if (!img.img)
		errors("\nError!\n\n", &img);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
			&img.endian);
	read_map(argv[1], &img);
	map_offset(&img);
	draw(&img);
	mlx_hook(img.mlx_win, 2, 0, &key_hook, &img);
	mlx_hook(img.mlx_win, 17, 0, &close_x, &img);
	mlx_loop(img.mlx);
}
