/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayi <jayi@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 19:30:20 by jayi              #+#    #+#             */
/*   Updated: 2022/01/26 21:10:21 by jayi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include "philo_define.h"
# include "philo_types.h"

# include <unistd.h>
# include <stdlib.h>

int		ft_atoi(const char *str);
void	ft_putnbr_fd(int n, int fd);
void	ft_putstr_fd(char *str, int fd);
void	philo_error(char *msg, int flag);
void	philo_exit(void);
void	init(t_var *philo, int argc, char *argv[]);

#endif