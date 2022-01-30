/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   act.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayi <jayi@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 13:46:54 by jayi              #+#    #+#             */
/*   Updated: 2022/01/31 02:44:50 by jayi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static void	taken_fork(t_philo *philo)
{
	pthread_mutex_lock(philo->left);
	pthread_mutex_lock(&philo->is_end);
	{
		print_message(get_mseconds(), MSG_FORK, philo->idx);
	}
	pthread_mutex_unlock(&philo->is_end);
	pthread_mutex_lock(philo->right);
	pthread_mutex_lock(&philo->is_end);
	{
		print_message(get_mseconds(), MSG_FORK, philo->idx);
	}
	pthread_mutex_unlock(&philo->is_end);
}

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
	idle(get_mseconds(), philo->var->time.eat);
}

static void	sleeping(t_philo *philo)
{
	time_t	now;

	pthread_mutex_unlock(philo->left);
	pthread_mutex_unlock(philo->right);
	pthread_mutex_lock(&philo->is_end);
	{
		now = get_mseconds();
		philo->act_end = philo->var->time.sleep + now;
		print_message(now, MSG_SLEEPING, philo->idx);
	}
	pthread_mutex_unlock(&philo->is_end);
	idle(get_mseconds(), philo->var->time.sleep);
}

static void	thinking(t_philo *philo)
{
	pthread_mutex_lock(&philo->is_end);
	{
		print_message(get_mseconds(), MSG_THINKING, philo->idx);
	}
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
		sleeping(philo);
		thinking(philo);
	}
	return (NULL);
}
