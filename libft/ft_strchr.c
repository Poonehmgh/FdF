/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmoghadd <pmoghadd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 17:09:23 by pmoghadd          #+#    #+#             */
/*   Updated: 2022/05/27 21:17:34 by pmoghadd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

char	*ft_strchr(const char *s, int c)
{
	int			i;
	const char	*p;

	i = 0;
	while ((unsigned char)s[i] != (unsigned char)c && s[i] != '\0')
		i++;
	if ((unsigned char)s[i] == (unsigned char)c)
	{
		p = &s[i];
		return ((char *)p);
	}
	else
		return (0);
}
