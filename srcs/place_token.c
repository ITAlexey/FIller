//
// Created by alexey on 11.09.2020.
//

#include "filler.h"

t_point	find_best_position(t_point my_node, int **heatmap, t_map plateau, t_map token)
{
	t_point		dot;

	/*restrictions:
	 * must overlap only one cell of player me
	 * can't overlap enemy cells
	 * must be within the boundaries of plateau
	*/
}

int 	place_token(t_game data, int **heatmap)
{
	int 	index;
	t_point	candidate;

	index = 0;
	while (index < data.me.size)
		candidate = find_best_position(data.me.positions[index++], heatmap, data.plateau, data.peace);
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