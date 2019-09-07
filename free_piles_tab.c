/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_piles_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adstuder <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/31 11:29:10 by adstuder          #+#    #+#             */
/*   Updated: 2019/03/31 11:31:15 by adstuder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		free_piles(int *pilea, int *pileb)
{
	free(pilea);
	free(pileb);
}

void		free_tab(char **tab)
{
	int i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}
