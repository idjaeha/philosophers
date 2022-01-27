/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   act.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayi <jayi@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 13:46:54 by jayi              #+#    #+#             */
/*   Updated: 2022/01/27 14:58:13 by jayi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
#include <stdio.h>

/*
	밥 -> 잠 -> 생각
	1. 집으려고할때 뮤텍스를 건다.
		1. 
	2. 
*/

static void	print_status(int status, int idx)
{
	struct timeval	time;
	const char *message[] = {"died", "is eating", "is sleeping", "is thinking", "has taken a fork"};

	gettimeofday(&time, NULL);
	printf("%d %d %s\n", time.tv_usec % 1000, idx, message[status]);
}

void	*act(void *data)
{
	const t_var	*philo = ((t_arg *)data)->philo;
	int	idx = ((t_arg *)data)->idx;

	if (philo->status[idx] == STATUS_SLEEPING)
	{
		
	}
	else if (philo->status[idx] == STATUS_EATING)
	{
		
	}
	else if (philo->status[idx] == STATUS_THINKING)
	{
		// pthread_mutex_lock(&philo->fork_lock);
		// pthread_mutex_unlock(&philo->fork_lock);
	}
	else if (philo->status[idx] == STATUS_DIED)
	{
		
	}
	else
		philo_error("잘못된 철학자 상태입니다.\n", 0);
	print_status(philo->status[idx], idx);
	return NULL;
}