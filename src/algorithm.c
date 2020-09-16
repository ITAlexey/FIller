/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshala <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 18:05:27 by dshala            #+#    #+#             */
/*   Updated: 2019/09/16 20:17:43 by dshala           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

t_point					**get_valid_states(t_game data, t_point node,
							int *valid_pos, int index)
{
	t_point		diff;
	t_point		*valid_nodes;
	int			i;

	if (index == data.token.cells)
		return (valid_pos ? data.token.placed_tokens : NULL);
	else
	{
		valid_nodes = (t_point*)ft_memalloc(sizeof(t_point) * data.token.cells);
		ISNOTNULL(valid_nodes);
		i = 0;
		diff = get_distance(data.token.positions[index], node);
		while (i < data.token.cells)
		{
			valid_nodes[i] = place_cell(data.token.positions[i], diff);
			i++;
		}
		if (check_boundary_conditions(data, valid_nodes))
			data.token.placed_tokens[(*valid_pos)++] = valid_nodes;
		return (get_valid_states(data, node, valid_pos, ++index));
	}
}
