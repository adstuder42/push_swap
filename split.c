/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adstuder <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/24 19:36:16 by adstuder          #+#    #+#             */
/*   Updated: 2019/03/29 12:09:20 by adstuder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			aonly_above(t_piles piles, int med)
{
	int pos;

	pos = 1;
	if (piles.a[0] == 1)
		return (-1);
	while (pos < piles.a[0])
	{
		if (piles.a[pos] <= med)
			return (pos);
		pos++;
	}
	return (-1);
}

t_piles		asplit_lst(t_piles piles, int med, int wr)
{
	int i;
	int pos;

	i = 1;
	pos = 0;
	while ((pos = aonly_above(piles, med)) > 0)
	{
		if (piles.a[1] <= med)
			piles = pb(piles, wr);
		else
		{
			if (pos <= (piles.a[0] / 2))
				piles = ra(piles, wr);
			if (pos > (piles.a[0] / 2))
				piles = rra(piles, wr);
		}
	}
	return (piles);
}

int			bonly_above(t_piles piles, int med)
{
	int pos;

	pos = 1;
	if (piles.b[0] == 1)
		return (-1);
	while (pos < piles.b[0])
	{
		if (piles.b[pos] >= med)
			return (pos);
		pos++;
	}
	return (-1);
}

t_piles		bsplit_lst(t_piles piles, int med, int wr)
{
	int i;
	int pos;
	int gmin;

	i = 1;
	pos = 0;
	gmin = get_gmin(piles);
	while ((pos = bonly_above(piles, med)) > 0)
	{
		if (piles.b[1] >= med)
			piles = pa(piles, wr);
		else
		{
			if (pos <= (piles.b[0] / 2))
				piles = rb(piles, wr);
			if (pos > (piles.b[0] / 2))
				piles = rrb(piles, wr);
		}
	}
	return (piles);
}
