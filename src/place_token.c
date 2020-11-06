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

static void			find_best_place(t_token token, int **heatmap, t_point *res, int *min)
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
		if (sum < *min)
		{
			*min = sum;
			res->x = token.placed_tokens[d.y][0].x - token.positions[0].x - token.min.x;
			res->y = token.placed_tokens[d.y][0].y - token.positions[0].y - token.min.y;
		}
		d.y++;
	}
}

static void			find_candidate(t_game data)
{
	int	index;
	int min;

	index = 0;
	min = data.plateau.width * data.plateau.height;
	while (index < data.me.size)
	{
		data.token.placed_tokens =
				(t_point**)ft_memalloc(sizeof(t_point*) * data.token.cells);
		ISNOTNULL(data.token.placed_tokens);
		data.token.valid_pos = 0;
		if (get_valid_states(data, data.me.positions[index++],
				&data.token.valid_pos, 0))
			find_best_place(data.token, data.heatmap, data.result, &min);
		ft_2dmemdel((void**)data.token.placed_tokens, data.token.cells);
	}
}

void 				print_hm(int **hm, int y, int x)
{
	printf("\t");
	for (int i = 0; i < y; i++)
		printf("%02d  ", i);
	printf("\n");
	for (int i = 0; i < y; i++)
	{
		printf("%03d\t", i);
		for (int j = 0; j < x; j++)
		{
			if (hm[i][j] == -1)
				printf(" E");
			else if (hm[i][j] == -2)
				printf(" M");
			else
				printf("%02d", hm[i][j]);
			printf("  ");
		}
		printf("\n");
	}
	printf("\n");
}

int					place_token(t_game data)
{
	short	is_continue;

	is_continue = TRUE;
	data.result = (t_point*)ft_memalloc(sizeof(t_point));
	//print_hm(data.heatmap, data.plateau.height, data.plateau.width);
	find_candidate(data);
	ft_printf("%d %d\n", data.result->y, data.result->x);
	is_continue = data.result->x != 0 && data.result->y != 0 ? TRUE : FALSE;
	free_data_game(data);
	return (is_continue);
}
