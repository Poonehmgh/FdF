/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmoghadd <pmoghadd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 10:26:28 by pmoghadd          #+#    #+#             */
/*   Updated: 2022/06/23 21:47:15 by pmoghadd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	whichformat(const char *str, int *i, va_list list)
{
	int		amount;
	int		signal;

	amount = 0;
	signal = 0;
	if (str[*i + 1] == 'c')
		amount += fchar(list);
	else if (str[*i + 1] == 's')
		amount += fstr(va_arg(list, char *));
	else if (str[*i + 1] == 'p')
		amount += fhex(va_arg(list, unsigned long int), signal = 2);
	else if (str[*i + 1] == 'd' || str[*i + 1] == 'i')
		amount += fint(va_arg(list, int));
	else if (str[*i + 1] == 'u')
		amount += funsigned(va_arg(list, int));
	else if (str[*i + 1] == 'x' || str[*i + 1] == 'X')
	{
		if (str[*i + 1] == 'X')
			signal = 1;
		amount += fhex(va_arg(list, int), signal);
	}
	else if (str[*i + 1] == '%')
		amount += write(1, "%", 1);
	*i = *i + 1;
	return (amount);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	va_list	list;
	int		amount;

	i = 0;
	amount = 0;
	va_start(list, str);
	while (str[i])
	{
		if (str[i] == '%' && str[i + 1])
		{
			if (str[i + 1] && (str[i + 1] == 'c' || str[i + 1] == 'd'
					|| str[i + 1] == 'i' || str[i + 1] == 's'
					|| str[i + 1] == 'x' || str[i + 1] == 'X'
					|| str[i + 1] == 'p' || str[i + 1] == 'u'
					|| str[i + 1] == '%'))
				amount += whichformat(str, &i, list);
		}
		else
			amount += write(1, &str[i], 1);
		i++;
	}
	va_end(list);
	return (amount);
}
