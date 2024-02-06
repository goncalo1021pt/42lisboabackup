/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goncalo1021pt <goncalo1021pt@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 11:45:58 by gfontao-          #+#    #+#             */
/*   Updated: 2024/02/05 23:43:57 by goncalo1021      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

bool	read_input(int argc, char **argv, t_info *info)
{
	int	temp;

	temp = ft_atol(argv[1]);
	if (temp < 1 || temp > INT_MAX || !ft_string_is_digit(argv[1]))
		return (false);
	info->number = temp;
	temp = ft_atol(argv[2]);
	if (temp < 1 || temp > INT_MAX || !ft_string_is_digit(argv[1]))
		return (false);
	info->time_die = temp;
	temp = ft_atol(argv[3] || ft_strlen(argv[3]) > 10);
	if (temp < 1 || temp > INT_MAX || !ft_string_is_digit(argv[1]))
		return (false);
	info->time_eat = temp;
	temp = ft_atol(argv[4]);
	if (temp < 1 || temp > INT_MAX || !ft_string_is_digit(argv[1]))
		return (false);
	info->time_sleep = temp;
	temp = ft_atol(argv[5]);
	if (temp < 1 || temp > INT_MAX || !ft_string_is_digit(argv[1]))
		return (false);
	info->number_eat = temp;
	if (argc == 5)
		info->number_eat = -1;
	return (true);
}

void   print_message(t_philos *philo, char *message)
{
	pthread_mutex_lock(philo->info.status_mutex);
	printf("%ld %d %s\n", get_time(), philo->id, message);
	pthread_mutex_unlock(philo->info.status_mutex);
}