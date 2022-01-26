/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayi <jayi@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 19:30:23 by jayi              #+#    #+#             */
/*   Updated: 2022/01/26 21:19:32 by jayi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	main(int argc, char *argv[])
{
	t_var	philo;

	if (argc == 5 || argc == 6)
	{
		init(&philo, argc, argv);
		// 실행문
		free(philo.philos);
		free(philo.forks);
		return (1);
	}
	ft_putstr_fd("올바르지 않은 인자의 개수\n", 1);
	return (1);
}
