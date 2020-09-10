//
// Created by alexey on 04.09.2020.
//

#ifndef FILLER_H
# define FILLER_H
# include "libft.h"
# define STDOUT 0

typedef struct	s_point
{
	int 		x;
	int 		y;
}				t_point;

typedef struct	s_player
{
	char 		id;
	t_point 	*positions;
	int 		size;
}				t_player;

typedef struct	s_map
{
	int 		height;
	int 		width;
	int 		size;
	char 		**grid;
}				t_map;

typedef struct	s_game
{
	int 		**heatmap;
	t_map		plateau;
	t_map		piece;
	t_player	player;
	t_player	enemy;

}				t_game;

#endif
