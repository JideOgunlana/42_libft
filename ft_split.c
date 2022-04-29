
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bogunlan <bogunlan@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 17:31:30 by bogunlan          #+#    #+#             */
/*   Updated: 2022/04/27 18:44:54 by bogunlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


/* 
Function name				ft_split

Prototype 					char **ft_split(char const *s, char c);

Turn in files -				Parameters s: The string to be split.
							c: The delimiter character.

Return value 				The array of new strings resulting from the split. NULL if the allocation fails.

External functs.: 			malloc, free

Description 				Allocates (with malloc(3)) and returns an array of strings obtained by splitting ’s’ using the character ’c’ as a delimiter. The array must end with a NULL pointer 
*/

#include "libft.h"
#define TRUE 1
#define FALSE 0

static int	ft_word_count(char const *s, char c)
{
	int				in_word;
	int				word_count;
	unsigned int	i;

	i = 0;
	word_count = 0;
	while (i < ft_strlen(s))
	{
		if (s[i] != c)
		{
			in_word = TRUE;
			while ((in_word) && (++i))
			{
				if ((s[i] == c) || s[i] == '\0')
				{
					word_count++;
					in_word = FALSE;
				}
			}
		}
		i++;
	}
	return (word_count);
}

char	**ft_gen(const char *s, char c, char **res, int res_s_i)
{
	unsigned int	i;
	int				in_word;
	int				word_start;

	i = 0;
	while (i < ft_strlen(s))
	{
		word_start = i;
		if (s[i] != c)
		{
			in_word = TRUE;
			while ((in_word) && (++i))
			{
				if ((s[i] == c) || (s[i] == '\0'))
				{
					res[res_s_i++] = ft_substr(s, word_start, i - word_start);
					in_word = FALSE;
				}
			}
		}
		i++;
	}
	res[res_s_i] = NULL;
	return (res);
}

char	**ft_split(char const *s, char c)
{
	char	**sarray;
	int		sarray_start_index;

	sarray_start_index = 0;
	if (!s)
		return (NULL);
	sarray = (char **) malloc(sizeof(char *) * (ft_word_count(s, c) + 1));
	if (!sarray)
		return (NULL);
	sarray = ft_gen(s, c, sarray, sarray_start_index);
	return (sarray);
}

// ----------------------------//////////\\\\\\\\\\\-------------------\\>

// #include <stdlib.h>
// #include <unistd.h>
// #include <stdio.h>

// static int	ft_word_count(char const *s, char c, int i, int wordcount)
// {
// 	int	in_word;

// 	in_word = 0;
// 	i = 0;
// 	while (s[i] != '\0')
// 	{
// 		if (s[i] != c)
// 		{
// 			in_word = 1;
// 			wordcount += 1;
// 			while (in_word)
// 			{
// 				i++;
// 				if (s[i] == '\0')
// 					break ;
// 				if (s[i] == c)
// 					in_word = 0;
// 			}
// 		}
// 		if (s[i] == '\0')
// 			break;
// 		i++;
// 	}
// 	return wordcount;
// }

// char	*ft_substr(char const *s, unsigned int start, size_t len)
// {
// 	char			*substr;
// 	unsigned int	i;
// 	unsigned int	j;

// 	if (!s)
// 		return (NULL);
// 	substr = (char *) malloc(sizeof(char) * (len + 1));
// 	if (!substr)
// 		return (NULL);
// 	i = 0;
// 	j = 0;
// 	while (s[i] != '\0')
// 	{
// 		while (i == start && j < len)
// 		{
// 			substr[j] = s[j + i];
// 			j++;
// 		}
// 		if (j == len)
// 			break ;
// 		i++;
// 	}
// 	substr[j] = '\0';
// 	return (substr);
// }


// char    **ft_split(char const *s, char c)
// {
//     unsigned int    i;
//     int    j;
//     // unsigned int    k;
//     int    start;
//     char   **sarray;
//     int    wordcount;
// 	int		in_word;
// 	// char	*new;
//     i = 0;
// 	start = 0;
// 	wordcount = 0;
// 	wordcount = ft_word_count(s, c, i, wordcount);
//     printf(":%d:\n", wordcount);
//     sarray = (char **) malloc(sizeof(char*) * (wordcount + 1));
//     if(!sarray)
//         return NULL;
	

// 	j = 0;

// 		while (s[i] != '\0')
// 	{
// 		start = i;
// 		if (s[i] != c)
// 		{
// 			in_word = 1;
// 			wordcount += 1;
// 			while (in_word)
// 			{
// 				printf("%d -> %d\n", i, start);
// 				i++;
// 				if (s[i] == '\0')
// 					break ;
// 				if (s[i] == c)
// 				{
// 					in_word = 0;
// 					sarray[j++] = ft_substr(s, start, i - start);
// 				}
// 			}
// 		}
// 		if (s[i] == '\0'){
// 			printf(":%d -> %d:\n", i, start);
// 			sarray[j++] = ft_substr(s, start, i - start);
// 			break;
// 		}
// 		i++;
// 	}



		

