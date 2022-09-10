/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmoghadd <pmoghadd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 09:50:35 by pmoghadd          #+#    #+#             */
/*   Updated: 2022/06/23 15:16:34 by pmoghadd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	fchar(va_list list)
{
	char	c;

	c = va_arg(list, int);
	return (write(1, &c, 1));
}

int	fstr(char *s)
{
	if (!s)
		return (write(1, "(null)", 6));
	return (write(1, s, ft_strlen(s)));
}

int	fint(int n)
{
	char	*s;
	int		amount;

	amount = 0;
	s = ft_itoa2(n);
	amount = write(1, s, ft_strlen(s));
	free(s);
	return (amount);
}

int	funsigned(unsigned int n)
{
	char	*s;
	int		amount;
	long	ln;

	amount = 0;
	ln = (long)n;
	s = ft_itoa(n);
	amount = write(1, s, ft_strlen(s));
	free(s);
	return (amount);
}
