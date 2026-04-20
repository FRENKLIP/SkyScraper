/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpaluku <fpaluku@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/28 19:14:31 by fpaluku           #+#    #+#             */
/*   Updated: 2026/03/29 16:46:40 by fpaluku          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"
#include <unistd.h>

int		checks(char *str);
void	convert(char *str, int clues[16]);
void	init_grid(int grid[4][4]);
int		solve(int grid[4][4], int clues[16], int pos);
void	print_grid(int grid[4][4]);

int	main(int argc, char **argv)
{
	int	clues[16];
	int	grid[4][4];

	if (argc != 2 || !checks(argv[1]))
	{
		write(1, "Error\n", 6);
		return (0);
	}
	convert(argv[1], clues);
	init_grid(grid);
	if (solve(grid, clues, 0))
		print_grid(grid);
	else
		write(1, "Error\n", 6);
	return (0);
}
