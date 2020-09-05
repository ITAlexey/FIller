//
// Created by alexey on 04.09.2020.
//

#ifndef FILLER_H
# define FILLER_H
# include "libft.h"
# define STDOUT 0

typedef struct	s_map
{
	int 		height;
	int 		width;
	char 		**grid;
}				t_map;

typedef struct	s_token
{
	int 		height;
	int 		width;
	char 		**figure;
}				t_token;

typedef struct	s_gamedata
{
	char 		my_id;
	char 		enemy_id;
	t_map		map;
	t_token		token;
}				t_gamedata;

#endif
