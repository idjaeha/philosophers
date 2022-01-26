/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayi <jayi@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 19:30:20 by jayi              #+#    #+#             */
/*   Updated: 2022/01/26 20:30:16 by jayi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include "philo_define.h"
# include "philo_types.h"

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

int		ft_atoi(const char *str);
void	philo_error(char *msg, int flag);
void	philo_exit(void);
void	init_argv(t_var *philo, int argc, char *argv[]);

#endif