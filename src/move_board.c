/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_board.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhsin <muhsin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/15 21:29:00 by muhsin            #+#    #+#             */
/*   Updated: 2026/11/15 21:29:00 by muhsin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/move_board.h"
#include <time.h>

static void	compact(int line[4])
{
	int	temp[4];
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < 4)
	{
		if (line[i] != 0)
		{
			temp[j] = line[i];
			j++;
		}
		i++;
	}
	while (j < 4)
	{
		temp[j] = 0;
		j++;
	}
	i = 0;
	while (i < 4)
	{
		line[i] = temp[i];
		i++;
	}
}

static int	merge(int line[4], t_data *d)
{
	int	i;
	int	changed;

	i = 0;
	changed = 0;
	while (i < 3)
	{
		if (line[i] != 0 && line[i] == line[i + 1])
		{
			line[i] *= 2;
			d->score += line[i];
			line[i + 1] = 0;
			changed = 1;
		}
		i++;
	}
	return (changed);
}

static int	process_line(int line[4], t_data *d)
{
	int	orig[4];
	int	i;

	i = 0;
	while (i < 4)
	{
		orig[i] = line[i];
		i++;
	}
	compact(line);
	merge(line, d);
	compact(line);
	i = 0;
	while (i < 4)
	{
		if (line[i] != orig[i])
			return (1);
		i++;
	}
	return (0);
}

static int	*cell(t_data *d, int i, int k, int vertical, int reversed)
{
	int	row;
	int	col;

	if (vertical)
	{
		row = reversed ? 3 - k : k;
		col = i;
	}
	else
	{
		row = i;
		col = reversed ? 3 - k : k;
	}
	return (&d->board[row][col]);
}

static int	apply_move(t_data *d, int vertical, int reversed)
{
	int	i;
	int	k;
	int	line[4];
	int	changed;

	i = 0;
	changed = 0;
	while (i < 4)
	{
		k = 0;
		while (k < 4)
		{
			line[k] = *cell(d, i, k, vertical, reversed);
			k++;
		}
		if (process_line(line, d))
			changed = 1;
		k = 0;
		while (k < 4)
		{
			*cell(d, i, k, vertical, reversed) = line[k];
			k++;
		}
		i++;
	}
	return (changed);
}

int	move_left(t_data *d)
{
	return (apply_move(d, 0, 0));
}

int	move_right(t_data *d)
{
	return (apply_move(d, 0, 1));
}

int	move_up(t_data *d)
{
	return (apply_move(d, 1, 0));
}

int	move_down(t_data *d)
{
	return (apply_move(d, 1, 1));
}

int	has_move(t_data *d)
{
	int	i;
	int	j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (d->board[i][j] == 0)
				return (1);
			if (j < 3 && d->board[i][j] == d->board[i][j + 1])
				return (1);
			if (i < 3 && d->board[i][j] == d->board[i + 1][j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	has_win(t_data *d)
{
	int	i;
	int	j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (d->board[i][j] >= WIN_VALUE)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

void	spawn_tile(t_data *d)
{
	int	empty[16];
	int	count;
	int	random_index;
	int	random_value;
	int	i;
	int	j;

	count = 0;
	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (d->board[i][j] == 0)
			{
				empty[count] = i * 4 + j;
				count++;
			}
			j++;
		}
		i++;
	}
	if (count == 0)
		return ;
	random_index = rand() % count;
	random_value = (rand() % 10 < 9) ? 2 : 4;
	i = empty[random_index] / 4;
	j = empty[random_index] % 4;
	d->board[i][j] = random_value;
}

int	move_board(t_data *d, int key)
{
	int	backup[4][4];
	int	i;
	int	j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			backup[i][j] = d->board[i][j];
			j++;
		}
		i++;
	}
	if (key == KEY_UP)
		move_up(d);
	else if (key == KEY_DOWN)
		move_down(d);
	else if (key == KEY_LEFT)
		move_left(d);
	else if (key == KEY_RIGHT)
		move_right(d);
	else
		return (0);
	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (backup[i][j] != d->board[i][j])
			{
				spawn_tile(d);
				if (!d->won && has_win(d))
				{
					d->won = true;
					return (2);
				}
				if (!has_move(d))
					return (-1);
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}
