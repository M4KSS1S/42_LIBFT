/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smaksiss <smaksiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 10:07:31 by smaksiss          #+#    #+#             */
/*   Updated: 2024/11/04 10:37:22 by smaksiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*str;
	size_t	i;

	i = size * count;
	if (count == 0 || size == 0)
		return (malloc(0));
	if (size > i / count)
		return (NULL);
	str = malloc(size * count);
	if (str == NULL)
		return (NULL);
	ft_memset(str, 0, count * size);
	return (str);
}
