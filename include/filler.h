//
// Created by alexey on 04.09.2020.
//

#ifndef FILLER_H
# define FILLER_H
# include "libft.h"
# define STDOUT 0
# define STAR 42
# define ISNOTNULL (x) (if (!(x)) exit(11))

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

typedef struct	s_token
{
	int 		cells;
	t_point 	*positions;
	t_point		**placed_tokens;
	int 		valid_pos;
}				t_token;

typedef struct	s_map
{
	int 		height;
	int 		width;
	int 		size;
	char 		**grid;
}				t_map;

typedef struct	s_game
{
	t_map		plateau;
	int 		**heatmap;
	t_map		piece;
	t_player	me;
	t_player	enemy;
	t_token		token;

}				t_game;

#endif
