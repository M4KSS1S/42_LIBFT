/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smaksiss <smaksiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 09:26:51 by smaksiss          #+#    #+#             */
/*   Updated: 2024/11/05 11:00:21 by smaksiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t		i;
	char		*d;
	const char	*s;

	if ((dst == src) || (dst == NULL && src == NULL && n > 0))
		return ((void *)src);
	s = src;
	d = dst;
	i = 0;
	while (i < n)
		d[i++] = *(s++);
	return (d);
}
