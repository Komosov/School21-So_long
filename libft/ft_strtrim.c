/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhelena <lhelena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 20:20:37 by lhelena           #+#    #+#             */
/*   Updated: 2021/11/13 19:17:49 by lhelena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strtrim_set_check(char symbol, char const *sub_set)
{
	char	*flex_sub_set;
	int		len;

	flex_sub_set = (char *)sub_set;
	len = ft_strlen(flex_sub_set) - 1;
	while (len >= 0)
	{
		if (symbol == flex_sub_set[len])
			return (1);
		len--;
	}
	return (0);
}

int	ft_strtrim_start_pos(char const *sub_s1, char const *sub_set)
{
	char	*flex_sub_s1;
	char	*flex_sub_set;
	int		len;
	int		i;

	flex_sub_s1 = (char *)sub_s1;
	flex_sub_set = (char *)sub_set;
	len = ft_strlen(flex_sub_s1);
	i = 0;
	while (i < len)
	{
		if (ft_strtrim_set_check(flex_sub_s1[i], flex_sub_set) == 0)
		{
			return (i);
		}
		i++;
	}
	return (-1);
}

int	ft_strtrim_end_pos(char const *sub_s1, char const *sub_set)
{
	char	*flex_sub_s1;
	char	*flex_sub_set;
	int		len;

	flex_sub_s1 = (char *)sub_s1;
	flex_sub_set = (char *)sub_set;
	len = ft_strlen(flex_sub_s1);
	while (len > 0)
	{
		len--;
		if (ft_strtrim_set_check(flex_sub_s1[len], flex_sub_set) == 0)
		{
			return (len);
		}
	}
	return (-1);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		j;
	char	*ptr;

	if (!s1 || !set)
		return (NULL);
	i = ft_strtrim_start_pos(s1, set);
	ptr = (char *)malloc(sizeof(char)
			* (ft_strtrim_end_pos(s1, set) + 1 - i + 1));
	if (!ptr)
		return (NULL);
	j = 0;
	while ((i <= ft_strtrim_end_pos(s1, set)) && (i >= 0))
	{
		ptr[j] = s1[i];
		j++;
		i++;
	}
	ptr[j] = '\0';
	return (ptr);
}
