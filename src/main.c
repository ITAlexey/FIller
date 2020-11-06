/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshala <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 18:05:27 by dshala            #+#    #+#             */
/*   Updated: 2019/09/16 20:17:43 by dshala           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	free_data_game(t_game data)
{
	ft_2dmemdel((void**)data.heatmap, data.plateau.height);
	ft_2dmemdel((void**)data.plateau.grid, data.plateau.height);
	ft_2dmemdel((void**)data.piece.grid, data.piece.height);
	ft_memdel((void**)&data.me.positions);
	ft_memdel((void**)&data.enemy.positions);
	ft_memdel((void**)&data.token.positions);
	ft_memdel((void**)&data.result);
}

static short 	skip_header(char *input)
{
	short id;
	short counter;

	counter = 0;
	id = -1;
	while (counter < 9 && get_next_line(STDOUT, &input))
	{
		if (!ft_strncmp(input, "$$$ exec p", 10) && ft_strstr(input, "dshala"))
			id = input[10] == '1' ? 1 : 0;
		ft_strdel(&input);
		counter++;
	}
	return (id);
}

int		main(void)
{
	t_game		data;
	char		*input;
	short 		id;
	short		game_running;

	game_running = TRUE;
	input = NULL;
	if ((id = skip_header(input)) != -1)
	{
		data.me.id = id == 1 ? 'O' : 'X';
		data.enemy.id = data.me.id == 'O' ? 'X' : 'O';
		while (game_running)
			game_running = parse_input(data);
	}
	return (0);
}
