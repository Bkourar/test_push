/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util5.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eenassir <eenassir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 14:28:55 by eenassir          #+#    #+#             */
/*   Updated: 2025/03/15 15:35:34 by eenassir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includs/parse_bonus.h"
#include "../../Includs/raycast_bonus.h"

int	ft_get_map_line_nbr(t_buff *mem)
{
	int	i;
	int	count;

	i = 0;
	count = 1;
	while (mem->array[i])
	{
		if (ft_skip_spaces(mem->array[i])[0] == '1')
			count++;
		i++;
	}
	return (count);
}

int	get_start_array(t_buff *mem)
{
	int	i;

	i = 0;
	while (mem->array[i])
	{
		if (ft_skip_spaces(mem->array[i])[0] == '1')
			break ;
		i++;
	}
	return (i);
}

int	get_map_mem(t_inf *mx, t_buff *mem)
{
	int	j;
	int	i;

	j = 0;
	mx->plan = (char **)malloc(sizeof(char *) * (ft_get_map_line_nbr(mem) + 1));
	if (!mx->plan)
		return (1);
	i = get_start_array(mem);
	while (mem->array[i])
	{
		mx->plan[j] = ft_strdup_1(mem->array[i], mem);
		i++;
		j++;
	}
	mx->plan[j] = NULL;
	mem->array_h = j;
	return (0);
}
