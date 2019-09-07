/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ab_get_min_max.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adstuder <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/29 12:07:31 by adstuder          #+#    #+#             */
/*   Updated: 2019/03/29 12:08:02 by adstuder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		aget_min(t_piles piles)
{
	int i;
	int min;

	i = 1;
	min = 2147483647;
	while (i < piles.a[0])
	{
		if (piles.a[i] < min)
			min = piles.a[i];
		i++;
	}
	return (min);
}

int		bget_min(t_piles piles)
{
	int i;
	int min;

	i = 1;
	min = 2147483647;
	while (i < piles.b[0])
	{
		if (piles.b[i] < min)
			min = piles.b[i];
		i++;
	}
	return (min);
}

int		aget_max(t_piles piles)
{
	int i;
	int max;

	i = 1;
	max = -2147483648;
	while (i < piles.a[0])
	{
		if (piles.a[i] > max)
			max = piles.a[i];
		i++;
	}
	return (max);
}

int		bget_max(t_piles piles)
{
	int i;
	int max;

	i = 1;
	max = -2147483648;
	while (i < piles.b[0])
	{
		if (piles.b[i] > max)
			max = piles.b[i];
		i++;
	}
	return (max);
}
