//
// Created by alexey on 11.09.2020.
//

#include "filler.h"

static inline t_point	get_distance(t_point token, t_point node)
{
	node.x -= token.x;
	node.y -= token.y;
	return (node);
}

static inline t_point	place_cell(t_point a, t_point b)
{
	a.x += b.x;
	a.y += b.y;
	return (a);
}

t_point 	**get_valid_states(t_game data, t_point node, int *valid_pos, int index)
{
	t_point		diff;
	t_point		*valid_nodes;
	int 		i;

	if (index == data.token.cells)
		return (valid_pos ? data.token.placed_tokens : NULL);
	else
	{
		valid_nodes = (t_point*)ft_memalloc(sizeof(t_point) * data.token.cells);
		ISNOTNULL(valid_nodes);
		i = 0;
		diff = get_distance(data.token.positions[index], node);
		while (i < data.token.cells)
			valid_nodes[i] = place_cell(data.token.positions[i++], diff);
		if (check_boundary_conditions(data, valid_nodes))
			data.token.placed_tokens[(*valid_pos)++] = valid_nodes;
		return (get_valid_states(data, node, valid_pos, ++index));
	}
}

t_point		find_best_place(t_token token, int *min_sum, int **heatmap)
{
	t_point		d;
	t_point		candidate;
	int 		sum;

	d.i = 0;
	while (d.i < token.valid_pos)
	{
		d.j = 0;
		sum = 0;
		while (d.j < token.cells)
		{
			candidate = token.placed_tokens[d.i][d.j];
			sum += heatmap[candidate.y][candidate.x];
			d.j++;
		}
		if (sum < *min_sum)
		{
			*min_sum = sum;
			candidate = token.placed_tokens[d.i][0];
		}
		d.i++;
	}
	return (candidate);
}

int 	place_token(t_game data)
{
	int		index;
	int 	min_sum;
	t_point	candidate;

	index = 0;
	min_sum = data.token.cells * data.plateau.size;
	while (index < data.me.size)
	{
		data.token.placed_tokens = (t_point**)ft_memalloc(sizeof(t_point*) * data.token.cells);
		ISNOTNULL(data.token.placed_tokens);
		data.token.valid_pos = 0;
		if (get_valid_states(data, data.me.positions[index++], &data.token.valid_pos, 0))
			candidate = find_best_place(data.token, &min_sum, data.heatmap);
		ft_2dmemdel((void**)data.token.placed_tokens, data.token.cells);
	}
}