/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmoghadd <pmoghadd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 18:06:42 by pmoghadd          #+#    #+#             */
/*   Updated: 2022/09/10 20:39:50 by pmoghadd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/fdf.h"

void	free_matrix(t_data	*img)
{
	int	i;

	i = 0;
	while (i < img->rows)
	{
		free(img->data[i]);
		i++;
	}
	free(img->data);
}

void	free_color(t_data	*img)
{
	int	i;

	i = 0;
	while (i < img->rows)
	{
		free(img->color[i]);
		i++;
	}
	free(img->color);
}

int	close_x(t_data *img)
{
	if (img->img && img->mlx)
		mlx_destroy_image(img->mlx, img->img);
	exit(0);
}

void	error_exit(char *s)
{
	ft_printf(s);
	exit(0);
}

void	errors(char *s, t_data	*img)
{
	ft_printf(s);
	if (img && img->img && img->mlx)
	{
		mlx_destroy_image(img->mlx, img->img);
	}
	if (img && img->mlx_win && img->mlx)
	{		
		mlx_destroy_window(img->mlx, img->mlx_win);
	}
	if (img->data)
		free_matrix(img);
	if (img->color)
		free_color(img);
	exit(0);
}
