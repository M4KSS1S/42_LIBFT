/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smaksiss <smaksiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 18:34:42 by smaksiss          #+#    #+#             */
/*   Updated: 2024/11/01 12:03:32 by smaksiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_help(char const s1, char const *set, size_t k)
{
	while (set[k])
	{
		if (set[k] == s1)
			return (1);
		k++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;
	size_t	k;
	char	*str;

	i = 0;
	k = 0;
	if (s1 == NULL || set == NULL)
		return (NULL);
	if (ft_strlen(s1) == 0)
	{
		str = malloc(1);
		if (!str)
			return (NULL);
		return (str[0] = '\0', str);
	}
	j = ft_strlen(s1) - 1;
	while (s1[i] && ft_help(s1[i], set, k))
		i++;
	while (i < j && ft_help(s1[j], set, k))
		j--;
	str = ft_substr(s1, i, j - i + 1);
	if (str == NULL)
		return (NULL);
	return (str);
}
