/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_aux.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adstuder <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/29 10:39:21 by adstuder          #+#    #+#             */
/*   Updated: 2019/03/29 12:14:30 by adstuder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_piles		opti(t_piles piles, int wr)
{
	if (piles.a[0] > 2 && piles.a[1] > piles.a[2] &&
			piles.b[0] > 2 && piles.b[1] < piles.b[2])
		piles = ss(piles, wr);
	else if (piles.a[0] > 2 && piles.a[1] > piles.a[2])
		piles = sa(piles, wr);
	else if (piles.b[0] > 2 && piles.b[1] < piles.b[2])
		piles = sb(piles, wr);
	return (piles);
}

int			isinb(t_piles piles, int nb)
{
	int i;

	i = 1;
	while (i < piles.b[0])
	{
		if (piles.b[i] == nb)
			return (1);
		i++;
	}
	return (0);
}
