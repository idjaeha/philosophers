/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayi <jayi@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 17:16:56 by jayi              #+#    #+#             */
/*   Updated: 2022/02/02 22:26:38 by jayi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

time_t	get_mseconds(void)
{
	static time_t	start = 0;
	struct timeval	time;

	gettimeofday(&time, NULL);
	if (start == 0)
		start = time.tv_sec * 1000 + time.tv_usec / 1000;
	return (time.tv_sec * 1000 + time.tv_usec / 1000 - start);
}

void	idle(time_t start, time_t idle_time)
{
	while (TRUE)
	{
		usleep(idle_time / 2);
		if (get_mseconds() >= start + idle_time)
			return ;
	}
}
