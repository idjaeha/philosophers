/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   release.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayi <jayi@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 01:33:02 by jayi              #+#    #+#             */
/*   Updated: 2022/02/02 23:56:46 by jayi             ###   ########.fr       */
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
	while (var->is_end == FALSE)
		usleep(5000);
	usleep(5000);
	while (--idx >= 0)
	{
		pthread_mutex_destroy(&var->philos[idx].fork);
		pthread_mutex_destroy(&var->philos[idx].eating);
	}
	pthread_mutex_destroy(&var->print);
	free(var->philos);
}
