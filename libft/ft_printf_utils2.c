/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmoghadd <pmoghadd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 15:08:55 by pmoghadd          #+#    #+#             */
/*   Updated: 2022/06/25 13:20:58 by pmoghadd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*reverse(char *buf)
{
	char	*str;
	int		i;
	int		j;

	str = malloc(ft_strlen(buf) + 1);
	j = 0;
	i = ft_strlen(buf) - 1;
	while (buf[j])
	{
		str[i] = buf[j];
		i--;
		j++;
	}
	str[ft_strlen(buf)] = '\0';
	return (str);
}

char	charcheck(unsigned long int n, char *buf, int *i, int signal)
{
	if (n % 16 > 9)
	{
		buf[*i] = ((n % 16) % 10) + 'a';
		if (signal == 1)
			buf[*i] = buf[*i] - 32;
	}
	else
		buf[*i] = n % 16 + '0';
	return (buf[*i]);
}

int	putfree(char *str)
{
	int	n;

	n = write(1, str, ft_strlen(str));
	free(str);
	return (n);
}

int	fhex(unsigned long int n, int signal)
{
	int		i;
	int		amount;
	char	*buf;
	char	*reversedbuf;

	i = 0;
	amount = 0;
	if (signal == 0 || signal == 1)
		n = (unsigned int)n;
	buf = malloc(digits(n) + 1);
	if (!buf)
		return (0);
	while (n / 16)
	{
		buf[i++] = charcheck(n, buf, &i, signal);
		n = n / 16;
	}
	buf [i] = charcheck(n, buf, &i, signal);
	buf [i + 1] = '\0';
	reversedbuf = reverse(buf);
	free(buf);
	if (signal == 2)
		amount += write(1, "0x", 2);
	amount += putfree(reversedbuf);
	return (amount);
}

char	*ft_itoa2(int m)
{
	int		i;
	char	*dst;
	int		*ptr;
	long	m_long;

	m_long = (long)m;
	i = 0;
	ptr = &i;
	dst = malloc((digits(m_long) + 1) * sizeof(char));
	if (!dst)
		return (NULL);
	if (m_long < 0)
	{
		m_long = -m_long;
		dst[0] = '-';
		i = 1;
	}
	dst = ft_recursion(m_long, dst, ptr);
	return (dst);
}
