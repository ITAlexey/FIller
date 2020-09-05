//
// Created by alexey on 05.09.2020.
//

#include "filler.h"

char 		**get_heatmap(char **map, int height, int width)
{
	int 	x;
	int 	y;

	x = 0;
	y = 0;
	while (y < height)
	{
		while (x < width)
		{

			x++;
		}
		y++;
	}
	return (map);

}
