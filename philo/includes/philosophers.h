/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayi <jayi@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 19:30:20 by jayi              #+#    #+#             */
/*   Updated: 2022/01/30 23:01:54 by jayi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include "philo_define.h"
# include "philo_types.h"

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/time.h>

int			ft_atoi(const char *str);
void		ft_putstr_fd(char *str, int fd);
void		*ft_memset(void *byte_str, int ch, size_t len);
void		*ft_calloc(size_t count, size_t size);
void		release(t_var *var);
void		print_message(time_t now, int status, int idx);
void		*act(void *data);
int			init(t_var *philo, int argc, char *argv[]);
time_t		get_mseconds(void);
void		*check_die(void *data);
void		*check_must_eat(void *data);
void		philo_sleep(time_t start, time_t target);

#endif