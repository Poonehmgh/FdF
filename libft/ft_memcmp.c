/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmoghadd <pmoghadd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 19:28:17 by pmoghadd          #+#    #+#             */
/*   Updated: 2022/05/27 21:15:07 by pmoghadd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

int	ft_memcmp(const void *str1, const void *str2, size_t n)
{
	unsigned char	*caststr1;
	unsigned char	*caststr2;
	int				diff;
	size_t			i;

	i = 0;
	caststr1 = (unsigned char *)str1;
	caststr2 = (unsigned char *)str2;
	while (i < n)
	{
		diff = caststr1[i] - caststr2[i];
		if (caststr1[i] != caststr2[i])
			return (diff);
		i++;
	}
	return (0);
}
