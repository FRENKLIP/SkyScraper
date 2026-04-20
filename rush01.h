/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpaluku <fpaluku@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/28 17:37:51 by fpaluku           #+#    #+#             */
/*   Updated: 2026/03/28 19:15:35 by fpaluku          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUSH01_H
# define RUSH01_H

# include <unistd.h>

int		checks(char *str);
void	convert(char *str, int clues[16]);
void	init_grid(int grid[4][4]);
int		check_row(int row, int number, int grid[4][4]);
int		check_col(int col, int number, int grid[4][4]);
int		safe(int row, int col, int number, int grid[4][4]);
int		count_visible(int line[4]);
int		check_one_row(int grid[4][4], int clues[16], int row);
int		check_one_col(int grid[4][4], int clues[16], int col);
int		check_all_views(int grid[4][4], int clues[16]);
int		solve(int grid[4][4], int clues[16], int pos);
void	print_grid(int grid[4][4]);

#endif