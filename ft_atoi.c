/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bogunlan <bogunlan@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 04:47:11 by bogunlan          #+#    #+#             */
/*   Updated: 2022/04/29 12:11:32 by bogunlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


/* 
	Description:			The C library function int atoi(const char *str) converts the string argument str to an integer (type int)

	Prototype:				int atoi(const char *str)

	Parameters:				str − This is the string representation of an integral number.

	Return Value:			This function returns the converted integral number as an int value. If no valid conversion could be performed, it returns zero.

 */
int	ft_atoi(const char *str)
{
	int	res;
	int	sign;

	res = 0;
	sign = 1;
	while (*str == 32 || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-')
		sign *= -1;
	if (*str == '-' || *str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		res = res * 10 + *str - '0';
		str++;
	}
	return (res * sign);
}


/*
int main ()
{
	char a[] = "1234";
	char b[] = "3hello5";
	printf("%d\n", ft_atoi(a));
	printf("%d", ft_atoi(b));
	return 0;
}
*/