/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmoghadd <pmoghadd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 18:11:20 by pmoghadd          #+#    #+#             */
/*   Updated: 2022/05/27 21:18:33 by pmoghadd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int			i;
	const char	*dst;

	i = ft_strlen((char *)s);
	dst = 0;
	while (i >= 0)
	{
		if ((unsigned char)s[i] == (unsigned char)c)
		{
			dst = &s[i];
			return ((char *)dst);
		}
		i--;
	}
	return (0);
}
