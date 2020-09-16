/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshala <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 18:05:27 by dshala            #+#    #+#             */
/*   Updated: 2019/09/16 20:17:43 by dshala           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static void				align_by_left_edge(t_token *token, t_point min)
{
	int	index;

	index = 0;
	while (index < token->cells)
	{
		token->positions[index].x -= min.x;
		token->positions[index].y -= min.y;
		index++;
	}
}

static inline t_point	define_min(t_point d, t_point *min)
{
	min->x = MIN(min->x, d.x);
	min->y = MIN(min->y, d.y);
	return (d);
}

void					record_token_positions(t_token *token, t_map peace)
{
	t_point		d;
	t_point		min;
	int			index;

	token->cells = define_nbr_of_elements(peace, STAR);
	token->positions = (t_point*)ft_memalloc(sizeof(t_point) * token->cells);
	ISNOTNULL(token->positions);
	index = 0;
	min.x = peace.width;
	min.y = peace.height;
	d.y = 0;
	while (d.y < peace.height)
	{
		d.x = 0;
		while (d.x < peace.width)
		{
			if (peace.grid[d.y][d.x] == STAR)
				token->positions[index++] = define_min(d, &min);
			d.x++;
		}
		d.y++;
	}
	align_by_left_edge(token, min);
}
