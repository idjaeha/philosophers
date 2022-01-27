/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayi <jayi@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 20:17:19 by jayi              #+#    #+#             */
/*   Updated: 2022/01/27 15:31:48 by jayi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	philo_exit(void)
{
	exit(1);
}

void	philo_error(char *msg, int flag)
{
	int	len;

	len = 0;
	if (DEBUG)
	{
		while (msg[len] != '\0')
			++len;
		write(STDERR_FILENO, msg, len);
		write(STDERR_FILENO, "\n", 1);
	}
	write(STDERR_FILENO, "Error\n", 6);
	exit(flag);
}
