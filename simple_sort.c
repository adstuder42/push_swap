/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adstuder <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/24 19:44:04 by adstuder          #+#    #+#             */
/*   Updated: 2019/03/31 13:34:59 by adstuder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_piles		sort_small_lst(t_piles piles, int wr)
{
	while (acheck_sort_up(piles) == 0)
	{
		if (piles.a[1] > piles.a[2])
			piles = sa(piles, wr);
		else
			piles = ra(piles, wr);
	}
	piles = acenter_up(piles, wr);
	return (piles);
}

t_piles		sort_medium_lst(t_piles piles, int i, int wr)
{
	int min;

	min = aget_min(piles);
	while (piles.a[0] > 4)
	{
		while (piles.a[1] == min && piles.a[0] > 4)
		{
			piles = pb(piles, wr);
			min = aget_min(piles);
		}
		i = 1;
		while (piles.a[i] != min)
			i++;
		if (i < ((piles.a[0] - 1) / 2))
			piles = ra(piles, wr);
		else
			piles = rra(piles, wr);
	}
	piles = sort_small_lst(piles, wr);
	while (piles.b[0] > 1)
		piles = pa(piles, wr);
	return (piles);
}

t_piles		selective_sort(t_piles piles, int i, int wr)
{
	int min;

	min = aget_min(piles);
	while (piles.a[0] > 4)
	{
		while (piles.a[0] > 3 && piles.a[1] == min)
		{
			piles = pb(piles, wr);
			min = aget_min(piles);
		}
		if (piles.a[0] >= 3 && piles.a[1] > piles.a[2])
			piles = sa(piles, wr);
		i = 1;
		while (piles.a[i] != min)
			i++;
		if (i < ((piles.a[0] - 1) / 2))
			piles = ra(piles, wr);
		else
			piles = rra(piles, wr);
	}
	piles = sort_small_lst(piles, wr);
	while (piles.b[0] > 1)
		piles = pa(piles, wr);
	return (piles);
}

t_piles		selective_sort2_sub(t_piles piles, int min, int wr)
{
	int i;

	i = 1;
	while (piles.a[i] != min)
		i++;
	if (i < ((piles.a[0] - 1) / 2))
		piles = ra(piles, wr);
	else
		piles = rra(piles, wr);
	return (piles);
}

t_piles		selective_sort2(t_piles piles, int wr)
{
	int min;

	min = aget_min(piles);
	if (acheck_sort_up(piles) == 1)
		return (acenter_up(piles, wr));
	while (piles.a[0] > 3)
	{
		if (piles.a[1] == min)
		{
			piles = pb(piles, wr);
			min = aget_min(piles);
		}
		else if (piles.a[1] > piles.a[2])
			piles = sa(piles, wr);
		else
			piles = selective_sort2_sub(piles, min, wr);
	}
	if (piles.a[1] > piles.a[2])
		piles = sa(piles, wr);
	while (piles.b[0] > 1)
		piles = pa(piles, wr);
	return (piles);
}
