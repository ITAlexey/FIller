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

	open("test2.txt", O_RDONLY);
	game_running = TRUE;
	input = NULL;
	if (get_next_line(STDOUT, &input) && input && ft_strlen(input) > 10
		&& !ft_strncmp(input, "$$$ exec p", 9) && (input[10] == '1' || input[10] == '2' ))
	{
		data.me.id = input[10] == '1' ? 'O' : 'X';
		data.enemy.id = data.me.id == 'O' ? 'X' : 'O';
		printf("%c\n", data.me.id);
		ft_strdel(&input);
		while (game_running)
			game_running = parse_input(data);
	}
	close(STDOUT);
	return (0);
}

