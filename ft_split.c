/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smaksiss <smaksiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 19:10:29 by smaksiss          #+#    #+#             */
/*   Updated: 2024/11/04 10:26:15 by smaksiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_words(const char *s, char c)
{
	size_t	count;
	size_t	flag;
	size_t	i;

	i = 0;
	flag = 1;
	count = 0;
	while (s[i])
	{
		if (s[i] != c && flag)
		{
			count++;
			flag = 0;
		}
		else if (s[i] == c)
			flag = 1;
		i++;
	}
	return (count);
}

static size_t	ft_word_len(char const *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i] != c && s[i])
		i++;
	return (i);
}

static void	ft_free_str(char **ptr)
{
	size_t	k;

	k = 0;
	while (ptr[k])
		free(ptr[k++]);
}

static char	**ft_cpy(char const *s, char c, char **ptr)
{
	size_t	i;
	size_t	j;
	size_t	k;
	size_t	word_len;

	i = 0;
	j = 0;
	k = 0;
	word_len = ft_count_words(s, c);
	while (s[i] && k < word_len)
	{
		while (s[i] == c && s[i])
			i++;
		ptr[k] = malloc(ft_word_len(&s[i], c) + 1);
		if (!ptr[k])
			return (ft_free_str(ptr), NULL);
		j = 0;
		while (s[i] != c && s[i])
			ptr[k][j++] = s[i++];
		ptr[k++][j] = '\0';
		while (s[i] == c && s[i])
			i++;
	}
	ptr[k] = NULL;
	return (ptr);
}

char	**ft_split(char const *s, char c)
{
	char	**ptr;
	size_t	word;

	if (s == NULL)
		return (NULL);
	word = ft_count_words(s, c);
	ptr = malloc (sizeof(char *) * (ft_count_words(s, c) + 1));
	if (word == 0)
	{
		ptr[0] = NULL;
		return (ptr);
	}
	if (!ptr)
		return (NULL);
	ptr = ft_cpy(s, c, ptr);
	if (ptr == NULL)
		return (NULL);
	return (ptr);
}
