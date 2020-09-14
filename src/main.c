//
// Created by alexey on 04.09.2020.
//
#include "filler.h"

void 	free_data_game(t_game data)
{
	ft_2dmemdel((void**)data.heatmap, data.plateau.height);
	ft_2dmemdel((void**)data.plateau.grid, data.plateau.height);
	ft_2dmemdel((void**)data.piece.grid, data.piece.height);
	ft_memdel((void**)&data.me.positions);
	ft_memdel((void**)&data.enemy.positions);
	ft_memdel((void**)&data.token.positions);
}

int 	main(void)
{
	t_game		data;
	char 		*input;
	short 		game_running;

	game_running = TRUE;
	input = NULL;
	open("res.txt", O_RDONLY);
	while (get_next_line(STDOUT, &input) >= 0)
	{
		if (ft_strlen(input) > 10 && !ft_strncmp(input, "$$$ exec p", 10)
			&& (input[10] == '1' || input[10] == '2'))
		{
			data.me.id = input[10] == '1' ? 'O' : 'X';
			data.enemy.id = data.me.id == 'O' ? 'X' : 'O';
			ft_strdel(&input);
			while (game_running)
				game_running = parse_input(data);
			break ;
		}
		else
			ft_strdel(&input);
	}
	close(3);
	return (0);
}


