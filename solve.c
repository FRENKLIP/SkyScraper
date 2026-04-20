/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpaluku <fpaluku@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/28 18:16:28 by fpaluku           #+#    #+#             */
/*   Updated: 2026/03/28 19:42:47 by fpaluku          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "rush01.h"

int	solve(int grid[4][4], int clues[16], int pos)
{
	int	row;
	int	col;
	int	num;

	if (pos == 16)
		return (check_all_views(grid, clues));
	row = pos / 4;
	col = pos % 4;
	num = 1;
	while (num <= 4)
	{
		if (safe(row, col, num, grid))
		{
			grid[row][col] = num;
			if (solve(grid, clues, pos + 1))
				return (1);
			grid[row][col] = 0;
		}
		num++;
	}
	return (0);
}

void	print_grid(int grid[4][4])
{
	int		i;
	int		j;
	char	c;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			c = grid[i][j] + '0';
			write(1, &c, 1);
			if (j < 3)
				write(1, " ", 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
}
