/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshala <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 18:05:27 by dshala            #+#    #+#             */
/*   Updated: 2019/09/16 20:17:43 by dshala           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H
# include "libft.h"
# include "stdio.h"
# define STDOUT 0
# define STAR 42
# define ISNOTNULL(x) if ((x) == NULL) perror("NULL");

typedef struct	s_point
{
	int			x;
	int			y;
}				t_point;

typedef struct	s_player
{
	char		id;
	t_point		*positions;
	int			size;
}				t_player;

typedef struct	s_token
{
	int			cells;
	t_point		*positions;
	t_point		**placed_tokens;
	int			valid_pos;
}				t_token;

typedef struct	s_map
{
	int			height;
	int			width;
	int			size;
	char		**grid;
}				t_map;

typedef struct	s_game
{
	t_map		plateau;
	int			**heatmap;
	t_map		piece;
	t_player	me;
	t_player	enemy;
	t_token		token;
	t_point		*result;

}				t_game;

int				parse_input(t_game data);
int				**get_heatmap(t_map plateau, t_player me, t_player enemy);
int				define_nbr_of_elements(t_map map, char id);
void			record_token_positions(t_token *token, t_map peace);
short			check_boundary_conditions(t_game data, t_point *valid_nodes);
int				place_token(t_game data);
void			free_data_game(t_game data);
t_point			**get_valid_states(t_game data, t_point node, int *valid_pos,
							int index);
#endif
