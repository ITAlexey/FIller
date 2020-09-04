/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshala <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 16:51:15 by dshala            #+#    #+#             */
/*   Updated: 2019/09/19 12:54:43 by dshala           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#define IN 1
#define OUT 0

static char			**free_splitted_str(char **str, long pos)
{
	while (pos >= 0)
		free(str[pos--]);
	free(str);
	str = NULL;
	return (str);
}

static long			count_letters_in_word(char const *s, long *offset, char dil)
{
	int		is_in_word;
	long	counter;
	long	start;

	counter = 0;
	start = 0;
	is_in_word = OUT;
	while (s[start] != '\0')
	{
		if (s[start] != dil)
		{
			if (is_in_word == OUT)
				*(offset) += start;
			is_in_word = IN;
			counter++;
		}
		else if (is_in_word == IN)
			break ;
		start++;
	}
	return (counter);
}

char				**ft_strsplit(char const *str, char c)
{
	long	nbr_of_words;
	long	i;
	char	**splitted_str;
	long	nbr_of_letters;
	long	offset;

	i = 0;
	offset = 0;
	if (str == NULL)
		return (NULL);
	nbr_of_words = ft_count_words(str, c);
	if (!(splitted_str = (char**)malloc(sizeof(char*) * (nbr_of_words + 1))))
		return (NULL);
	while (i < nbr_of_words)
	{
		nbr_of_letters = count_letters_in_word(str, &offset, c);
		str += offset;
		if (!(splitted_str[i] = ft_strsub(str, 0, nbr_of_letters)))
			return (free_splitted_str(splitted_str, i));
		str += nbr_of_letters;
		offset = 0;
		i++;
	}
	splitted_str[i] = NULL;
	return (splitted_str);
}
