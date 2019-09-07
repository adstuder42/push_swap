/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adstuder <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 14:08:25 by adstuder          #+#    #+#             */
/*   Updated: 2019/04/02 21:38:10 by adstuder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			check_tri(t_piles piles)
{
	int i;
	int min;

	i = 1;
	min = -2147483648;
	while (i < piles.a[0])
	{
		if (piles.a[i] < min)
			return (0);
		min = piles.a[i];
		i++;
	}
	if (piles.b[0] > 1)
		return (0);
	return (1);
}

t_piles		reset_piles(t_piles piles, int len, char **argv, int split)
{
	free(piles.a);
	free(piles.b);
	if (init_tab(&piles, len) == 1)
		return (piles);
	piles = fill_a(piles, len, argv, split);
	return (piles);
}

t_piles		find_opti(t_piles piles, int len, char **argv, int split)
{
	int sml;
	int ss;
	int ss2;

	sml = 0;
	ss = 0;
	ss2 = 0;
	piles = sort_medium_lst(piles, 1, 0);
	sml = piles.count;
	piles = reset_piles(piles, len, argv, split);
	piles = selective_sort(piles, 1, 0);
	ss = piles.count;
	piles = reset_piles(piles, len, argv, split);
	piles = selective_sort2(piles, 0);
	ss2 = piles.count;
	piles = reset_piles(piles, len, argv, split);
	if (sml <= ss && sml <= ss2)
		piles = sort_medium_lst(piles, 1, 1);
	else if (ss <= sml && ss <= ss2)
		piles = selective_sort(piles, 1, 1);
	else if (ss2 <= sml && ss2 <= ss)
		piles = selective_sort2(piles, 1);
	return (piles);
}

int			count_lines(char **tab)
{
	int i;

	i = 0;
	while (tab[i] != 0)
	{
		i++;
	}
	i++;
	return (i);
}
