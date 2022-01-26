/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayi <jayi@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 19:30:23 by jayi              #+#    #+#             */
/*   Updated: 2022/01/26 20:22:12 by jayi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"


	
int main(int argc, char *argv[])
{
	t_var philo;
	if (argc == 5 || argc == 6)
	{
		init_argv(&philo, argc, argv);
		return (1);
	}
	else
		return printf("올바르지 않은 인자의 개수\n") > 0;
}