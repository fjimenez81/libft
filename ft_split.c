/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjimenez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 19:36:04 by fjimenez          #+#    #+#             */
/*   Updated: 2021/06/02 10:29:53 by fjimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static	int	ft_contador(char const *str, char c)
{
	int		word_len;
	size_t	cont;

	word_len = 0;
	cont = 0;
	while (*str)
	{
		if (!word_len && *str != c)
			cont++;
		if (*str == c)
			word_len = 0;
		else
			word_len = 1;
		str++;
	}
	return (cont);
}

static	int	ft_word_len(char const *str, char c)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (str[i] == c)
		i++;
	while (str[i] != c && str[i] != '\0')
	{
		i++;
		len++;
	}
	return (len);
}

char	**ft_split(const char *str, char c)
{
	int		i;
	int		j;
	int		k;
	char	**s;

	s = (char **)malloc(sizeof(*s) * (ft_contador(str, c) + 1));
	if (!str || !s)
		return (NULL);
	i = -1;
	j = 0;
	while (++i < ft_contador(str, c))
	{
		k = 0;
		s[i] = ft_calloc(ft_word_len(&str[j], c) + 1, 1);
		if (!s[i])
			s[i] = NULL;
		while (str[j] == c)
			j++;
		while (str[j] != c && str[j])
			s[i][k++] = str[j++];
		s[i][k] = '\0';
	}
	s[i] = 0;
	return (s);
}
