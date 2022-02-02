/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   act.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayi <jayi@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 13:46:54 by jayi              #+#    #+#             */
/*   Updated: 2022/02/02 18:29:20 by jayi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static void	taken_fork(t_philo *philo)
{
	pthread_mutex_lock(philo->left);
	print_message(get_mseconds(), MSG_FORK, philo->idx);
	pthread_mutex_lock(philo->right);
	print_message(get_mseconds(), MSG_FORK, philo->idx);
}

static void	eating(t_philo *philo)
{
	time_t	now;

	pthread_mutex_lock(&philo->eating);
	{
		now = get_mseconds();
		philo->count_eat++;
		philo->act_end = philo->var->time.eat + now;
		philo->time_die = philo->var->time.die + now;
		print_message(now, MSG_EATING, philo->idx);
	}
	pthread_mutex_unlock(&philo->eating);
	idle(now, philo->var->time.eat);
}

static void	sleeping(t_philo *philo)
{
	time_t	now;

	pthread_mutex_unlock(philo->left);
	pthread_mutex_unlock(philo->right);
	{
		now = get_mseconds();
		philo->act_end = philo->var->time.sleep + now;
		print_message(now, MSG_SLEEPING, philo->idx);
		idle(now, philo->var->time.sleep);
	}
}

static void	thinking(t_philo *philo)
{
	print_message(get_mseconds(), MSG_THINKING, philo->idx);
}

void	*act(void *data)
{
	t_philo *const	philo = data;

	if (philo->idx & 1)
		usleep(philo->var->time.eat * 100);
	while (philo->var->is_end == 0)
	{
		taken_fork(philo);
		eating(philo);
		sleeping(philo);
		thinking(philo);
	}
	return (NULL);
}
