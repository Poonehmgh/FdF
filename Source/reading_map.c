/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reading_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmoghadd <pmoghadd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 14:28:33 by pmoghadd          #+#    #+#             */
/*   Updated: 2022/09/10 20:40:10 by pmoghadd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/fdf.h"

void	map_offset(t_data	*img)
{
	int	max_iso_x;
	int	max_iso_y;

	max_iso_x = (SCREEN_WIDTH - SCREEN_HIGHT) * cos(0.8) / 2;
	max_iso_y = (max_iso_x + SCREEN_HIGHT / 2) * sin (0.8);
	img->offset_x = (SCREEN_WIDTH - max_iso_x) / 4;
	img->offset_y = (SCREEN_HIGHT - max_iso_y) / 2;
}

void	free2d(char **s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		free(s[i]);
		i++;
	}
	free(s);
}

void	memory_allocation_and_check(t_data *img, int row)
{
	img->color[row] = (int *)malloc(sizeof(int) * (img->cols + 1));
	if (!img->color[row])
		errors("Error while allocating!", img);
	img->data[row] = (int *)(malloc(sizeof(int *) * (img->cols + 1)));
	if (!img->data[row])
		errors("Error while allocating!", img);
}

void	read_map_subfunction(t_data *img, char *s, int fd)
{
	int		i;
	int		j;
	char	**tmp;

	i = 0;
	j = 0;
	while (i < img->rows)
	{
		memory_allocation_and_check(img, i);
		s = get_next_line(fd);
		tmp = ft_split(s, ' ');
		tmp = color_default(tmp, img, i, s);
		while (j < img->cols && tmp[j] && s)
		{
			(*img).data[i][j] = ft_atoi(tmp[j]);
			validity_check(tmp[j]);
			j++;
		}
		(*img).data[i][j] = '\0';
		free(s);
		j = 0;
		i++;
		free2d(tmp);
	}
	img->data[i] = NULL;
}

void	read_map(char *name, t_data *img)
{
	int		fd;
	char	*s;

	s = NULL;
	fd = open(name, O_RDONLY, 0);
	if (fd == -1)
		errors("Error! Not able to read\n\n", img);
	(*img).data = (int **)(malloc(sizeof(int *) * (img->rows + 1)));
	if (!img->data)
		return ;
	img->color = (int **)malloc(sizeof(int *) * (img->rows + 1));
	if (!img->color)
		return ;
	read_map_subfunction(img, s, fd);
	free(s);
	close(fd);
}
