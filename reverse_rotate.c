/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adstuder <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/17 18:35:50 by adstuder          #+#    #+#             */
/*   Updated: 2019/03/30 19:38:51 by adstuder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_piles		rra(t_piles piles, int wr)
{
	int tmp;
	int i;

	i = piles.a[0] - 1;
	tmp = piles.a[i];
	if (wr == 1)
		write(1, "rra\n", 4);
	if (piles.a[0] <= 2)
	{
		piles.count++;
		return (piles);
	}
	while (i >= 2)
	{
		piles.a[i] = piles.a[i - 1];
		i--;
	}
	piles.a[1] = tmp;
	piles.count++;
	return (piles);
}

t_piles		rrb(t_piles piles, int wr)
{
	int tmp;
	int i;

	i = piles.b[0] - 1;
	tmp = piles.b[i];
	if (wr == 1)
		write(1, "rrb\n", 4);
	if (piles.b[0] <= 2)
	{
		piles.count++;
		return (piles);
	}
	while (i >= 2)
	{
		piles.b[i] = piles.b[i - 1];
		i--;
	}
	piles.b[1] = tmp;
	piles.count++;
	return (piles);
}

t_piles		rrr(t_piles piles, int wr)
{
	if (wr == 1)
		write(1, "rrr\n", 4);
	piles = rra(piles, 0);
	piles = rrb(piles, 0);
	piles.count--;
	return (piles);
}
