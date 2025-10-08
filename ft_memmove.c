/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smaksiss <smaksiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 15:01:31 by smaksiss          #+#    #+#             */
/*   Updated: 2024/11/04 10:28:15 by smaksiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t		i;
	char		*dtr;
	const char	*str;

	if ((dst == src) || (dst == NULL && src == NULL && len > 0))
		return ((void *)src);
	dtr = (char *)dst;
	str = (const char *)src;
	if (dtr > str)
	{
		while (len--)
			dtr[len] = str[len];
	}
	else
	{
		i = 0;
		while (i < len)
		{
			dtr[i] = str[i];
			i++;
		}
	}
	return (dtr);
}
