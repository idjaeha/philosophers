/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayi <jayi@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 19:30:23 by jayi              #+#    #+#             */
/*   Updated: 2022/02/02 22:18:23 by jayi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	main(int argc, char *argv[])
{
	t_var	var;

	if (argc == 5 || argc == 6)
	{
		if (init(&var, argc, argv) == FAIL)
			return (FAIL);
		if (start(&var) == FAIL)
			return (FAIL);
		release(&var);
		return (SUCCESS);
	}
	ft_putstr_fd("올바르지 않은 인자의 개수\n", 2);
	return (FAIL);
}
