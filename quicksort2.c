/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adstuder <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/29 11:43:03 by adstuder          #+#    #+#             */
/*   Updated: 2019/04/02 18:36:14 by adstuder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_piles		move_back(t_piles piles)
{
	while (piles.mv > 0)
	{
		piles = rra(piles, 1);
		piles.mv--;
	}
	piles = pa(piles, 1);
	return (piles);
}

t_piles		sort_up_sub(t_piles piles, int nmin, int med, int gmed)
{
	int gmax;

	gmax = get_gmax(piles);
	if (piles.a[1] != nmin)
	{
		med = aget_next_med(piles, nmin);
		while (piles.a[1] != nmin && nmin > gmed && nmin <= gmax)
		{
			if (piles.a[1] <= med)
				piles = pb(piles, 1);
			else
			{
				piles = ra(piles, 1);
				piles.mv++;
			}
		}
		piles = pb(piles, 1);
		piles = move_back(piles);
	}
	piles = ra(piles, 1);
	piles = opti(piles, 1);
	piles.datatmp = med;
	return (piles);
}

t_piles		sort_up(t_piles piles, int gmed, int gmax, int wr)
{
	int med;
	int nmin;

	med = aget_min(piles);
	nmin = aget_next_up(piles, gmed);
	while (nmin > gmed)
	{
		while (piles.b[0] > 1)
		{
			med = bget_med(piles);
			piles = bsplit_lst(piles, med, wr);
		}
		while (isinb(piles, nmin) == 0 && nmin > gmed && nmin <= gmax)
		{
			piles = sort_up_sub(piles, nmin, med, gmed);
			if (nmin == gmax && nmin == 2147483647)
				return (piles);
			med = piles.datatmp;
			nmin = get_next_gmin(piles, nmin);
			if (nmin > gmax)
				return (piles);
		}
	}
	return (piles);
}

t_piles		sort_down_sub(t_piles piles, int nmin, int med, int gmed)
{
	if (piles.a[1] != nmin)
	{
		med = aget_next_med(piles, nmin);
		while (nmin <= gmed && piles.a[1] != nmin)
		{
			if (piles.a[1] <= med)
				piles = pb(piles, 1);
			else
			{
				piles = ra(piles, 1);
				piles.mv++;
			}
		}
		piles = pb(piles, 1);
		piles = move_back(piles);
	}
	piles = ra(piles, 1);
	piles = opti(piles, 1);
	piles.datatmp = med;
	return (piles);
}

t_piles		sort_down(t_piles piles, int gmed, int wr)
{
	int med;
	int nmin;
	int gmax;

	gmax = get_gmax(piles);
	med = aget_min(piles);
	nmin = aget_next_up(piles, -2147483648);
	while (nmin <= gmed)
	{
		while (isinb(piles, nmin) == 1)
		{
			med = bget_med(piles);
			piles = bsplit_lst(piles, med, wr);
		}
		while (nmin <= gmed && isinb(piles, nmin) == 0)
		{
			piles = sort_down_sub(piles, nmin, med, gmed);
			med = piles.datatmp;
			nmin = get_next_gmin(piles, nmin);
		}
	}
	return (piles);
}
