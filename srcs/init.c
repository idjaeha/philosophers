/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayi <jayi@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 20:19:43 by jayi              #+#    #+#             */
/*   Updated: 2022/01/26 20:30:02 by jayi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	check_str(char *str)
{
	while (*str != '\0')
	{
		if (('0' <= *str && *str <= '9') || *str == ' ' || *str == '+' || *str == '-')
			str++;
		else
			philo_error("올바르지 않은 인자 값", 1);
	}
}

void	init_argv(t_var *philo, int argc, char *argv[])
{
	check_str(argv[1]);
	check_str(argv[2]);
	check_str(argv[3]);
	check_str(argv[4]);
	philo->philo_count = ft_atoi(argv[1]);
	philo->time.die = ft_atoi(argv[2]);
	philo->time.eat = ft_atoi(argv[3]);
	philo->time.sleep = ft_atoi(argv[4]);
	if (argc == 5)
	{
		check_str(argv[5]);
		philo->must_eat = ft_atoi(argv[5]);
	}
}