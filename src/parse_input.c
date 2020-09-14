//
// Created by alexey on 04.09.2020.
//

#include "filler.h"

static void 	record_data(t_map *map, char *input, int offset)
{
	int 	index;

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
	while (index < map->height && get_next_line(STDOUT, &input) > 0)
	{
		map->grid[index] = ft_strdup(input + offset);
		ISNOTNULL(map->grid[index++]);
		ft_strdel(&input);
	}
}


int 	parse_input(t_game data)
{
	char 	*line;

	while (get_next_line(STDOUT, &line) > 0)
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
			//return (place_token(data));
		}
		else
			ft_strdel(&line);
	}
	/*for (int i = 0; i < data.plateau.height; i++)
	{
		for (int j = 0; j < data.plateau.width; j++)
			printf("%3d", data.heatmap[i][j]);
		printf("\n");
	}*/
	ft_2dmemdel((void**)data.plateau.grid, data.plateau.height);
	ft_2dmemdel((void**)data.piece.grid, data.piece.height);
	ft_memdel((void**)&data.me.positions);
	ft_memdel((void**)&data.enemy.positions);
	ft_2dmemdel((void**)data.heatmap, data.plateau.height);
	ft_memdel((void**)&data.token.positions);
	return (0);
}