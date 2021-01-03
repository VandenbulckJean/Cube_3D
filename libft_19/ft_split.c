/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvanden- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/09 13:37:46 by jvanden-          #+#    #+#             */
/*   Updated: 2020/10/09 13:37:48 by jvanden-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	word_count(char const *s, char c)
{
	unsigned int	i;
	unsigned int	count;

	count = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i])
			count++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (count);
}

unsigned int	letter_count(char const *str, char c, unsigned int i)
{
	unsigned int	letter;

	letter = 0;
	while (str[i] && str[i] != c)
	{
		i++;
		letter++;
	}
	return (letter);
}

char			*copy_word(char const *s, char *word, char c, unsigned int *i)
{
	unsigned int	j;

	j = 0;
	while (s[*i] && s[*i] != c)
	{
		word[j] = s[*i];
		j++;
		(*i)++;
	}
	word[j] = '\0';
	return (word);
}

char			**free_words(char **words)
{
	int i;

	i = 0;
	while (words[i])
	{
		free(words[i]);
		i++;
	}
	free(words);
	return (NULL);
}

char			**ft_split(char const *s, char c)
{
	char			**words;
	unsigned int	i;
	unsigned int	j;
	unsigned int	amount_words;

	if (!s)
		return (0);
	amount_words = word_count(s, c);
	j = 0;
	i = 0;
	if (!(words = malloc(sizeof(char *) * (amount_words + 1))))
		return (NULL);
	while (j < amount_words)
	{
		while (s[i] && s[i] == c)
			i++;
		if (!(words[j] = (char*)malloc(sizeof(char) *
		(letter_count(s, c, i) + 1))))
			return (free_words(words));
		copy_word(s, words[j], c, &i);
		j++;
	}
	words[j] = 0;
	return (words);
}
