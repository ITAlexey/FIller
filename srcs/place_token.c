//
// Created by alexey on 11.09.2020.
//

#include "filler.h"

/*restrictions:
* must overlap only one cell of player me
* can't overlap enemy cells
* must be within the boundaries of plateau
*/

static inline t_point	place_cell(t_point token, t_point node)
{
	node.x -= token.x;
	node.y -= token.y;
	return (node);
}

static inline short 	is_out_of_borders(t_point node, t_map map)
{
	return (node.x < 0 || node.y < 0
		|| node.x >= map.width || node.y >= map.height);
}

static inline short 	is_on_same_positions(t_point a, t_point b)
{
	return (!(a.x - b.x && a.y - b.y));
}

short 		is_overlap_enemy(t_point *nodes, int size, t_player enemy)
{
	int 	i;
	int 	j;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < enemy.size)
		{
			if (is_on_same_positions(nodes[i], enemy.positions[j]))
				return (TRUE);
			j++;
		}
		i++;
	}
	return (FALSE);
}

short 		is_one_align_overlap(t_point *nodes, int size, t_player player)
{
	int 	i;
	int 	j;
	int 	count_overlaps;

	count_overlaps = 0;
	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < player.size)
		{
			if (is_on_same_position(nodes[i], player.positions[j]))
				count_overlaps++;
			j++;
		}
		i++;
	}
	return (count_overlaps == 1 ? TRUE : FALSE);
}

t_point		*try_place(t_token token, t_point diff, t_map map)
{
	t_point		*tmp;
	int 		index;

	index = 0;
	tmp = (t_point*)ft_memalloc(sizeof(t_point) * token.cells);
	ISNOTNULL(tmp);
	while (index < token.cells)
	{
		tmp[index].x = token.positions[index].x + diff.x;
		tmp[index].y = token.positions[index].y + diff.y;
		if (is_out_of_borders(tmp[index], map) && !is_overlap_enemy(data.token, data.enemy)
			&& is_one_align_overlap(nodes, data.token.size, data.me))
		{
			ft_memdel(&tmp);
			break ;
		}
		index++;
	}
	return (tmp);
}

void 		get_valid_states(t_game data, t_token *token, t_point node)
{
	t_point diff;
	int 	i;
	t_point	*valid_state;

	data.token.placed_tokens = (t_point**)ft_memalloc(sizeof(t_point*) * token.cells);
	ISNOTNULL(data.token.placed_tokens);
	data.token.valid_pos = 0;
	i = 0;
	nodes = NULL;
	while (i < data.token.cells)
	{
		diff = place_cell(data.token.positions[i], node);
		if (!is_out_of_borders(diff, data.plateau) &&
			get_valid_states(data, node, diff, &valid_state)) && valid_state)
			data.token.placed_tokens[valid_pos++] = valid_state;
		i++;
	}
}

int 	place_token(t_game data)
{
	int		index;

	index  = 0
	while (index < data.me.size)
	{
		if (get_valid_states(data, &data.token, data.me.positions[index++])
			&& data.token.placed_tokens)
		{
			//find_best;
		}
	}
}