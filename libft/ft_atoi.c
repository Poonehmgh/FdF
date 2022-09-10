/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmoghadd <pmoghadd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 14:16:35 by pmoghadd          #+#    #+#             */
/*   Updated: 2022/09/10 16:11:25 by pmoghadd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"
#include<stdio.h>

int	charnumeric(char c)
{
	if ((c >= '0' && c <= '9'))
		return (1);
	return (0);
}

int charnumeric2(char c)
{
	if ((c >= '0' && c <= '9') || c == '\n')
		return (1);
	return (0);
}
long long	str_to_nbr(char *str)
{
	int			i;
	long long	result;

	i = 0;
	result = 0;
	while (charnumeric(str[i]))
	{
		result = result * 10 + str[i] - '0';
		i++;
	}
	if (str[i] == '.')
	{
		i++;
		while (str[i])
		{
			if (!ft_isdigit(str[i]))
				return (0);
			i++;
		}
	}
	if (!charnumeric2(str[i]) && str[i])
		return (0);
	return (result);
}

int	check_sign(char *str, int *result)
{
	int	i;

	i = 0;
	*result = 1;
	if (!charnumeric(str[i]))
	{
		if (str[i] == '-')
			*result = -1 * *result;
		else if (str[i] != '+')
			return (-5);
		i++;
	}
	return (i);
}

int	skip_spaces(char *str)
{
	int	i;

	i = 0;
	while (str[i] == ' ' || str[i] == '\f' || str[i] == '\n'
		|| str[i] == '\r' || str[i] == '\t' || str[i] == '\v')
		i++;
	return (i);
}

int	ft_atoi(const char *str)
{
	int		sign;
	int		index;
	int		tmp;
	char	*tstr;

	tstr = (char *)str;
	index = skip_spaces(tstr);
	tmp = check_sign(tstr + index, &sign);
	if (tmp == -5)
		return (0);
	index = tmp + index;
	if ((sign * str_to_nbr(tstr + index) > 2147483647)
		|| (sign * str_to_nbr(tstr + index) < -2147483648))
		return (0);
	return (sign * str_to_nbr(tstr + index));
}
