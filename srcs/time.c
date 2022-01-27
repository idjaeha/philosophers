/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayi <jayi@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 17:16:56 by jayi              #+#    #+#             */
/*   Updated: 2022/01/27 18:00:18 by jayi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

time_t	get_mseconds(void)
{
	static time_t	start = 0;
	struct timeval	time;
	gettimeofday(&time, NULL);
	if (start == 0)
		start = time.tv_sec;

	return ((time.tv_sec - start) * 1000 + time.tv_usec / 1000);
}

suseconds_t	get_useconds(void)
{
	struct timeval	time;
	gettimeofday(&time, NULL);

	return (time.tv_usec);
}
