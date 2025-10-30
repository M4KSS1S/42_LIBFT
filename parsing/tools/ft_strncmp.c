/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smaksiss <smaksiss@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 13:40:27 by smaksiss          #+#    #+#             */
/*   Updated: 2025/10/30 11:49:17 by smaksiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header.h"

int	ft_strncmp(char *s1, char *s2, int n)
{
	int	i;

	i = 0;
    if (!s1 || !s2)
		return (-1);
	if (n == 0)
		return (0);
	while (i < n && s1[i] == s2[i] && s1[i] && s2[i])
		i++;
	if (i == n)
		return (0);
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

int	ft_strlen(char *str)
{
	int i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

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
