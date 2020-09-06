//
// Created by alexey on 04.09.2020.
//

#include "libft.h"

static void 	define_initial_positions(t_game *data)
{
	t_point		d;

	d.y = 0;
	while (d.y < data->plateau.height)
	{
		d.x = 0;
		while (d.x < data->plateau.width)
		{
			if (data->plateau.grid[d.y][d.x] == data->me.id)
				data->me.start = d;
			else if (data->plateau.grid[d.y][d.x] == data->enemy.id)
				data->enemy.start = d;
			d.x += 1;
		}
		d.y += 1;
	}
	data->is_first_entry = 1;
}

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
	token->map = ft_memalloc(sizeof(char*) * token->height + 1);
	ISNOTNULL(token->map);
	token->map[token->height] = NULL;
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

	while (get_next_line(STDOUT, &line) >= 0 && line != NULL)
	{
		if (!ft_strncmp(line, "Plateau", 8))
		{
			record_data(&data.plateau, line, 4);
			if (!data.is_first_entry)
				define_initial_positions(&data);
		}
		else if (!ft_strncmp(line, "Piece", 7))
			record_data(&data.piece, line, 0);
		ft_strdel(&line);
	}
}