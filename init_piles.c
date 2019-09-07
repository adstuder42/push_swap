/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_piles.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adstuder <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 14:12:14 by adstuder          #+#    #+#             */
/*   Updated: 2019/04/02 18:15:16 by adstuder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			init_tab(t_piles *piles, int len)
{
	int i;

	i = len;
	if (!(piles->a = malloc(sizeof(int) * i)))
		return (1);
	if (!(piles->b = malloc(sizeof(int) * i)))
		return (1);
	i--;
	while (i >= 0)
	{
		piles->a[i] = 0;
		piles->b[i] = 0;
		i--;
	}
	piles->a[0] = len;
	piles->b[0] = 1;
	piles->op = 0;
	piles->count = 0;
	piles->datatmp = 0;
	piles->mv = 0;
	return (0);
}

t_piles		fill_a(t_piles piles, int argc, char **argv, int split)
{
	int i;

	i = argc;
	i--;
	while (i > 0)
	{
		piles.a[i] = ft_atoi(argv[i - split]);
		i--;
	}
	return (piles);
}
