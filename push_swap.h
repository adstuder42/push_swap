/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adstuder <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/16 17:41:10 by adstuder          #+#    #+#             */
/*   Updated: 2019/04/02 18:37:03 by adstuder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# define BUFF_SIZE 10

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct		s_piles
{
	int	*a;
	int *b;
	int datatmp;
	int mv;
	int op;
	int count;

}					t_piles;

void				print_tab(int *tab);
int					ft_atoi(const char *str);
long long int		ft_atolli(const char *str);
t_piles				sa(t_piles piles, int wr);
t_piles				sb(t_piles piles, int wr);
t_piles				ss(t_piles piles, int wr);
t_piles				pa(t_piles piles, int wr);
t_piles				pb(t_piles piles, int wr);
t_piles				ra(t_piles piles, int wr);
t_piles				rb(t_piles piles, int wr);
t_piles				rr(t_piles piles, int wr);
t_piles				rra(t_piles piles, int wr);
t_piles				rrb(t_piles piles, int wr);
t_piles				rrr(t_piles piles, int wr);
t_piles				fill_a(t_piles piles, int argc, char **argv, int split);
int					init_tab(t_piles *piles, int len);
t_piles				call_tri_rapide(t_piles piles);
t_piles				asort_up(t_piles piles);
t_piles				aput_top(t_piles piles, int i);
int					acheck_sort_up(t_piles piles);
int					bcheck_sort_down(t_piles piles);
int					acheck_sort_down(t_piles piles);
t_piles				bsort_piles_double(t_piles piles);
t_piles				asort_down(t_piles piles, int wr);
int					aget_med(t_piles piles);
int					aget_min(t_piles piles);
int					bget_min(t_piles piles);
int					aget_max(t_piles piles);
int					get_gmax(t_piles piles);
int					bget_max(t_piles piles);
t_piles				bsort_down(t_piles piles);
t_piles				acenter_up(t_piles piles, int wr);
t_piles				selective_sort(t_piles piles, int i, int wr);
t_piles				selective_sort2(t_piles piles, int wr);
t_piles				asplit_lst(t_piles piles, int med, int wr);
t_piles				bsplit_lst(t_piles piles, int med, int wr);
t_piles				quicksort(t_piles piles, int wr);
t_piles				bsort_down_combi(t_piles piles);
t_piles				bcenter_down(t_piles piles);
t_piles				acenter_down(t_piles piles);
t_piles				absort(t_piles piles);
t_piles				opti(t_piles piles, int wr);
int					bget_med(t_piles piles);
int					aget_next_up(t_piles piles, int nb);
int					aget_next_med(t_piles piles, int nmin);
int					aget_next_down(t_piles piles, int nb);
int					bget_next_down(t_piles piles, int nb);
t_piles				sort_btoa(t_piles piles, int nmin);
t_piles				div_a(t_piles piles, int nmin, int med);
int					isinb(t_piles piles, int min);
int					get_next_gmin(t_piles piles, int min);
int					get_gmin(t_piles piles);
t_piles				simple_sort(t_piles piles);
int					get_gmed(t_piles piles);
t_piles				sort_small_lst(t_piles piles, int wr);
t_piles				sort_medium_lst(t_piles piles, int i, int wr);
int					ab_check_sort(t_piles piles);
t_piles				sort_down(t_piles piles, int gmed, int wr);
t_piles				sort_up(t_piles piles, int gmed, int gmax, int wr);
int					check_invalid(t_piles piles, int argc, char **argv,
					int split);
int					print_error();
int					is_sign(char c);
int					is_number(char c);
char				**ft_strsplit(char const *s, char c);
int					count_lines(char **tab);
void				free_piles(int *pilea, int *pileb);
void				free_tab(char **tab);
t_piles				find_opti(t_piles piles, int len, char **argv, int split);
int					get_next_line(const int fd, char **line);
int					check_sort(t_piles piles);
int					ft_strcmp(const char *s1, const char *s2);
int					check_tri(t_piles piles);
size_t				ft_strlen(const char *str);
int					sub_main(int argc, char **argv, int split);
char				*ft_strdup(const char *s1);

#endif
