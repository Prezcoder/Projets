/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush03.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkramer <marvin@42quebec.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 08:54:14 by mkramer           #+#    #+#             */
/*   Updated: 2022/11/26 12:22:07 by fbouchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_putchar(char c);

void	ft_letter(int line, int column, int x, int y)
{
	if (line == 1 || line == y)
	{
		if (column == 1)
		{
			ft_putchar('A');
		}
		else if (column == x)
		{
			ft_putchar('C');
		}
		else
		{
			ft_putchar('B');
		}
	}
	else if (column == 1 || column == x)
	{
		ft_putchar('B');
	}
	else
	{
		ft_putchar(' ');
	}
}

void	rush(int x, int y)
{
	int	line;
	int	column;

	line = 0;
	while (++line <= y && (x > 0 && y > 0))
	{
		column = 0;
		while (++column <= x)
		{
			ft_letter(line, column, x, y);
		}
		ft_putchar('\n');
	}
}
