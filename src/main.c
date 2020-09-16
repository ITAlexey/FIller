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

int		main(void)
{
	t_game		data;
	char		*input;
	short		game_running;

	game_running = TRUE;
	input = NULL;
	if (get_next_line(STDOUT, &input) >= 0 && ft_strlen(input) > 10
		&& !ft_strncmp(input, "$$$ exec p", 10)
		&& (input[10] == '1' || input[10] == '2'))
	{
		data.me.id = input[10] == '1' ? 'O' : 'X';
		data.enemy.id = data.me.id == 'O' ? 'X' : 'O';
		ft_strdel(&input);
		while (game_running)
			game_running = parse_input(data);
	}
	else
		ft_strdel(&input);
	return (0);
}
