/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   act.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayi <jayi@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 13:46:54 by jayi              #+#    #+#             */
/*   Updated: 2022/01/30 04:04:47 by jayi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static void	taken_fork(t_philo *philo)
{
	pthread_mutex_lock(philo->left);
	pthread_mutex_lock(philo->right);
	print_message(get_mseconds(), MSG_FORK, philo->idx);
	philo->status++;
}

static void	release_fork(t_philo *philo)
{
	pthread_mutex_unlock(philo->left);
	pthread_mutex_unlock(philo->right);
}

static void	start_eating(t_philo *philo)
{
	const time_t	now = get_mseconds();

	pthread_mutex_lock(&philo->eat_or_die);
	philo->eat++;
	philo->act_end = philo->var->time.eat + now;
	philo->die = philo->var->time.die + now;
	print_message(now, philo->status++, philo->idx);
	pthread_mutex_unlock(&philo->eat_or_die);
}

static void	start_sleeping(t_philo *philo)
{
	const time_t	now = get_mseconds();

	release_fork(philo);
	philo->act_end = philo->var->time.sleep + now;
	print_message(now, philo->status++, philo->idx);
}

void	*act(void *data)
{
	t_philo	*philo;

	philo = (t_philo *)data;
	if ((philo->idx & 1) == 0)
		usleep(philo->var->time.eat * 1000);
	while (philo->var->is_end == 0)
	{
		if (philo->status == TAKEN_FORK)
			taken_fork(philo);
		else if (philo->status == START_EATING)
			start_eating(philo);
		else if (philo->status == START_SLEEPING)
			start_sleeping(philo);
		else if (philo->status == START_THINKING)
		{
			print_message(get_mseconds(), philo->status, philo->idx);
			philo->status = 0;
		}
		else if (philo->act_end <= get_mseconds())
			philo->status++;
	}
	return (NULL);
}
