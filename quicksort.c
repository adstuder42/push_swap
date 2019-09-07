/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adstuder <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/21 16:18:18 by adstuder          #+#    #+#             */
/*   Updated: 2019/04/02 18:35:51 by adstuder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_piles		quicksort_sub(t_piles piles, int med, int gmed, int id)
{
	int gmax;

	gmax = 0;
	gmax = get_gmax(piles);
	while (piles.b[0] > 1)
	{
		med = bget_med(piles);
		piles = bsplit_lst(piles, med, 1);
	}
	if (id == 0)
		piles = sort_down(piles, gmed, 1);
	if (id == 1)
		piles = sort_up(piles, gmed, gmax, 1);
	return (piles);
}

t_piles		quicksort(t_piles piles, int wr)
{
	int med;
	int gmed;
	int gmin;
	int i;

	i = 0;
	gmed = aget_med(piles);
	gmin = get_gmin(piles);
	med = gmed;
	piles = asplit_lst(piles, med, wr);
	piles = quicksort_sub(piles, med, gmed, 0);
	med = aget_next_med(piles, gmin);
	while (piles.a[1] != gmin && isinb(piles, gmin) == 0)
	{
		if (piles.a[1] < med)
			piles = pb(piles, wr);
		else
			piles = ra(piles, wr);
	}
	while (piles.a[piles.a[0] - 1] != gmed)
		piles = rra(piles, wr);
	piles = quicksort_sub(piles, med, gmed, 1);
	while (piles.b[0] > 1)
		piles = pa(piles, wr);
	return (piles);
}
