/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmoghadd <pmoghadd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 15:04:12 by pmoghadd          #+#    #+#             */
/*   Updated: 2022/05/29 18:13:43 by pmoghadd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;
	char	*castd;
	char	*casts;

	castd = (char *)dst;
	casts = (char *)src;
	if (n == 0 || (!castd && !casts))
		return (dst);
	i = 0;
	while (i < n)
	{
		castd[i] = casts[i];
		i++;
	}
	return (dst);
}
