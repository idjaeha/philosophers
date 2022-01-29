/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayi <jayi@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 05:26:08 by jayi              #+#    #+#             */
/*   Updated: 2022/01/29 16:26:20 by jayi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*check_die(void *data)
{
	t_var	*var;
	int		idx;

	var = (t_var *)data;
	while (var->is_end == 0)
	{
		idx = -1;
		while (++idx < var->count)
		{
			if (get_mseconds() >= var->philos[idx].die)
			{
				var->is_end = 1;
				print_message(get_mseconds(), MSG_DIED, idx);
				break ;
			}
		}
	}
	return (NULL);
}

void	*check_eat(void *data)
{
	t_var	*var;
	int		idx;
	int		checker;

	var = (t_var *)data;
	while (var->is_end == 0)
	{
		idx = -1;
		checker = 0;
		while (++idx < var->count)
			checker += var->philos[idx].eat >= var->must_eat;
		if (checker == var->count)
			var->is_end = 1;
	}
	return (NULL);
}
