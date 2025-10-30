/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smaksiss <smaksiss@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 09:56:25 by ael-majd          #+#    #+#             */
/*   Updated: 2025/10/30 11:36:41 by smaksiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE 
#  define BUFFER_SIZE 42
# endif

# ifndef OPEN_MAX 
#  define OPEN_MAX 10240
# endif

// # include "../../header.h"
# include <limits.h>
# include <stdlib.h>
# include <unistd.h>
# include "../../header.h"

char	*get_next_line(int fd);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strdup(const char *s);

#endif