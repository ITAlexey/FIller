/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place_token.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshala <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 18:05:27 by dshala            #+#    #+#             */
/*   Updated: 2019/09/16 20:17:43 by dshala           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static void			find_best_place(t_token token, int *min_sum,
							int **heatmap, t_point *res)
{
	t_point		d;
	t_point		candidate;
	int			sum;

	d.y = 0;
	while (d.y < token.valid_pos)
	{
		d.x = 0;
		sum = 0;
		while (d.x < token.cells)
		{
			candidate = token.placed_tokens[d.y][d.x];
			sum += heatmap[candidate.y][candidate.x];
			d.x++;
		}
		if (sum < *min_sum)
		{
			*min_sum = sum;
			res->x = token.placed_tokens[d.y][0].x;
			res->y = token.placed_tokens[d.y][0].y;
		}
		d.y++;
	}
}

static void			find_candidate(t_game data, int min_sum, short *is_match)
{
	int	index;

	index = 0;
	while (index < data.me.size)
	{
		data.token.placed_tokens =
				(t_point**)ft_memalloc(sizeof(t_point*) * data.token.cells);
		ISNOTNULL(data.token.placed_tokens);
		data.token.valid_pos = 0;
		if (get_valid_states(data, data.me.positions[index++],
				&data.token.valid_pos, 0))
		{
			*is_match = TRUE;
			find_best_place(data.token, &min_sum, data.heatmap, data.result);
		}
		ft_2dmemdel((void**)data.token.placed_tokens, data.token.cells);
	}
}

int					place_token(t_game data)
{
	int		min_sum;
	short	is_match;

	is_match = FALSE;
	data.result = (t_point*)ft_memalloc(sizeof(t_point));
	min_sum = data.token.cells * data.plateau.size;
	find_candidate(data, min_sum, &is_match);
	is_match ? ft_printf("%d %d\n", data.result->y, data.result->x)
		: ft_printf("%d %d\n", 0, 0);
	free_data_game(data);
	return (is_match ? TRUE : FALSE);
}
