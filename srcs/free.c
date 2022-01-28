/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayi <jayi@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 01:33:02 by jayi              #+#    #+#             */
/*   Updated: 2022/01/29 03:45:37 by jayi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	free_all(t_var *var)
{
	int	idx;

	idx = var->count + 1;
	free(var->philos);
	free(var->philo_threads);
	while (--idx > 0)
		pthread_mutex_destroy(&var->forks[idx]);
	free(var->forks);
}
