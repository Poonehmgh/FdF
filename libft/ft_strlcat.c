/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmoghadd <pmoghadd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 11:53:58 by pmoghadd          #+#    #+#             */
/*   Updated: 2022/05/27 21:19:27 by pmoghadd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	n;
	size_t	i;

	n = ft_strlen(dst);
	i = 0;
	if (dstsize > n)
	{
		while (i < dstsize - n - 1 && src[i] != '\0')
		{
			dst[n + i] = src[i];
			i++;
		}
		dst[n + i] = '\0';
		return (n + ft_strlen(src));
	}
	else
		return (dstsize + ft_strlen(src));
}
