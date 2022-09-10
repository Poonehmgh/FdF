/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmoghadd <pmoghadd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 17:29:12 by pmoghadd          #+#    #+#             */
/*   Updated: 2022/05/27 21:44:51 by pmoghadd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	x;

	i = 0;
	j = 0;
	x = 0;
	if (needle[0] == '\0')
		return ((char *)haystack);
	while (i < len && i < ft_strlen(haystack) && len)
	{
		if (haystack[i] == needle[j])
		{
			x = i - j;
			while (j < ft_strlen(needle) && haystack[j + x] == needle[j])
				j++;
			if (j == ft_strlen(needle) && (j + x <= len))
				return ((char *)&haystack [i]);
			else
				j = 0;
		}
		i++;
	}
	return (0);
}
