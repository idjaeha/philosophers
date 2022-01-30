/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   act.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayi <jayi@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 13:46:54 by jayi              #+#    #+#             */
/*   Updated: 2022/01/30 23:06:45 by jayi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static void	eating(t_philo *philo)
{
	time_t	now;

	pthread_mutex_lock(&philo->is_end);
	if (philo->var->is_end == FALSE)
	{
		now = get_mseconds();
		philo->count_eat++;
		philo->act_end = philo->var->time.eat + now;
		philo->time_die = philo->var->time.die + now;
		print_message(now, MSG_EATING, philo->idx);
	}
	pthread_mutex_unlock(&philo->is_end);
}

static void	release_fork(t_philo *philo)
{
	pthread_mutex_unlock(philo->left);
	pthread_mutex_unlock(philo->right);
}

static void	sleeping(t_philo *philo)
{
	const time_t	now = get_mseconds();

	pthread_mutex_lock(&philo->is_end);
	philo->act_end = philo->var->time.sleep + now;
	print_message(now, MSG_SLEEPING, philo->idx);
	pthread_mutex_unlock(&philo->is_end);
}

static void	taken_fork(t_philo *philo)
{
	pthread_mutex_lock(&philo->is_end);
	pthread_mutex_lock(philo->left);
	print_message(get_mseconds(), MSG_FORK, philo->idx);
	pthread_mutex_unlock(&philo->is_end);
	pthread_mutex_lock(&philo->is_end);
	pthread_mutex_lock(philo->right);
	print_message(get_mseconds(), MSG_FORK, philo->idx);
	pthread_mutex_unlock(&philo->is_end);
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
		philo_sleep(get_mseconds(), philo->var->time.eat);
		release_fork(philo);
		sleeping(philo);
		philo_sleep(get_mseconds(), philo->var->time.sleep);
		pthread_mutex_lock(&philo->is_end);
		print_message(get_mseconds(), MSG_THINKING, philo->idx);
		pthread_mutex_unlock(&philo->is_end);
	}
	return (NULL);
}
