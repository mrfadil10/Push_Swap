/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_strs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfadil <mfadil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 15:47:38 by mfadil            #+#    #+#             */
/*   Updated: 2023/04/08 00:58:23 by mfadil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_count_words(const char *str, char c)
{
	int	i;
	int	flag;

	i = 0;
	flag = 0;
	while (*str)
	{
		if (*str != c && flag == 0)
		{
			flag = 1;
			i++;
		}
		else if (*str == c)
			flag = 0;
		str++;
	}
	return (i);
}

static char	*ft_put_words(const char *str, int start, int end)
{
	char	*word;
	int		i;

	i = 0;
	word = ft_calloc(sizeof(char), (end - start + 1));
	while (start < end)
		word[i++] = str[start++];
	return (word);
}

void	free_split(char **str, int j)
{
	while (j--)
		free(str[j]);
	free(str);
}

int	mini_split(char **result, char c, int *index, const char *s)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (*s && i <= ft_strlen(s))
	{
		if (s[i] != c && *index < 0)
			*index = i;
		else if ((s[i] == c || i == ft_strlen(s)) && *index >= 0)
		{
			result[j++] = ft_put_words(s, *index, i);
			if (!result[j - 1])
			{
				free_split(result, j - 1);
				return (0);
			}
			*index = -1;
		}
		i++;
	}
	return (1);
}

char	**ft_split(char const *s, char c)
{
	int		index;
	char	**result;

	index = -1;
	if (!s)
		return (NULL);
	result = ft_calloc(sizeof(char *), (ft_count_words(s, c) + 1));
	if (!s || !result)
		return (0);
	if (!mini_split(result, c, &index, s))
		return (0);
	return (result);
}
