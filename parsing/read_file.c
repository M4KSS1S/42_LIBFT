/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smaksiss <smaksiss@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 11:21:29 by smaksiss          #+#    #+#             */
/*   Updated: 2025/10/30 13:02:33 by smaksiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

char	*ft_substr(char *s, int start, int len)
{
	char	*str;
	int	i;

	i = 0;
	if (s == NULL)
		return (NULL);
	if ((start >= ft_strlen(s)) || len == 0)
		return (ft_strdup(""));
	if (len > ft_strlen(s) - start)
		len = ft_strlen(s) - start;
	str = malloc(len + 1);
	if (str == NULL)
		return (NULL);
	while (i < len && s[i])
		str[i++] = s[start++];
	str[i] = '\0';
	return (str);
}

int	ft_atoi(char	*str)
{
	int		num;
	int					i;

	i = 0;
	num = 0;
	while (str[i] <= 32)
		i++;
    if (str[i] == '-')
        return (-1);
	if (str[i] == '+')
		i++;
	while (str[i] && ft_isdigit(str[i]) && num < 500)
		num = num * 10 + (str[i++] - '0');
    while (str[i] && str[i] <= 32)
        i++;
    if (num > 255 || num < 0)
        return (-1);
    if (str[i])
        return (-1);
	return (num);
}