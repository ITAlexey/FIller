//
// Created by alexey on 04.09.2020.
//

#include "filler.h"

static void 	record_data(t_map *map, char *input, int offset)
{
	char	**tmp;
	int 	index;

	index = 0;
	tmp = ft_strsplit(input, ' ');
	map->height = ft_atoi(tmp[1]);
	map->width = ft_atoi(tmp[2]);
	map->size = map->height * map->width;
	ft_free2darray((void**)tmp);
	ft_strdel(&input);
	if (offset)
	{
		get_next_line(STDOUT, &input);
		ft_strdel(&input);
	}
	map->grid = (char **)ft_memalloc(sizeof(char*) * map->height);
	ISNOTNULL(map->grid);
	while (get_next_line(STDOUT, &input) >= 0)
	{
		map->grid[index] = ft_strdup(input + offset);
		ISNOTNULL(map->grid[index++]);
		ft_strdel(&input);
	}
}


int 	parse_input(t_game data)
{
	char 	*line;

	while (get_next_line(STDOUT, &line) >= 0 && line != NULL)
	{
		if (!ft_strncmp(line, "Plateau", 8))
		{
			record_data(&data.plateau, line, 4);
			record_player_positions(data.plateau, &data.me);
			record_player_positions(data.plateau, &data.enemy);
			data.heatmap = get_heatmap(data.plateau, data.me, data.enemy);
		}
		else if (!ft_strncmp(line, "Piece", 7))
		{
			record_data(&data.piece, line, 0);
			record_token_positions(&data.token, data.piece);
			return (place_token(data));
		}
		ft_strdel(&line);
	}
	return (0);
}