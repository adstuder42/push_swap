/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_min_max.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adstuder <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/29 10:36:53 by adstuder          #+#    #+#             */
/*   Updated: 2019/03/29 10:49:55 by adstuder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		get_gmax(t_piles piles)
{
	int gmax;
	int i;

	gmax = -2147483648;
	i = 1;
	while (i < piles.a[0])
	{
		if (piles.a[i] > gmax)
			gmax = piles.a[i];
		i++;
	}
	i = 1;
	while (i < piles.b[0])
	{
		if (piles.b[i] > gmax)
			gmax = piles.b[i];
		i++;
	}
	return (gmax);
}

int		get_gmin(t_piles piles)
{
	int gmin;
	int i;

	gmin = 2147483647;
	i = 1;
	while (i < piles.a[0])
	{
		if (piles.a[i] < gmin)
			gmin = piles.a[i];
		i++;
	}
	i = 1;
	while (i < piles.b[0])
	{
		if (piles.b[i] < gmin)
			gmin = piles.b[i];
		i++;
	}
	return (gmin);
}

int		get_next_gmin(t_piles piles, int min)
{
	int nmin;
	int i;

	nmin = 2147483647;
	i = 1;
	while (i < piles.a[0])
	{
		if (piles.a[i] > min && piles.a[i] < nmin)
			nmin = piles.a[i];
		i++;
	}
	i = 1;
	while (i < piles.b[0])
	{
		if (piles.b[i] > min && piles.b[i] < nmin)
			nmin = piles.b[i];
		i++;
	}
	return (nmin);
}
