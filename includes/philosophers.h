/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayi <jayi@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 19:30:20 by jayi              #+#    #+#             */
/*   Updated: 2022/01/27 14:53:44 by jayi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include "philo_define.h"
# include "philo_types.h"

# include <unistd.h>
# include <stdlib.h>
# include <sys/time.h>
# include <stdio.h>

int		ft_atoi(const char *str);
void	ft_putnbr_fd(int n, int fd);
void	ft_putstr_fd(char *str, int fd);
char	*ft_strchr(const char *str, int ch, char **ret);
char	*ft_substr(const char *str, unsigned int start, size_t len);
void	*ft_memset(void *byte_str, int ch, size_t len);
void	*ft_calloc(size_t count, size_t size);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t	ft_strlen(const char *str);
void	free_all(t_var *philo);
void	philo_error(char *msg, int flag);
void	philo_exit(void);
void	*act(void *data);
void	init(t_var *philo, int argc, char *argv[]);

#endif