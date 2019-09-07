/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adstuder <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/24 19:41:09 by adstuder          #+#    #+#             */
/*   Updated: 2019/03/29 10:26:15 by adstuder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		acheck_sort_up(t_piles piles)
{
	int i;
	int min;
	int loop;

	i = 1;
	loop = 0;
	min = -2147483648;
	if (piles.a[0] == 1)
		return (1);
	while (i < piles.a[0])
	{
		if (piles.a[i] < min)
		{
			if (loop == 1)
				return (0);
			loop = 1;
		}
		min = piles.a[i];
		i++;
	}
	if (loop == 1 && piles.a[piles.a[0] - 1] > piles.a[1])
		return (0);
	return (1);
}

int		bcheck_sort_down(t_piles piles)
{
	int i;
	int max;
	int loop;

	i = 1;
	loop = 0;
	max = 2147483647;
	if (piles.b[0] == 1)
		return (1);
	while (i < piles.b[0])
	{
		if (piles.b[i] > max)
		{
			if (loop == 1)
				return (0);
			loop = 1;
		}
		max = piles.b[i];
		i++;
	}
	if (loop == 1 && piles.b[piles.b[0] - 1] < piles.b[1])
		return (0);
	return (1);
}
