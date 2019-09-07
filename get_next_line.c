/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adstuder <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/02 21:03:23 by adstuder          #+#    #+#             */
/*   Updated: 2019/04/01 16:09:32 by adstuder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*next_line(char *s)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	while ((s) && (s[i] != '\n') && (s[i] != EOF) && (s[i] != '\0'))
		i++;
	j = i;
	if (!(str = (char*)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	str[i] = '\0';
	i--;
	while (i >= 0)
	{
		str[i] = s[i];
		i--;
	}
	return (str);
}

char	*sub_concat(char *s1, char *s2, int k, int len)
{
	int		i;
	int		j;
	char	*str;

	if (!(str = (char*)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	str[len] = '\0';
	i = 0;
	j = 0;
	if (s1 != NULL)
		while (s1[i] != '\0')
		{
			str[i] = s1[i];
			i++;
		}
	if (s2 != NULL)
		while (s2[j + k] != '\0')
		{
			str[i + j] = s2[j + k];
			j++;
		}
	str[i + j] = '\0';
	return (str);
}

char	*concat(char *s1, char *s2, int k, int l)
{
	int		len;
	char	*str;

	str = NULL;
	if ((s1) && (!s2))
		len = ft_strlen(s1);
	else if ((!s1) && (s2))
		len = ft_strlen(s2);
	else if ((!s1) && (!s2))
		len = 0;
	else
		len = ft_strlen(s1) + ft_strlen(s2) - k;
	len < 0 ? len = 0 : 0;
	if (len == 0)
	{
		l == 1 ? free(s1) : free(s2);
		return (str);
	}
	str = sub_concat(s1, s2, k, len);
	l == 1 ? free(s1) : free(s2);
	return (str);
}

int		sub_gnl(int i, char **line, char **str)
{
	int j;

	if (i < 0)
		return (-1);
	if ((*str) && ft_strlen(*str) > 0)
	{
		*line = next_line(*str);
		j = 0;
		while (str[0][j] != '\0' && str[0][j] != '\n')
			j++;
		*str = concat("", *str, j + 1, 2);
		return (1);
	}
	return (0);
}

int		get_next_line(const int fd, char **line)
{
	int				i;
	int				j;
	char			buf[BUFF_SIZE + 1];
	static char		*str = NULL;

	if (fd < 0)
		return (-1);
	j = 0;
	while ((i = read(fd, buf, BUFF_SIZE)) > 0)
	{
		j = j + i;
		buf[i] = '\0';
		str = concat(str, buf, 0, 1);
		i = -1;
		while (++i < j)
			if ((str) && (str[i] == '\n' || str[i] == '\0'))
			{
				*line = next_line(str);
				str = concat("", str, i + 1, 2);
				return (1);
			}
	}
	return (sub_gnl(i, line, &str));
}
