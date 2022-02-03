/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayi <jayi@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 05:26:08 by jayi              #+#    #+#             */
/*   Updated: 2022/02/03 15:21:42 by jayi             ###   ########.fr       */
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
		pthread_mutex_lock(&philo->eating);
		now = get_mseconds();
		if (now >= philo->time_die)
		{
			philo->var->is_end = TRUE;
			print_message(MSG_DIED, philo->idx, (void *)1, philo->var);
			return (NULL);
		}
		pthread_mutex_unlock(&philo->eating);
		usleep(SLEEP_DIED);
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
		{
			ft_putstr_fd("Philosophers finished eating.\n", 1);
			var->is_end = 1;
			return (NULL);
		}
		usleep(SLEEP_MUST_EAT);
	}
	return (NULL);
}
