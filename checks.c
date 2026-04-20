/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpaluku <fpaluku@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/28 16:52:45 by fpaluku           #+#    #+#             */
/*   Updated: 2026/03/28 19:43:50 by fpaluku          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

int	check_row(int row, int number, int grid[4][4])
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (grid[row][i] == number)
			return (0);
		i++;
	}
	return (1);
}

int	check_col(int col, int number, int grid[4][4])
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (grid[i][col] == number)
			return (0);
		i++;
	}
	return (1);
}

int	safe(int row, int col, int number, int grid[4][4])
{
	if (check_row(row, number, grid) && check_col(col, number, grid))
		return (1);
	return (0);
}
