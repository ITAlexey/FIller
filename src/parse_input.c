/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshala <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 18:05:27 by dshala            #+#    #+#             */
/*   Updated: 2019/09/16 20:17:43 by dshala           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int			define_nbr_of_elements(t_map map, char id)
{
	t_point		d;
	int			counter;

	counter = 0;
	d.y = 0;
	while (d.y < map.height)
	{
		d.x = 0;
		while (d.x < map.width)
		{
			if (ft_toupper(map.grid[d.y][d.x]) == id)
				counter++;
			d.x++;
		}
		d.y++;
	}
	return (counter);
}

static void	record_player_positions(t_map plateau, t_player *player)
{
	t_point		d;
	int			index;

	index = 0;
	player->size = define_nbr_of_elements(plateau, player->id);
	player->positions = (t_point*)ft_memalloc(sizeof(t_point) * player->size);
	ISNOTNULL(player->positions);
	d.y = 0;
	while (d.y < plateau.height)
	{
		d.x = 0;
		while (d.x < plateau.width)
		{
			if (ft_toupper(plateau.grid[d.y][d.x]) == player->id)
				player->positions[index++] = d;
			d.x++;
		}
		d.y++;
	}
}

static void	record_data(t_map *map, char *input, int offset)
{
	int	index;

	index = 0;
	map->height = ft_atoi(ft_strchr(input, ' '));
	map->width = ft_atoi(ft_strchr(ft_strchr(input, ' ') + 1, ' '));
	map->size = map->height * map->width;
	ft_strdel(&input);
	if (offset)
	{
		get_next_line(STDOUT, &input);
		ft_strdel(&input);
	}
	map->grid = (char **)ft_memalloc(sizeof(char*) * map->height);
	ISNOTNULL(map->grid);
	while (index < map->height && get_next_line(STDOUT, &input))
	{
		map->grid[index] = ft_strdup(input + offset);
		ISNOTNULL(map->grid[index++]);
		ft_strdel(&input);
	}
}

int			parse_input(t_game data)
{
	char	*line;

	while (get_next_line(STDOUT, &line))
	{
		if (!ft_strncmp(line, "Plateau", 7))
		{
			record_data(&data.plateau, line, 4);
			record_player_positions(data.plateau, &data.me);
			record_player_positions(data.plateau, &data.enemy);
			data.heatmap = get_heatmap(data.plateau, data.me, data.enemy);
		}
		else if (!ft_strncmp(line, "Piece", 5))
		{
			record_data(&data.piece, line, 0);
			record_token_positions(&data.token, data.piece);
			return (place_token(data));
		}
		else
			ft_strdel(&line);
	}
	return (0);
}
