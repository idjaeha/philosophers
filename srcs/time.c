/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayi <jayi@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 17:16:56 by jayi              #+#    #+#             */
/*   Updated: 2022/01/28 06:31:38 by jayi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

time_t	get_mseconds(void)
{
	static time_t	start_sec = 0;
	struct timeval	time;

	gettimeofday(&time, NULL);
	if (start_sec == 0)
		start_sec = time.tv_sec; 
	return ((time.tv_sec - start_sec) * 1000 + time.tv_usec / 1000);
}

suseconds_t	get_useconds(void)
{
	struct timeval	time;
	gettimeofday(&time, NULL);

	return (time.tv_usec);
}
