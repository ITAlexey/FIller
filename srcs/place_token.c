//
// Created by alexey on 11.09.2020.
//

#include "filler.h"

/*restrictions:
* must overlap only one cell of player me
* can't overlap enemy cells
* must be within the boundaries of plateau
*/

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
		candidate = find_best_place(data.me.positions[index++], heatmap, data);
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