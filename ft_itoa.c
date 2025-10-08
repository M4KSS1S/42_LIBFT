/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smaksiss <smaksiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 11:45:29 by smaksiss          #+#    #+#             */
/*   Updated: 2024/11/04 10:18:17 by smaksiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	length(int n)
{
	int	i;

	i = 0;
	if (n <= 0)
		i++;
	while (n)
	{
		i++;
		n /= 10;
	}
	return (i);
}

static char	*con(int n, char *str, int mines, int len)
{
	if (n == -2147483648)
	{
		str[0] = '-';
		str[1] = '2';
		n = 147483648;
	}
	else if (n == 0)
	{
		str[0] = '0';
		return (str);
	}
	else if (n < 0)
	{
		str[0] = '-';
		mines++;
		n = n * -1;
	}
	while (n) 
	{
		str[len--] = n % 10 + '0';
		n /= 10;
	}
	return (str);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		mines;
	int		len;

	len = length(n);
	mines = 0;
	str = malloc(len + 1);
	if (str == NULL)
		return (NULL);
	str[len--] = '\0';
	con((long)n, str, mines, len);
	return (str);
}
