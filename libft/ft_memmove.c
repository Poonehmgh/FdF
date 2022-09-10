/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmoghadd <pmoghadd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 19:41:00 by pmoghadd          #+#    #+#             */
/*   Updated: 2022/05/29 18:17:18 by pmoghadd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*castd;
	unsigned char	*casts;

	castd = (unsigned char *)dst;
	casts = (unsigned char *)src;
	if (len == 0 || (!castd && !casts))
		return (dst);
	if (dst < src)
		dst = ft_memcpy(dst, src, len);
	else
	{
		while (len--)
		{
			castd[len] = casts[len];
		}
	}
	return (dst);
}
