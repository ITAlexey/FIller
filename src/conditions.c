/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conditions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshala <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 18:05:27 by dshala            #+#    #+#             */
/*   Updated: 2019/09/16 20:17:43 by dshala           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static short		is_out_of_borders(t_point *nodes, int size, t_map map)
{
	int		i;

	i = 0;
	while (i < size)
	{
		if (nodes[i].x < 0 || nodes[i].y < 0
			|| nodes[i].x >= map.width || nodes[i].y >= map.height)
			return (TRUE);
		i++;
	}
	return (FALSE);
}

static inline short	is_on_same_positions(t_point a, t_point b)
{
	return (!(a.x - b.x) && !(a.y - b.y));
}

static short		is_overlap_enemy(t_point *nodes, int size, t_player enemy)
{
	int	i;
	int	j;

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

static short		is_one_align_overlap(t_point *nodes, int size,
						t_player player)
{
	int	i;
	int	j;
	int	count_overlaps;

	count_overlaps = 0;
	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < player.size)
		{
			if (is_on_same_positions(nodes[i], player.positions[j]))
				count_overlaps++;
			j++;
		}
		i++;
	}
	return (count_overlaps == 1 ? TRUE : FALSE);
}

short				check_boundary_conditions(t_game data, t_point *valid_nodes)
{
	int	size;

	size = data.token.cells;
	if (!is_out_of_borders(valid_nodes, size, data.plateau)
		&& !is_overlap_enemy(valid_nodes, size, data.enemy)
		&& is_one_align_overlap(valid_nodes, size, data.me))
		return (TRUE);
	ft_memdel((void**)&valid_nodes);
	return (FALSE);
}
