/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_med.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adstuder <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/21 12:13:03 by adstuder          #+#    #+#             */
/*   Updated: 2019/03/29 12:12:47 by adstuder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			aget_med(t_piles piles)
{
	int i;
	int min;
	int max;
	int loop;

	i = 1;
	min = aget_min(piles);
	max = aget_max(piles);
	loop = 0;
	while (loop < ((piles.a[0] - 2) / 2))
	{
		while (i < piles.a[0])
		{
			if (piles.a[i] > min && piles.a[i] < max)
				max = piles.a[i];
			i++;
		}
		loop++;
		min = max;
		max = 2147483647;
		i = 1;
	}
	return (min);
}

int			bget_med(t_piles piles)
{
	int i;
	int min;
	int max;
	int loop;

	i = 1;
	min = bget_min(piles);
	max = bget_max(piles);
	loop = 0;
	while (loop < ((piles.b[0] - 2) / 2))
	{
		while (i < piles.b[0])
		{
			if (piles.b[i] > min && piles.b[i] < max)
				max = piles.b[i];
			i++;
		}
		loop++;
		min = max;
		max = 2147483647;
		i = 1;
	}
	return (min);
}

int			aget_next_up(t_piles piles, int nb)
{
	int i;
	int max;

	i = 1;
	max = 2147483647;
	while (i < piles.a[0])
	{
		if (piles.a[i] > nb && piles.a[i] < max)
			max = piles.a[i];
		i++;
	}
	return (max);
}

int			next_up_loc(t_piles piles, int nmin)
{
	int i;

	i = 1;
	while (piles.a[i] != nmin && i < piles.a[0])
		i++;
	return (i);
}

int			aget_next_med(t_piles piles, int nmin)
{
	int loop;
	int loc;
	int min;
	int max;
	int i;

	max = 2147483647;
	min = nmin;
	loc = next_up_loc(piles, nmin);
	loop = loc / 2;
	i = 1;
	while (loop > 0)
	{
		i = 1;
		while (piles.a[i] != min && i < piles.a[0])
		{
			if (piles.a[i] > nmin && piles.a[i] < max)
				max = piles.a[i];
			i++;
		}
		loop--;
		loop > 0 ? nmin = max : 0;
		loop > 0 ? max = 2147483647 : 0;
	}
	return (max);
}
