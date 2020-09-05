//
// Created by alexey on 04.09.2020.
//

#include "libft.h"

static char 	*retrieve_line(char **line, int size, short is_grid)
{
	char 	*string;

	string = NULL;
	if (get_next_line(STDOUT, line))
	{
		string = ft_strnew(size);
		ISNULL(string);
		ft_strncpy(string, is_grid ? line + 4 : line, size);
	}
	ft_strdel(input);
	return (string);
}

static char 	**record_grid_or_figure(int height, int width, short is_grid)
{
	char 	*input;
	char 	**arr;
	int 	index;

	index = 0;
	arr = (char**)malloc(sizeof(char*) * height + 1);
	ISNULL(arr);
	if (is_grid)
	{
		get_next_line(STDOUT, input);
		ft_strdel(input);
	}
	while (height)
	{
		arr[index++] = retrieve_line(&input, width, is_grid);
		height--;
	}
	return (is_grid ? get_heatmap(arr, height, width) : arr);
}

static void 	record_height_and_width(int *height, int *width)
{
	char 	*input;
	char 	**splitted_input;

	input = NULL;
	if (get_next_line(STDOUT, &input))
	{
		splitted_input = ft_strsplit(input, ' ');
		*height = ft_atoi(splitted_input[1]);
		*width = ft_atoi(splitted_input[2]);
		ft_free2darray(splitted_input);
		ft_strdel(&input);
	}
	else
	{
		ft_strdel(&input);
		ft_printf("Error %s\n", strerror(99));
	}
}

void 	parse_input(t_gamedata data)
{
	record_height_and_width(&data.map.height, &data.map.width);
	data.map.grid = record_grid_or_figure(data.map.height, data.map.width, 1);
	record_height_and_width(&data.token.height, &data.token.width);
	data.token.figure = record_grid_or_figure(data.token.height, data.token.width, 0);
}