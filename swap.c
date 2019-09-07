/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adstuder <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/16 19:51:56 by adstuder          #+#    #+#             */
/*   Updated: 2019/03/31 11:39:52 by adstuder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_piles	sa(t_piles piles, int wr)
{
	int tmp;

	tmp = 0;
	if (wr == 1)
		write(1, "sa\n", 3);
	if (piles.a[0] <= 2)
	{
		piles.count++;
		return (piles);
	}
	tmp = piles.a[1];
	piles.a[1] = piles.a[2];
	piles.a[2] = tmp;
	piles.count++;
	return (piles);
}

t_piles	sb(t_piles piles, int wr)
{
	int tmp;

	tmp = 0;
	if (wr == 1)
		write(1, "sb\n", 3);
	if (piles.b[0] <= 2)
	{
		piles.count++;
		return (piles);
	}
	tmp = piles.b[1];
	piles.b[1] = piles.b[2];
	piles.b[2] = tmp;
	piles.count++;
	return (piles);
}

t_piles	ss(t_piles piles, int wr)
{
	if (wr == 1)
		write(1, "ss\n", 3);
	piles = sa(piles, 0);
	piles = sb(piles, 0);
	piles.count--;
	return (piles);
}
