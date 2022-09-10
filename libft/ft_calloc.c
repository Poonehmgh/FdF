/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmoghadd <pmoghadd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 09:45:49 by pmoghadd          #+#    #+#             */
/*   Updated: 2022/05/29 20:16:05 by pmoghadd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	size_t	i;
	char	*output;

	i = 0;
	output = malloc (count * size);
	if (!output)
		return (NULL);
	while (i < size * count)
	{
		output[i] = 0;
		i++;
	}
	return (output);
}
