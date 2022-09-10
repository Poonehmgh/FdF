/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmoghadd <pmoghadd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 14:30:32 by pmoghadd          #+#    #+#             */
/*   Updated: 2022/09/10 20:40:05 by pmoghadd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/fdf.h"

void	validity_check(char *num)
{
	int	i;

	i = 0;
	while (num[i])
	{
		if (127 > num[i] && num[i] > 58)
			error_exit("\nError! Invalid map content!\n\n");
		i++;
	}
}
