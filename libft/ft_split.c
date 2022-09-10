/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmoghadd <pmoghadd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 13:54:40 by user0             #+#    #+#             */
/*   Updated: 2022/08/15 11:17:59 by pmoghadd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	howmany(char const *s, char c)
{
	int	amount;
	int	i;

	if (!s)
		return (0);
	amount = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			amount++;
		i++;
	}
	return (amount);
}

void	*ft_free(char **arr, int j)
{
	int	i;

	i = 0;
	while (i < j)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
	return (NULL);
}

char	*makestr(char **arr, char const *s, char const *a, int *j)
{
	size_t	l;

	l = ft_strlen(s) - ft_strlen(a);
	if (l > 0)
	{
		arr[*j] = ft_substr(s, 0, l);
		if (arr[*j] == NULL)
		{	
			ft_free(arr, *j);
			return (NULL);
		}
		*j = *j + 1;
	}
	else
		return (NULL);
	return (arr[*j - 1]);
}

char	**ft_split(char const *s, char c)
{
	int			j;
	char		**arr;
	char		*a;

	if (!s)
		return (0);
	j = 0;
	a = (char *)s;
	arr = malloc ((howmany(s, c) + 1) * sizeof(char *));
	if (!arr)
		return (NULL);
	while (*s && *a)
	{
		while (*s == c && *s)
			s++;
		a = (char *)s;
		while (*a != c && *a)
			a++;
		arr[j] = makestr (arr, s, a, &j);
		s = a;
	}
	arr[j] = NULL;
	return (arr);
}
