/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adstuder <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/29 13:05:24 by adstuder          #+#    #+#             */
/*   Updated: 2019/03/29 18:30:10 by adstuder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		check_argv(int argc, char **argv, int split)
{
	int i;
	int j;

	i = 1;
	j = 0;
	while (i < argc)
	{
		j = 0;
		while (argv[i - split][j] != '\0')
		{
			if (j == 0)
			{
				if (is_sign(argv[i - split][j]) == 0 &&
						is_number(argv[i - split][j]) == 0)
					return (1);
			}
			else if (is_number(argv[i - split][j]) == 0)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int		check_int(int argc, char **argv, int split)
{
	long long int	nb;
	int				i;

	nb = 0;
	i = 1;
	while (i < argc)
	{
		nb = ft_atolli(argv[i - split]);
		if (nb > 2147483647 || nb < -2147483648)
			return (1);
		i++;
	}
	return (0);
}

int		check_doublons(t_piles piles)
{
	int i;
	int j;

	i = 1;
	j = 1;
	while (i < piles.a[0])
	{
		j = 1;
		while (j < piles.a[0])
		{
			if (piles.a[j] == piles.a[i] && i != j)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int		check_invalid(t_piles piles, int argc, char **argv, int split)
{
	if (check_argv(argc, argv, split) == 1)
	{
		print_error();
		return (1);
	}
	if (check_int(argc, argv, split) == 1)
	{
		print_error();
		return (1);
	}
	if (check_doublons(piles) == 1)
	{
		print_error();
		return (1);
	}
	return (0);
}
