//
// Created by alexey on 11.09.2020.
//

#include "filler.h"

static inline int 	calculate_distance(t_point a, t_point b)
{
	return (ABC(a.x - b.x) + ABC(a.y - b.y));
}

static int 	define_min_distance(t_player player, int max_dist, t_point node)
{
	int 	index;
	int 	distance;
	int 	tmp;

	distance = max_dist;
	index = 0;
	while (index < player.size)
	{
		tmp = calculate_distance(player.positions[index++], node);
		distance = MIN(distance, tmp);
	}
	return (distance);
}

int	 	**get_heatmap(t_map plateau, t_player me, t_player enemy)
{
	int 		**heatmap;
	t_point		d;

	d.y = 0;
	heatmap = (int**)ft_memalloc(sizeof(int*) * plateau.height);
	ISNOTNULL(heatmap);
	while (d.y < plateau.height)
	{
		d.x = 0;
		heatmap[d.y] = (int*)ft_memalloc(sizeof(int) * plateau.width);
		ISNOTNULL(heatmap[d.y]);
		while (d.x < plateau.width)
		{
			if (ft_toupper(plateau.grid[d.y][d.x]) == me.id)
				heatmap[d.y][d.x] = -1;
			else if (ft_toupper(plateau.grid[d.y][d.x]) == enemy.id)
				heatmap[d.y][d.x] = -2;
			else
				heatmap[d.y][d.x] = define_min_distance(enemy, plateau.size, d);
			d.x++;
		}
		d.y++;
	}
	return (heatmap);
}