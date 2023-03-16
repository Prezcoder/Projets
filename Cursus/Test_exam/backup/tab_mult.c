/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab_mult.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbouchar <fbouchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 15:14:08 by fbouchar          #+#    #+#             */
/*   Updated: 2023/03/16 10:01:42 by fbouchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_atoi(char *str)
{
	int i;
	int result;
	
	i = 0;
	result = 0;
	while (str[i] != '\0' && str[i] >= '0' && str[i] <= '9')
    {
        result = result * 10 + str[i] - '0';
        i++;
    }
    return (result);
}

void ft_putnbr(int n)
{
	char c;

	if (n >= 10)
		ft_putnbr(n / 10);
	c = (n % 10) + '0';
	write(1, &c, 1);
}

int main(int argc, char **argv)
{
	int i;
	int j;
	int l;
	int h;
	
	i = 1;
	j = 0;
	l = 0;
	h = 0;
	j = ft_atoi(argv[1]);
	if (argc == 2)
	{
		while (i <= 9)
		{	
			ft_putnbr(i);
			write(1, " x ", 3);
			ft_putnbr(j);
			write(1, " = ", 3);
			ft_putnbr(i * j);
			write(1, "\n", 1);
			i++;
		}
		
	}
}