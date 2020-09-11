//
// Created by alexey on 10.09.2020.
//

#include "filler.h"

int		define_nbr_of_elements(t_map map, char id)
{
	t_point		d;
	int 		counter;

	counter = 0;
	d.y = 0;
	while (d.y < map.heigth)
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

static void		align_by_left_edge(t_point *node, t_point border)
{
	while (border.y)
	{
		node->y--;
		border.y--;
	}
	while (border.x)
	{
		node->x--;
		border.x--;
	}
}

void	record_token_positions(t_map peace, t_token *token)
{
	t_point		d;

	token->size = define_nbr_of_elements(peace, token->id);
	token->positions = (t_point*)ft_memalloc(sizeof(t_point) * token->size);
	ISNOTNULL(token->positions);
	token->min.x = peace.width;
	token->min.y = peace.height;
	d.y = 0;
	while (d.y < peace.height)
	{
		d.x = 0;
		while (d.x < peace.width)
		{
			if (peace.gird[d.y][d.x] == token->id)
			{
				token->positions[d.y] = d;
				token->min.x = MIN(min.x, d.x);
				token->min.y = MIN(min.y, d.y);
			}
			d.x++;
		}
		d.y++;
	}
	d.y = 0;
	while (d.y < token->size)
		align_by_left_edge(&token->position[d.y++], token->min)
}

void 	record_player_positions(t_map plateau, t_player *player)
{
	t_point		d;

	player->size = define_nbr_of_elements(plateau, player.id);
	player->positions = (t_point*)ft_memalloc(sizeof(t_point) * player->size);
	ISNOTNULL(player->positions);
	d.y = 0;
	while (d.y < plateau.height)
	{
		d.x = 0;
		while (d.x < plateau.width)
		{
			if (ft_toupper(plateau.grid[d.y][d.x]) == player->id)
				player->positions[d.y] = d;
			d.x++;
		}
		d.y++;
	}
}