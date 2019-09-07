/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adstuder <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/17 16:07:49 by adstuder          #+#    #+#             */
/*   Updated: 2019/03/31 12:13:13 by adstuder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_piles		pa(t_piles piles, int wr)
{
	int i;

	if (wr == 1)
		write(1, "pa\n", 3);
	piles.b[0] <= 1 ? piles.count++ : 0;
	if (piles.b[0] <= 1)
		return (piles);
	i = piles.a[0];
	while (i >= 2)
	{
		piles.a[i] = piles.a[i - 1];
		i--;
	}
	piles.a[1] = piles.b[1];
	piles.a[0]++;
	i = 1;
	while (i < piles.b[0] - 1)
	{
		piles.b[i] = piles.b[i + 1];
		i++;
	}
	piles.b[0]--;
	piles.count++;
	return (piles);
}

t_piles		pb(t_piles piles, int wr)
{
	int i;

	if (wr == 1)
		write(1, "pb\n", 3);
	piles.a[0] <= 1 ? piles.count++ : 0;
	if (piles.a[0] <= 1)
		return (piles);
	i = piles.b[0];
	while (i >= 2)
	{
		piles.b[i] = piles.b[i - 1];
		i--;
	}
	piles.b[1] = piles.a[1];
	piles.b[0]++;
	i = 1;
	while (i < piles.a[0] - 1)
	{
		piles.a[i] = piles.a[i + 1];
		i++;
	}
	piles.a[0]--;
	piles.count++;
	return (piles);
}
