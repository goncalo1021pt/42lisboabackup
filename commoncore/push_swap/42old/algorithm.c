/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfontao- <gfontao-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 19:49:20 by gfontao-          #+#    #+#             */
/*   Updated: 2023/10/20 13:04:13 by gfontao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

void	indexer(t_stack *stack)
{
	t_node	*temp;
	t_node	*temp2;
	int		ctd;

	temp = stack->head;
	temp2 = stack->head;
	while (temp)
	{
		ctd = 1;
		while (temp2)
		{
			if (temp2->nbr < temp->nbr)
				ctd++;
			temp2 = temp2->next;
		}
		temp->value = ctd;
		temp2 = stack->head;
		temp = temp->next;
	}
}

void	choose_moves(t_stack stack)
{
	t_next_elements	*big;
	t_next_elements	*small;

	total_cost(stack, big, small);
	if (big->cost < small->cost)
		small = big;
	if (head_cost(stack.head, small) > tail_cost(stack.tail, small))
	{
		while (stack.head->value != small->found)
	}
	
	
}