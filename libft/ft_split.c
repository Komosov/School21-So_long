/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhelena <lhelena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 10:48:39 by lhelena           #+#    #+#             */
/*   Updated: 2021/11/13 19:16:48 by lhelena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_split_free(char **arr)
{
	int	i;

	i = 0;
	while (arr[i] != NULL)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
	return (NULL);
}

int	ft_split_str_count(const char *str, char splitter)
{
	int	i;
	int	found;

	if (str[0] == '\0')
		return (0);
	i = 1;
	found = 0;
	if (str[0] != splitter)
		found++;
	while (str[i] != '\0')
	{
		if ((str[i - 1] == splitter) && (str[i] != splitter))
			found++;
		i++;
	}
	return (found);
}

int	ft_split_strlen(char const *str, char splitter, int pos)
{
	int	i;
	int	count;

	i = pos;
	count = 0;
	while ((str[i] != '\0') && (str[i] != splitter))
	{
		i++;
		count++;
	}
	return (count);
}

char	**ft_split(char const *s, char c)
{
	char	**res;
	int		i;
	int		j;

	if (!s)
		return (NULL);
	res = (char **)malloc(sizeof(char *) * (ft_split_str_count(s, c) + 1));
	if (!res)
		return (NULL);
	res[ft_split_str_count(s, c)] = NULL;
	i = 0;
	j = 0;
	while (j < ft_split_str_count(s, c))
	{
		while (s[i] == c)
			i++;
		res[j] = ft_substr(s, i, ft_split_strlen(s, c, i));
		if (!res[j])
			return (ft_split_free(res));
		res[j][ft_split_strlen(s, c, i)] = '\0';
		i = i + ft_split_strlen(s, c, i);
		j++;
	}
	return (res);
}
