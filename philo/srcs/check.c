/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayi <jayi@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 05:26:08 by jayi              #+#    #+#             */
/*   Updated: 2022/01/31 02:46:17 by jayi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*check_die(void *data)
{
	t_philo	*philo;
	time_t	now;

	philo = (t_philo *)data;
	while (philo->var->is_end == 0)
	{
		pthread_mutex_lock(&philo->is_end);
		now = get_mseconds();
		if (now >= philo->time_die)
		{
			print_message(now, MSG_DIED, philo->idx);
			philo->var->is_end = 1;
			return (NULL);
		}
		pthread_mutex_unlock(&philo->is_end);
		usleep(5000);
	}
	return (NULL);
}

void	*check_must_eat(void *data)
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
			checker += var->philos[idx].count_eat >= var->must_eat;
		if (checker == var->count)
			var->is_end = 1;
		usleep(5000);
	}
	return (NULL);
}