// 	sarray[j] = 0;
//     return sarray;
// }


// int main ()
// {
//     printf("%s",ft_split("dfasd______dfas____sfd", '_')[3]);
//     return (0);
// }


// #include "libft.h"
// #define TRUE 1
// #define FALSE 0

// static int	ft_word_count(char const *s, char c)
// {
// 	int	in_word;
// 	int word_count = 0;
// 	int i;

// 	i = 0;
// 	while (s[i] != '\0')
// 	{
// 		if (s[i] != c)
// 		{
// 			in_word = TRUE;
// 			// word_count += 1;
// 			while ((in_word) && (word_count++) && (++i))
// 			{
// 				// i++;
// 				if (s[i] == '\0')
// 					break ;
// 				if (s[++i] == c)
// 					in_word = FALSE;
// 			}
// 		}
// 		if (s[i] == '\0')
// 			break;
// 		i++;
// 	}
// 	return word_count;
// }


// char	**ft_gen(const char *s, char c, char **res, int word_count)
// {
// 	int i = 0;
// 	int j = 0;
// 	int in_word;
// 	int st;

// 	while (s[i] != '\0')
// 	{
// 		st = i;
// 		if (s[i] != c)
// 		{
// 			in_word = TRUE;
// 			while ((in_word) && (word_count++) && (++i))
// 			{
// 				if (s[i] == '\0')
// 					break ;
// 				if (s[i] == c)
// 				{
// 					in_word = FALSE;
// 					res[j++] = ft_substr(s, st, i - st);
// 				}
// 			}
// 		}
// 		if (s[i] == '\0'){
// 			res[j++] = ft_substr(s, st, i - st);
// 			break;
// 		}
// 		i++;
// 	}
// 	res[j] = 0;
// 	return res;
// }

// char	**ft_split(char const *s, char c)
// {
// 	int		start;
// 	char	**sarray;

// 	start = 0;
// 	if (!s)
// 		return (NULL);
// 	sarray = (char **) malloc(sizeof(char*) * (ft_word_count(s, c) + 1));
// 	if(!sarray)
// 		return (NULL);
// 	sarray = ft_gen(s, c, sarray, ft_word_count(s, c));
// 	return sarray;
// }




//////////// -last attempt to reduce function to conform with the norm /////////

// #include "libft.h"
// #define TRUE 1
// #define FALSE 0

// static int	ft_word_count(char const *s, char c)
// {
// 	int	in_word;
// 	int word_count;
// 	int i;

// 	i = 0;
// 	word_count = 0;
// 	while (s[i] != '\0')
// 	{
// 		if (s[i] != c)
// 		{
// 			in_word = TRUE;
// 			while ((in_word) && (word_count++) && (++i))
// 			{
// 				if (s[i] == '\0')
// 					break ;
// 				if (s[++i] == c)
// 					in_word = FALSE;
// 			}
// 		}
// 		if (s[i] == '\0')
// 			break;
// 		i++;
// 	}
// 	return word_count;
// }

// char **ft_gen_help(const char *s, char c, int i, int in_word)
// {
// 	int word_count;

// 	word_count = ft_word_count(s, c);
// 	while ((in_word) && (word_count++) && (++i))
// 	{
// 		if (s[i] == '\0')
// 			break ;
// 		if (s[i] == c)
// 		{
// 			in_word = FALSE;
// 			res[j++] = ft_substr(s, start, i - st);
// 		}
// 	}
// }


// char	**ft_gen(const char *s, char c, char **res, int word_count)
// {
// 	int i;
// 	int j;
// 	int in_word;
// 	int start;

// 	i = 0;
// 	j = 0;
// 	while ((s[i] != '\0') && (i < ft_strlen(s)))
// 	{
// 		start = i;
// 		if ((s[i] != c))
// 		{
// 			in_word = TRUE;
// 			while ((in_word) && (word_count++) && (++i))
// 			{
// 				if ((s[i] == '\0') && (res[j++] = ft_substr(s, start, i - start)))
// 					break ;
// 				if ((s[i] == c) && (res[j++] = ft_substr(s, start, i - start)))
// 					in_word = FALSE;
// 			}
// 		}
// 		i++;
// 	}
// 	res[j] = 0;
// 	return res;
// }

// char	**ft_split(char const *s, char c)
// {
// 	int		start;
// 	char	**sarray;

// 	start = 0;
// 	if (!s)
// 		return (NULL);
// 	sarray = (char **) malloc(sizeof(char*) * (ft_word_count(s, c) + 1));
// 	if(!sarray)
// 		return (NULL);
// 	sarray = ft_gen(s, c, sarray, ft_word_count(s, c));
// 	return sarray;
// }
