/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijaaskel <ijaaskel@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 16:48:00 by ijaaskel          #+#    #+#             */
/*   Updated: 2021/12/07 16:48:04 by ijaaskel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

static char	**ft_free_array(char **dest)
{
	int	i;

	i = 0;
	while (dest)
	{
		ft_strdel(&dest[i]);
		i++;
	}
	free (dest);
	dest = NULL;
	return (dest);
}

static char	*ft_input_word(const char *s, size_t chars)
{
	char	*word;

	word = (char *)malloc(sizeof(char) * chars + 1);
	if (word == NULL)
		return (NULL);
	word = ft_strncpy(word, s, chars);
	word[chars] = '\0';
	return (word);
}

static char	**ft_input_words(char **dest, char const *s, char c, int i)
{
	int	j;
	int	k;

	j = 0;
	while (s[j] != '\0')
	{
		while (s[j] == c)
			j++;
		k = j;
		while (s[j] && s[j] != c)
			j++;
		if (j > k)
		{
			dest[i] = ft_input_word(&s[k], j - k);
			if (dest[i] == NULL)
			{
				ft_free_array(dest);
				return (dest);
			}
			i++;
		}
	}
	return (dest);
}

static int	ft_count_words(char const *s, char c)
{
	int		i;
	int		words;

	i = 0;
	words = 0;
	while (s[i] == c && s[i] != '\0')
		i++;
	while (s[i] != '\0')
	{
		if (s[i] == c)
		{
			while (s[i + 1] == c && s[i] != '\0')
				i++;
			words++;
		}
		i++;
	}
	words++;
	if (s[i - 1] == c)
		words--;
	return (words);
}

char	**ft_strsplit(char const *s, char c)
{
	char	**dest;
	int		words;
	int		i;

	if (s == NULL)
		return (NULL);
	i = 0;
	words = ft_count_words(s, c);
	dest = (char **)malloc(sizeof(char *) * (words + 1));
	if (dest == NULL)
		return (NULL);
	dest = ft_input_words(dest, s, c, i);
	dest[words] = NULL;
	return (dest);
}
