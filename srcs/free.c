/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayi <jayi@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 01:33:02 by jayi              #+#    #+#             */
/*   Updated: 2022/01/28 17:06:22 by jayi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	free_all(t_var *var)
{
	free(var->forks);
	free(var->philos);
	free(var->philo_threads);
	pthread_mutex_destroy(&var->fork_lock);
}
