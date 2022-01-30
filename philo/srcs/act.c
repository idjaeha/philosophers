/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   act.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayi <jayi@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 13:46:54 by jayi              #+#    #+#             */
/*   Updated: 2022/01/30 22:24:44 by jayi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static void	eating(t_philo *philo)
{
	time_t	now;

	pthread_mutex_lock(philo->left);
	print_message(get_mseconds(), MSG_FORK, philo->idx);
	pthread_mutex_lock(philo->right);
	print_message(get_mseconds(), MSG_FORK, philo->idx);
	pthread_mutex_lock(&philo->eat_or_die);
	now = get_mseconds();
	philo->eat++;
	philo->act_end = philo->var->time.eat + now;
	philo->die = philo->var->time.die + now;
	print_message(now, MSG_EATING, philo->idx);
	pthread_mutex_unlock(&philo->eat_or_die);
}

static void	release_fork(t_philo *philo)
{
	pthread_mutex_unlock(philo->left);
	pthread_mutex_unlock(philo->right);
}

static void	sleeping(t_philo *philo)
{
	const time_t	now = get_mseconds();

	philo->act_end = philo->var->time.sleep + now;
	print_message(now, MSG_SLEEPING, philo->idx);
}

static void	ft_sleep(time_t start, time_t target)
{
	while (TRUE)
	{
		usleep(target / 5);
		if (get_mseconds() > start + target)
			return ;
	}
}

void	*act(void *data)
{
	t_philo *const	philo = data;

	if (philo->idx & 1)
		usleep(philo->var->time.eat * 100);
	while (philo->var->is_end == 0)
	{
		eating(philo);
		ft_sleep(get_mseconds(), philo->var->time.eat);
		release_fork(philo);
		sleeping(philo);
		ft_sleep(get_mseconds(), philo->var->time.sleep);
		print_message(get_mseconds(), MSG_THINKING, philo->idx);
	}
	return (NULL);
}
