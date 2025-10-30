/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smaksiss <smaksiss@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 13:33:17 by smaksiss          #+#    #+#             */
/*   Updated: 2025/10/30 12:48:20 by smaksiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"


int	set_colors(t_cub *cub, char *line, int type)
{
	int	i;
	char **str;

	i = 0;
	if (cub->colors_count == 2)
		return (0);
	while (line[i] && !ft_isdigit(line[i]) && i < 3)
		i++;
	str = ft_split(line, ',');
	cub->colors_count++;
	if (!line[i] ||(line[i] != ',' && !ft_isdigit(line[i])))
		return (-1);
	for (int i = 0; str[i]; i++)
	{
		if (ft_atoi(str[i]) == -1)
			return (-1);
		if (type == 'F')
			cub->floor_color[i] = ft_atoi(str[i]);
		if (type == 'C')
			cub->ceiling_color[i] = ft_atoi(str[i]);
	}
	return (1);
}

void	ft_clean(t_cub *cub)
{
	if (cub->ea_texture)
		free(cub->ea_texture);
	if (cub->we_texture)
		free(cub->we_texture);
	if (cub->so_texture)
		free(cub->so_texture);
	if (cub->no_texture)
		free(cub->no_texture);
	if (cub)
		free(cub);
}

void	texture_file_names(char *line, t_cub *cub)
{
	int	i;

	i = 0;
	while (line[i] == ' ')
		i++;
	if (line[i] && line[i + 1] && line[i + 2])
		i += 2;
	while (line[i] && line[i] == ' ')
		i++;
	if (!ft_strncmp(line, "NO ",3) && !cub->no_texture)
	{
		cub->no_texture = ft_strdup(line + i);
		cub->textures_count++;
	}
	if (!ft_strncmp(line, "SO ",3) && !cub->so_texture)
	{
		cub->so_texture = ft_strdup(line + i);
		cub->textures_count++;
	}
	if (!ft_strncmp(line, "WE ",3) && !cub->we_texture)
	{
		cub->we_texture = ft_strdup(line + i);
		cub->textures_count++;
	}
	if (!ft_strncmp(line, "EA ",3) && !cub->ea_texture)
	{
		cub->ea_texture = ft_strdup(line + i);
		cub->textures_count++;
	}
}

int	colors(t_cub *cub, char *line)
{
	int	i = 0;
	int	type;

	i = 0;
	if (cub->colors_count == 2)
		return (0);
	while (line[i] && line[i] == ' ')
		i++;
	if (line[i] && line[i + 1] &&(!ft_strncmp(line + i, "F ", 1) || !ft_strncmp(line + i, "C ", 1)))
	{
		type = line[i];
		i += 1;
	}
	while (line[i] && line[i] == ' ')
		i++;
	if (set_colors(cub, line + i, type) == -1)
		return (-1);
	return (1);
}

int	texture_path_check(t_cub *cub, char *line)
{
	int	i;

	i = 0;
	if (cub->textures_count == 4)
		return (0);
	while (line[i] && line[i] <= 32)
		i++;
	if (!line[i])
		return (1);
	if (line[i] && (line[i] != 'N' && line[i] != 'S' && line[i] != 'W' && line[i] != 'E'))
		return (-1);
	if (!ft_strncmp(line, "WE ",3) || !ft_strncmp(line, "EA ",3)
			|| !ft_strncmp(line, "SO ", 3) || !ft_strncmp(line, "NO ", 3))
		texture_file_names(line, cub);
	return (1);
}

void	initial_cub(t_cub **cub, char *filename)
{
	(*cub)->filename = filename;
	(*cub)->res_x = -1;
	(*cub)->res_y = -1;
	(*cub)->colors_count = 0;
	(*cub)->textures_count = 0;
	(*cub)->no_texture = NULL;
	(*cub)->so_texture = NULL;
	(*cub)->we_texture = NULL;
	(*cub)->ea_texture = NULL;
	(*cub)->sprite_texture = NULL;
	(*cub)->floor_color[0] = -1;
	(*cub)->ceiling_color[0] = -1;
	(*cub)->map_head = NULL;
	(*cub)->map_height = -1;
	(*cub)->map_width = -1;
}

int read_file_content(t_cub *cub)
{
	char    *line;
	int     fd;

	fd = open(cub->filename, O_RDWR);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		if (cub->textures_count == 4 && colors(cub,line) == -1)
			return (printf("Error\nColor errors\n"), free(line), -1);
		if (cub->textures_count < 4 && texture_path_check(cub, line) == -1)
			return (printf("Error\n"), free(line), -1);
		// if (color_
		// free(line);
		// line = NULL;
	}
	return (0);
}

int valid_params(char *str)
{
	int i;

	i = ft_strlen(str);
	if (i > 4 && !ft_strncmp(&str[i - 4], ".cub", 5))
		return (1);
	return (0);
}

int main(int ac, char **ag)
{
	t_cub *cub;
	
	if (ac != 2 || !valid_params(ag[1]))
		return (printf("Error\n"), 1);
	cub = malloc(sizeof(t_cub));
	initial_cub(&cub, ag[1]);
	if (read_file_content(cub) == -1)
		return ft_clean(cub), 1; // cleanup function
	printf("%d\n",cub->floor_color[0]);
	printf("%d\n",cub->floor_color[1]);
	printf("%d\n",cub->floor_color[2]);
	ft_clean(cub);
}