/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   table.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfontao- <gfontao-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 10:40:07 by goncalo1021       #+#    #+#             */
/*   Updated: 2024/03/12 14:58:37 by gfontao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

bool	table_init(t_table *table)
{
	table->sim_status_mutex = ft_calloc(1, sizeof(t_mutex));
	if (!table->sim_status_mutex)
		return (false);
	pthread_mutex_init(table->sim_status_mutex, NULL);
	table->print_mutex = ft_calloc(1, sizeof(t_mutex));
	if (!table->print_mutex)
		return (free(table->sim_status_mutex), false);
	pthread_mutex_init(table->print_mutex, NULL);
	table->sim_status = true;
	table->philo = NULL;
	return (true);
}

void	free_table(t_table *table)
{
	pthread_mutex_destroy(table->sim_status_mutex);
	pthread_mutex_destroy(table->print_mutex);
	free(table->sim_status_mutex);
	free(table->print_mutex);
}
