/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   act.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayi <jayi@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 13:46:54 by jayi              #+#    #+#             */
/*   Updated: 2022/02/03 15:23:07 by jayi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*taken_fork(t_philo *philo)
{
	pthread_mutex_lock(philo->left);
	print_message(MSG_FORK, philo->idx, NULL, philo->var);
	pthread_mutex_lock(philo->right);
	print_message(MSG_FORK, philo->idx, NULL, philo->var);
	return (eating);
}

void	*eating(t_philo *philo)
{
	time_t	now;

	pthread_mutex_lock(&philo->eating);
	{
		now = get_mseconds();
		philo->count_eat++;
		philo->time_die = philo->var->time.die + now;
		print_message(MSG_EATING, philo->idx, NULL, philo->var);
	}
	pthread_mutex_unlock(&philo->eating);
	idle(now, philo->var->time.eat);
	return (sleeping);
}

void	*sleeping(t_philo *philo)
{
	time_t	now;

	pthread_mutex_unlock(philo->left);
	pthread_mutex_unlock(philo->right);
	{
		now = get_mseconds();
		print_message(MSG_SLEEPING, philo->idx, NULL, philo->var);
		idle(now, philo->var->time.sleep);
	}
	return (thinking);
}

void	*thinking(t_philo *philo)
{
	print_message(MSG_THINKING, philo->idx, NULL, philo->var);
	return (taken_fork);
}

void	*act(void *data)
{
	t_philo *const	philo = data;
	void			*(*current)(t_philo *);

	current = taken_fork;
	if (philo->idx & 1)
		usleep(philo->var->time.eat * START_DELAY);
	while (philo->var->is_end == 0)
		current = current(philo);
	return (NULL);
}
