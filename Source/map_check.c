/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmoghadd <pmoghadd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 14:30:32 by pmoghadd          #+#    #+#             */
/*   Updated: 2022/09/10 20:57:03 by pmoghadd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/fdf.h"

/*checks if there is non numbers in each item of map. actually this is not very complete
and could have been better. but since some maps had spaces after numbers, when splitting they give a \n as an element and
when i make the below function restricter, it gives me irrelevent responce for those maps. So I didnt go as restrict as in push swap for 
charactter check and +0 or -0 check or so.*/

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
