/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmoghadd <pmoghadd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 18:56:22 by pmoghadd          #+#    #+#             */
/*   Updated: 2022/05/29 18:03:40 by pmoghadd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t					i;
	unsigned char			*casts;

	i = 0;
	casts = (unsigned char *)s;
	while (i < n)
	{
		if (casts[i] == (unsigned char)c)
		{
			return ((void *)(s + i));
		}
	i++;
	}
	return (NULL);
}
