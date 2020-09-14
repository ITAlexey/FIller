//
// Created by alexey on 10.09.2020.
//

#include "filler.h"

static int		define_nbr_of_elements(t_map map, char id)
{
	t_point		d;
	int 		counter;

	counter = 0;
	d.y = 0;
	while (d.y < map.height)
	{
		d.x = 0;
		while (d.x < map.width)
		{
			if (ft_toupper(map.grid[d.y][d.x]) == id)
				counter++;
			d.x++;
		}
		d.y++;
	}
	return (counter);
}

static inline void		align_by_left_edge(t_point *node, t_point border)
{
	node->x -= border.x;
	node->y -= border.y;
}

void	record_token_positions(t_token *token, t_map peace)
{
	t_point		d;
	t_point		min;
	int 		index;

	token->cells = define_nbr_of_elements(peace, STAR);
	token->positions = (t_point*)ft_memalloc(sizeof(t_point) * token->cells);
	ISNOTNULL(token->positions);
	index = 0;
	min.x = peace.width;
	min.y = peace.height;
	d.y = 0;
	while (d.y < peace.height)
	{
		d.x = 0;
		while (d.x < peace.width)
		{
			if (peace.grid[d.y][d.x] == STAR)
			{
				token->positions[index++] = d;
				min.x = MIN(min.x, d.x);
				min.y = MIN(min.y, d.y);
			}
			d.x++;
		}
		d.y++;
	}
	d.y = 0;
	while (d.y < token->cells)
		align_by_left_edge(&token->positions[d.y++], min);
}

void 	record_player_positions(t_map plateau, t_player *player)
{
	t_point		d;
	int 		index;

	index = 0;
	player->size = define_nbr_of_elements(plateau, player->id);
	player->positions = (t_point*)ft_memalloc(sizeof(t_point) * player->size);
	ISNOTNULL(player->positions);
	d.y = 0;
	while (d.y < plateau.height)
	{
		d.x = 0;
		while (d.x < plateau.width)
		{
			if (ft_toupper(plateau.grid[d.y][d.x]) == player->id)
				player->positions[index++] = d;
			d.x++;
		}
		d.y++;
	}
}