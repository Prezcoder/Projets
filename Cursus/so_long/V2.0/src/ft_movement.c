/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_movement.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbouchar <fbouchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 08:38:51 by fbouchar          #+#    #+#             */
/*   Updated: 2023/03/06 15:27:31 by fbouchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_up(t_map *ms)
{
	ms->direction = 'N';
	if (ms->map[ms->player.y - 1][ms->player.x] == '0'
		|| ms->map[ms->player.y - 1][ms->player.x] == '2'
		|| ms->map[ms->player.y - 1][ms->player.x] == 'C'
		|| ms->map[ms->player.y - 1][ms->player.x] == 'X'
		|| ms->map[ms->player.y - 1][ms->player.x] == 'E')
	{
		ms->move_count++;
		ft_print_moves(ms);
		ft_printf("Moves:%d\n", ms->move_count);
		if (ft_check_for_c_and_e(ms, ms->map[ms->player.y - 1]
				[ms->player.x]) == 1)
			return ;
		ms->map[ms->player.y - 1][ms->player.x] = 'P';
		ms->map[ms->player.y][ms->player.x] = '2';
		ms->player.y--;
		return ;
	}
}

void	ft_down(t_map *ms)
{
	ms->direction = 'S';
	if (ms->map[ms->player.y + 1][ms->player.x] == '0'
		|| ms->map[ms->player.y + 1][ms->player.x] == '2'
		|| ms->map[ms->player.y + 1][ms->player.x] == 'C'
		|| ms->map[ms->player.y + 1][ms->player.x] == 'X'
		|| ms->map[ms->player.y + 1][ms->player.x] == 'E')
	{
		ms->move_count++;
		ft_print_moves(ms);
		ft_printf("Moves:%d\n", ms->move_count);
		if (ft_check_for_c_and_e(ms, ms->map[ms->player.y + 1]
				[ms->player.x]) == 1)
			return ;
		ms->map[ms->player.y + 1][ms->player.x] = 'P';
		ms->map[ms->player.y][ms->player.x] = '2';
		ms->player.y++;
		return ;
	}
}

void	ft_right(t_map *ms)
{
	ms->direction = 'E';
	if (ms->map[ms->player.y][ms->player.x + 1] == '0'
		|| ms->map[ms->player.y][ms->player.x + 1] == '2'
		|| ms->map[ms->player.y][ms->player.x + 1] == 'C'
		|| ms->map[ms->player.y][ms->player.x + 1] == 'X'
		|| ms->map[ms->player.y][ms->player.x + 1] == 'E')
	{
		ms->move_count++;
		ft_print_moves(ms);
		ft_printf("Moves:%d\n", ms->move_count);
		if (ft_check_for_c_and_e(ms, ms->map[ms->player.y]
				[ms->player.x + 1]) == 1)
			return ;
		ms->map[ms->player.y][ms->player.x + 1] = 'P';
		ms->map[ms->player.y][ms->player.x] = '0';
		ms->player.x++;
		return ;
	}
}

void	ft_left(t_map *ms)
{
	ms->direction = 'O';
	if (ms->map[ms->player.y][ms->player.x - 1] == '0'
		|| ms->map[ms->player.y][ms->player.x - 1] == '2'
		|| ms->map[ms->player.y][ms->player.x - 1] == 'C'
		|| ms->map[ms->player.y][ms->player.x - 1] == 'X'
		|| ms->map[ms->player.y][ms->player.x - 1] == 'E')
	{
		ms->move_count++;
		ft_print_moves(ms);
		ft_printf("Moves:%d\n", ms->move_count);
		if (ft_check_for_c_and_e(ms, ms->map[ms->player.y]
				[ms->player.x - 1]) == 1)
			return ;
		ms->map[ms->player.y][ms->player.x - 1] = 'P';
		ms->map[ms->player.y][ms->player.x] = '0';
		ms->player.x--;
		return ;
	}
}

int	ft_check_for_c_and_e(t_map *ms, char c)
{
	if (c == 'C')
	{
		ms->c--;
		ft_print_collected_c(ms);
		if (ms->c == 0)
			ft_printf("Yeah! That's a neet job!\n");
	}
	else if (c == 'E' && ms->c != 0)
	{
		ft_printf("Not done yet!\n");
		return (1);
	}
	else if (c == 'E' && ms->c == 0)
	{
		mlx_close_window(ms->mlx);
		ft_printf("You made it in %d moves!\n", ms->move_count);
		ft_delete_image_old(ms);
	}
	else if (c == 'X')
	{
		mlx_close_window(ms->mlx);
		ft_printf("You're DEAD!!!\n");
		ft_delete_image_old(ms);
	}
	return (0);
}
