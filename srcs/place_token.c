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

t_point		*accommodate_token(t_token token, diff, t_map map)
{
	t_point		*tmp;
	int 		index;

	index = 0;
	tmp = (t_point*)ft_memalloc(sizeof(t_point) * token.size);
	ISNOTNULL(tmp);
	while (index < token.size)
	{
		tmp[index] = place_cell(diff, data.token.positions[index]);
		if (is_out_of_borders(tmp[index], map))
		{
			ft_memdel(&tmp);
			break ;
		}
		index++;
	}
	return (tmp);
}

short 		is_overlap_enemy(t_point *nodes, int size, t_player enemy)
{
	int 	j;
	int 	i;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < enemy.size)
		{
			if (nodes[i].x - enemy[j].x && nodes[i].y - enemy[j].y)
				return (TRUE);
			j++;
		}
		i++;
	}
	return (FALSE);
}

short 		check_boundary_conditions(t_game data, t_point node)
{
	t_point diff;
	t_point	*nodes;
	int 	align_overlap;
	int 	i;

	i = 0;
	align_overlap = 0;
	while (i < data.token.size)
	{
		if ((diff = place_cell(data.token.positions[i++], node))
				&& !is_out_of_borders(diff, data.plateau))
		{
			if (nodes = accommodate_token(data.token, diff, data.plateau))
			{
				is_overlap_enemy(nodes, data.token.size, data.enemy)
			}
		}
	}
}

t_point		find_best_place(t_point my_node, int **heatmap, t_game data)
{
	t_point		dot;
	int 		sum;
	int 		index;

	index = 0;
	sum = 132;
	while (index < data.token.size)
	{

	}

}

int 	place_token(t_game data, int **heatmap)
{
	int 	index;
	t_point	candidate;

	index = 0;
	while (index < data.me.size)
	{
		if (!check_boundary_conditions(data, data.me.positions[index]))
			candidate = find_best_place(data.me.positions[index], heatmap, data);
		index++;
	}
	if (is_valid_position(candidate))
	{
		ft_printf("%d, %d\n", candidate.y, candidate.x);
		// free_struct();
		return (1);
	}
	else
	{
		ft_printf("%d, %d\n", 0, 0)
		// free_struct();
		return (0);
	}
}