/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   release.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayi <jayi@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 01:33:02 by jayi              #+#    #+#             */
/*   Updated: 2022/01/30 21:44:28 by jayi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	release(t_var *var)
{
	int	idx;

	idx = -1;
	while (++idx < var->count)
		pthread_detach(var->philos[idx].act);
	idx = -1;
	while (++idx < var->count)
		pthread_detach(var->philos[idx].check_die);
	if (var->must_eat != -1)
		pthread_detach(var->check_must_eat);
	while (var->is_end == 0)
	{
	}
	while (--idx >= 0)
	{
		pthread_mutex_destroy(&var->philos[idx].fork);
		pthread_mutex_destroy(&var->philos[idx].eat_or_die);
	}
	free(var->philos);
}
