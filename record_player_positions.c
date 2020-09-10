//
// Created by alexey on 10.09.2020.
//

#include "filler.h"

static int	define_nbr_of_elements(t_map plateau, char player_id)
{
	t_point		d;
	int 		counter;

	counter = 0;
	d.y = 0;
	while (d.y < plateau.heigth)
	{
		d.x = 0;
		while (d.x < plateau.width)
		{
			if (ft_toupper(plateau.grid[d.y][d.x]) == player_id)
				counter++;
			d.x++;
		}
		d.y++;
	}
	return (counter);
}

void 	record_player_positions(t_map plateau, t_player *player)
{
	t_point		d;
	int 		index;

	player->size = define_nbr_of_elements(plateau, player.id);
	player->positions = (t_point*)ft_memalloc(sizeof(t_point) * player->size);
	ISNOTNULL(player->positions);
	index = 0;
	d.y = 0;
	while (d.y < plateau.height)
	{
		d.x = 0;
		while (d.x < plateau.width)
		{
			if (ft_toupper(plateau.grid[d.y][d.x]) == player->id)
				player->positions[index++] = d;
		}
		d.y++;
	}
}