/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adstuder <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/17 18:22:50 by adstuder          #+#    #+#             */
/*   Updated: 2019/03/30 19:36:02 by adstuder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_piles		ra(t_piles piles, int wr)
{
	int tmp;
	int i;

	tmp = piles.a[1];
	i = 1;
	if (wr == 1)
		write(1, "ra\n", 3);
	if (piles.a[0] <= 2)
	{
		piles.count++;
		return (piles);
	}
	while (i <= piles.a[0] - 2)
	{
		piles.a[i] = piles.a[i + 1];
		i++;
	}
	piles.a[i] = tmp;
	piles.count++;
	return (piles);
}

t_piles		rb(t_piles piles, int wr)
{
	int tmp;
	int i;

	tmp = piles.b[1];
	i = 1;
	if (wr == 1)
		write(1, "rb\n", 3);
	if (piles.b[0] <= 2)
	{
		piles.count++;
		return (piles);
	}
	while (i <= piles.b[0] - 2)
	{
		piles.b[i] = piles.b[i + 1];
		i++;
	}
	piles.b[i] = tmp;
	piles.count++;
	return (piles);
}

t_piles		rr(t_piles piles, int wr)
{
	if (wr == 1)
		write(1, "rr\n", 3);
	piles = ra(piles, 0);
	piles = rb(piles, 0);
	piles.count--;
	return (piles);
}
