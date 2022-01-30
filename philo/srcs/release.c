/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   release.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayi <jayi@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 01:33:02 by jayi              #+#    #+#             */
/*   Updated: 2022/01/30 23:06:45 by jayi             ###   ########.fr       */
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
		pthread_join(var->philos[idx].check_die, NULL);
	if (var->must_eat != -1)
		pthread_join(var->check_must_eat, NULL);
	while (--idx >= 0)
	{
		pthread_mutex_destroy(&var->philos[idx].fork);
		pthread_mutex_destroy(&var->philos[idx].is_end);
	}
	free(var->philos);
}
