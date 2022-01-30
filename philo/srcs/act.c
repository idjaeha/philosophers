/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   act.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayi <jayi@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 13:46:54 by jayi              #+#    #+#             */
/*   Updated: 2022/01/30 21:19:00 by jayi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static void	taken_fork(t_philo *philo)
{
	pthread_mutex_lock(philo->left);
	if (philo->var->is_end == 0)
		print_message(get_mseconds(), MSG_FORK, philo->idx);
	pthread_mutex_lock(philo->right);
	if (philo->var->is_end == 0)
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
	time_t	now;

	pthread_mutex_lock(&philo->eat_or_die);
	if (philo->var->is_end == 0)
	{
		now = get_mseconds();
		philo->eat++;
		philo->act_end = philo->var->time.eat + now;
		philo->die = philo->var->time.die + now;
		print_message(now, philo->status++, philo->idx);
	}
	pthread_mutex_unlock(&philo->eat_or_die);
}

static void	start_sleeping(t_philo *philo)
{
	const time_t	now = get_mseconds();

	release_fork(philo);
	philo->act_end = philo->var->time.sleep + now;
	if (philo->var->is_end == 0)
		print_message(now, philo->status++, philo->idx);
}

void	*act(void *data)
{
	t_philo *const	philo = data;

	if ((philo->idx & 1) == 0)
		usleep(philo->var->time.eat * 1000);
	while (++philo->count && philo->var->is_end == 0)
	{
		if (philo->status == TAKEN_FORK)
			taken_fork(philo);
		else if (philo->status == START_EATING)
			start_eating(philo);
		else if (philo->status == START_SLEEPING)
			start_sleeping(philo);
		else if (philo->status == START_THINKING)
		{
			if (philo->var->is_end == 0)
				print_message(get_mseconds(), philo->status, philo->idx);
			philo->status = 0;
		}
		else if (philo->count >= MAX_COUNT && philo->act_end <= get_mseconds())
		{
			philo->status++;
			philo->count = 0;
		}
	}
	return (NULL);
}
