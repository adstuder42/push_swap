/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   center.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adstuder <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/24 19:42:20 by adstuder          #+#    #+#             */
/*   Updated: 2019/03/29 10:24:46 by adstuder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_piles		acenter_up_sub(t_piles piles, int wr, int i, int min)
{
	if (i == 1)
		while ((piles.a[piles.a[0] - 1]) == min)
			piles = rra(piles, wr);
	else
	{
		if (i < ((piles.a[0] - 1) / 2))
			while (i > 1)
			{
				piles = ra(piles, wr);
				i--;
			}
		else
			while (i < (piles.a[0]))
			{
				piles = rra(piles, wr);
				i++;
			}
	}
	return (piles);
}

t_piles		acenter_up(t_piles piles, int wr)
{
	int i;
	int min;

	i = 1;
	min = aget_min(piles);
	if (piles.a[0] <= 2)
		return (piles);
	while (piles.a[i] != min)
		i++;
	piles = acenter_up_sub(piles, wr, i, min);
	return (piles);
}
