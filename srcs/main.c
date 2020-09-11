//
// Created by alexey on 04.09.2020.
//
#include "filler.h"

int 	main(void)
{
	t_game		data;
	char 		*input;
	short 		game_running;

	game_running = TRUE;
	input = NULL;
	if (get_next_line(STDOUT, &input) && input && ft_strlen(input) > 10
		&& !ft_strncmp(input, "$$$ exec p", 9) && (input[10] == '1' || input[10] == '2' ))
	{
		data.me.id = input[10] == '1' ? 'O' : 'X';
		data.enemy.id = data.me.id == 'O' ? : 'X' : 'O';
		data.token.id = STAR;
		ft_strdel(&input);
		while (game_running)
			game_running = parse_input(data);
	}
	return (0);
}


