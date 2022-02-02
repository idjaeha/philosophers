/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayi <jayi@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 19:30:20 by jayi              #+#    #+#             */
/*   Updated: 2022/02/02 23:13:42 by jayi             ###   ########.fr       */
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

int			init(t_var *philo, int argc, char *argv[]);
int			start(t_var *var);
void		*act(void *data);
void		release(t_var *var);
void		idle(time_t start, time_t target);
void		*check_die(void *data);
void		*check_must_eat(void *data);
time_t		get_mseconds(void);
void		print_message(char *message, int idx \
			, pthread_mutex_t *print, int is_end);
int			ft_atoi(const char *str);
void		ft_putstr_fd(char *str, int fd);
void		*ft_memset(void *byte_str, int ch, size_t len);
void		*ft_calloc(size_t count, size_t size);

#endif