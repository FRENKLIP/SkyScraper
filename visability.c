/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visability.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpaluku <fpaluku@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/28 17:44:44 by fpaluku           #+#    #+#             */
/*   Updated: 2026/03/28 19:43:42 by fpaluku          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

int	count_visible(int line[4])
{
	int	i;
	int	max;
	int	visible;

	i = 0;
	max = 0;
	visible = 0;
	while (i < 4)
	{
		if (line[i] > max)
		{
			max = line[i];
			visible++;
		}
		i++;
	}
	return (visible);
}

int	check_one_row(int grid[4][4], int clues[16], int row)
{
	int	line[4];
	int	reversed_line[4];
	int	i;

	i = 0;
	while (i < 4)
	{
		line[i] = grid[row][i];
		i++;
	}
	if (count_visible(line) != clues[8 + row])
		return (0);
	i = 0;
	while (i < 4)
	{
		reversed_line[i] = grid[row][3 - i];
		i++;
	}
	if (count_visible(reversed_line) != clues[12 + row])
		return (0);
	return (1);
}

int	check_one_col(int grid[4][4], int clues[16], int col)
{
	int	line[4];
	int	reversed_line[4];
	int	i;

	i = 0;
	while (i < 4)
	{
		line[i] = grid[i][col];
		i++;
	}
	if (count_visible(line) != clues[col])
		return (0);
	i = 0;
	while (i < 4)
	{
		reversed_line[i] = grid[3 - i][col];
		i++;
	}
	if (count_visible(reversed_line) != clues[4 + col])
		return (0);
	return (1);
}

int	check_all_views(int grid[4][4], int clues[16])
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (check_one_row(grid, clues, i) == 0)
			return (0);
		i++;
	}
	i = 0;
	while (i < 4)
	{
		if (check_one_col(grid, clues, i) == 0)
			return (0);
		i++;
	}
	return (1);
}
