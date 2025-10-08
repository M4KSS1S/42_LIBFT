/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smaksiss <smaksiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 11:25:12 by smaksiss          #+#    #+#             */
/*   Updated: 2024/11/05 09:57:25 by smaksiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	dlen;
	size_t	slen;

	slen = ft_strlen(src);
	if (dst == NULL && dstsize == 0)
		return (slen);
	dlen = ft_strlen(dst);
	i = 0;
	if (dstsize == 0 || dstsize <= dlen)
		return (dstsize + slen);
	while (i < dstsize - dlen - 1 && *src)
		dst[dlen + i++] = *src++;
	dst[dlen + i] = '\0';
	return (dlen + slen);
}
