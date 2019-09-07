/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adstuder <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/24 16:30:25 by adstuder          #+#    #+#             */
/*   Updated: 2019/04/02 18:09:53 by adstuder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			check_sort(t_piles piles)
{
	int i;
	int max;

	i = 2;
	max = 0;
	if (piles.b[0] != 1)
		return (0);
	if (piles.a[1] <= 2)
		return (1);
	max = piles.a[1];
	while (i < piles.a[0])
	{
		if (piles.a[i] < max)
			return (0);
		max = piles.a[i];
		i++;
	}
	return (1);
}

t_piles		op_cmp_sub(t_piles piles, char *line)
{
	if (ft_strcmp(line, "ra") == 0)
		piles = ra(piles, 0);
	if (ft_strcmp(line, "ra") == 0)
		piles.op = 1;
	if (ft_strcmp(line, "rb") == 0)
		piles = rb(piles, 0);
	if (ft_strcmp(line, "rb") == 0)
		piles.op = 1;
	if (ft_strcmp(line, "rr") == 0)
		piles = rr(piles, 0);
	if (ft_strcmp(line, "rr") == 0)
		piles.op = 1;
	if (ft_strcmp(line, "rra") == 0)
		piles = rra(piles, 0);
	if (ft_strcmp(line, "rra") == 0)
		piles.op = 1;
	if (ft_strcmp(line, "rrb") == 0)
		piles = rrb(piles, 0);
	if (ft_strcmp(line, "rrb") == 0)
		piles.op = 1;
	if (ft_strcmp(line, "rrr") == 0)
		piles = rrr(piles, 0);
	if (ft_strcmp(line, "rrr") == 0)
		piles.op = 1;
	return (piles);
}

t_piles		op_cmp(t_piles piles, char *line)
{
	if (ft_strcmp(line, "sa") == 0)
		piles = sa(piles, 0);
	if (ft_strcmp(line, "sa") == 0)
		piles.op = 1;
	if (ft_strcmp(line, "sb") == 0)
		piles = sb(piles, 0);
	if (ft_strcmp(line, "sb") == 0)
		piles.op = 1;
	if (ft_strcmp(line, "ss") == 0)
		piles = ss(piles, 0);
	if (ft_strcmp(line, "ss") == 0)
		piles.op = 1;
	if (ft_strcmp(line, "pa") == 0)
		piles = pa(piles, 0);
	if (ft_strcmp(line, "pa") == 0)
		piles.op = 1;
	if (ft_strcmp(line, "pb") == 0)
		piles = pb(piles, 0);
	if (ft_strcmp(line, "pb") == 0)
		piles.op = 1;
	return (piles);
}

t_piles		call_gnl(t_piles piles)
{
	char *line;

	line = NULL;
	while (get_next_line(0, &line) == 1)
	{
		piles.op = 0;
		piles = op_cmp(piles, line);
		piles = op_cmp_sub(piles, line);
		if (piles.op == 0)
		{
			print_error();
			free(line);
			return (piles);
		}
		free(line);
	}
	if (check_tri(piles) == 1)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	return (piles);
}

int			sub_main(int argc, char **argv, int split)
{
	t_piles piles;
	char	**tab;

	tab = NULL;
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
		piles = call_gnl(piles);
	split == 1 ? free_tab(tab) : 0;
	free_piles(piles.a, piles.b);
	return (0);
}
