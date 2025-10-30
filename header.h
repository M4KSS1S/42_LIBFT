#ifndef     HEADER_H
#define     HEADER_H

# ifndef OPEN_MAX 
#  define OPEN_MAX 10240
# endif

# include <unistd.h>
# include <stdio.h>
# include <math.h>
# include <fcntl.h>
# include <stdlib.h>
# ifndef GET_NEXT_LINE_H
# include "parsing/gnl/get_next_line.h"
# endif

// Main structure to hold all parsed values
typedef struct s_cub {
	char		*filename;
	int 		res_x;
	int			res_y;
	int			textures_count;
	int			colors_count;
	char		*no_texture;
	char		*so_texture;
	char		*we_texture;
	char		*ea_texture;
	char		*sprite_texture;
	int			floor_color[3];
	int			ceiling_color[3];
	char		**map_head;
	int			map_height;
	int			map_width;
 
} t_cub;

int	ft_isdigit(int c);
int	ft_atoi(char	*str);
char	*ft_substr(char *s, int start, int len);
int	ft_strlen(char *str);
char	**ft_split(char const *s, char c);
int	ft_strncmp(char *s1, char *s2, int n);

#endif
