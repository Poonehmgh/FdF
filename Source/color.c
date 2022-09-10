/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmoghadd <pmoghadd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 13:03:49 by pmoghadd          #+#    #+#             */
/*   Updated: 2022/09/10 21:00:51 by pmoghadd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/fdf.h"

long int	decimal_value(char	*hexcolor)
{
	int			i;
	int			j;
	long int	decimal;

	j = 0;
	i = 2;
	decimal = 0;
	while (hexcolor[i])
	{
		while ((hexcolor[i] != "0123456789abcdef"[j]
				&& hexcolor[i] != "0123456789ABCDEF"[j]) && j <= 15)
			j++;
		decimal *= 16;
		decimal = j + decimal;
		j = 0;
		i++;
	}
	return (decimal);
}

void	save_hex_color(char *hexcolor, t_data	*img, int row, int col)
{
	img->color[row][col] = decimal_value(hexcolor);
}

/*if it finds ',' it means there is color. so splits every element of map the first of which is the data 
and the second one being the color. I had so many issues with this function because it caused so many leaks. 
freeing is tricky anyway!*/

char	**save_color(char **s, t_data *img, int row)
{
	char	**buffer;
	char	**tmp;
	int		i;
	int		j;

	i = 0;
	j = 0;
	tmp = (char **)malloc(sizeof(char *) * (img->cols + 1));
	if (!tmp)
		return (NULL);
	while (s[i])
	{
		buffer = ft_split(s[i], ',');
		tmp[i] = buffer[0];
		if (buffer[1] && buffer[1][0] == '0' && buffer[1][1] == 'x')
			save_hex_color(buffer[1], img, row, i);
		if (buffer[1])
			free(buffer[1]);
		buffer[0] = NULL;
		free2d(buffer);
		i++;
	}
	tmp[i] = NULL;
	free2d(s);
	return (tmp);
}

char	**color_default(char **tmp, t_data	*img, int row, char *line)
{
	int	i;

	i = 0;
	while (i < img->cols)
	{
		img->color[row][i] = 16777215;
		i++;
	}
	img->color[row][i] = '\0';
	if (ft_strchr(line, ','))
			tmp = save_color(tmp, img, row);
	return (tmp);
}
