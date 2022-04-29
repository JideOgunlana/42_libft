/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bogunlan <bogunlan@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 17:44:57 by bogunlan          #+#    #+#             */
/*   Updated: 2022/04/29 12:15:19 by bogunlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* 
	Description:			The bzero() function fills the first n bytes of the object pointed to by dst with zero (NUL) bytes.

	Prototype:				void bzero( void *dst, size_t n )

	Parameters:				dst:     an existing object that you want to fill with zeroes.
							n:       The number of bytes to fill.

	No return value
 */

void	ft_bzero(void *s, size_t n)
{
	size_t	i;

	i = 0;
	if (n != 0)
	{
		while (i < n)
		{
			*((char *) s + i) = 0;
			++i;
		}
	}
	return ;
}

/* int	main()
{
	char	c[] = "Hello Man!";
	int i = 0;
	while(c[i] != '\0')
	{
		printf("%c\n", c[i]);
		++i;
	}
	i = 0;
	ft_bzero(c, 4);
	while(c[i] != '\0')
	{
		printf("%c\n", c[i]);
		++i;
	}
} */