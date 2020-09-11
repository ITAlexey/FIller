//
// Created by alexey on 04.09.2020.
//

#include "filler.h"

static void 	record_data(t_map *token, char *input, int offset)
{
	char	**tmp;
	int 	index;

	index = 0;
	tmp = ft_strsplit(input, ' ');
	token->height = ft_atoi(tmp[1]);
	token->width = ft_atoi(tmp[2]);
	token->size = token->height * token->width;
	ft_free2darray(tmp);
	ft_strdel(&input);
	if (offset)
	{
		get_next_line(STDOUT, &input)
		ft_strdel(&input);
	}
	token->map = (char **)ft_memalloc(sizeof(char*) * token->height);
	ISNOTNULL(token->map);
	while (get_next_line(STDOUT, &input) >= 0)
	{
		token->map[index] = ft_strdup(line + offset);
		ISNOTNULL(token->map[index++]);
		ft_strdel(&input);
	}
}


void 	parse_input(t_game data)
{
	char 	*line;
	int 	**heatmap;

	while (get_next_line(STDOUT, &line) >= 0 && line != NULL)
	{
		if (!ft_strncmp(line, "Plateau", 8))
		{
			record_data(&data.plateau, line, 4);
			record_player_positions(data.plateau, &data.me);
			record_player_positions(data.plateau, &data.enemy);
			heatmap = get_heatmap(data.plateau, data.me, data.enemy);
		}
		else if (!ft_strncmp(line, "Piece", 7))
		{
			record_data(&data.piece, line, 0);

		}
		ft_strdel(&line);
	}
}