/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_push_swap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adstuder <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/30 20:59:15 by adstuder          #+#    #+#             */
/*   Updated: 2019/04/02 20:07:43 by adstuder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_piles		call_algo(t_piles piles, int argc, char **tab, int split)
{
	if (acheck_sort_up(piles) == 1)
		return (acenter_up(piles, 1));
	if (piles.a[0] <= 4)
		piles = sort_small_lst(piles, 1);
	else if (piles.a[0] > 4 && piles.a[0] < 28)
		piles = find_opti(piles, argc, tab, split);
	else if (piles.a[0] >= 28)
		piles = quicksort(piles, 1);
	return (piles);
}

int			main(int argc, char **argv)
{
	t_piles piles;
	char	**tab;
	int		split;

	tab = NULL;
	split = 0;
	if (argc == 2)
	{
		if (!(tab = ft_strsplit(argv[1], ' ')))
			return (0);
		argc = count_lines(tab);
		split = 1;
	}
	else
		tab = argv;
	if (init_tab(&piles, argc) == 1)
		return (0);
	piles = fill_a(piles, argc, tab, split);
	if (argc > 1 && check_invalid(piles, argc, tab, split) == 0)
		piles = call_algo(piles, argc, tab, split);
	free_piles(piles.a, piles.b);
	split == 1 ? free_tab(tab) : 0;
	return (0);
}
