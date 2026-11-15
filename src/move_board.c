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

static int	process_line(int line[4], t_data *d)
{
	int	temp[4];
	int	i;
	int	j;
	int	changed;

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
	changed = 0;
	while (i < 3)
	{
		if (temp[i] != 0 && temp[i] == temp[i + 1])
		{
			temp[i] *= 2;
			d->score += temp[i];
			temp[i + 1] = 0;
			changed = 1;
		}
		i++;
	}
	i = 0;
	j = 0;
	while (i < 4)
	{
		if (temp[i] != 0)
		{
			line[j] = temp[i];
			j++;
		}
		i++;
	}
	while (j < 4)
	{
		line[j] = 0;
		j++;
	}
	return (changed);
}

int	move_left(t_data *d)
{
	int	i;
	int	changed;

	i = 0;
	changed = 0;
	while (i < 4)
	{
		if (process_line(d->board[i], d))
			changed = 1;
		i++;
	}
	return (changed);
}

int	move_right(t_data *d)
{
	int	i;
	int	j;
	int	line[4];
	int	changed;

	i = 0;
	changed = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			line[j] = d->board[i][3 - j];
			j++;
		}
		if (process_line(line, d))
			changed = 1;
		j = 0;
		while (j < 4)
		{
			d->board[i][3 - j] = line[j];
			j++;
		}
		i++;
	}
	return (changed);
}

int	move_up(t_data *d)
{
	int	i;
	int	j;
	int	line[4];
	int	changed;

	j = 0;
	changed = 0;
	while (j < 4)
	{
		i = 0;
		while (i < 4)
		{
			line[i] = d->board[i][j];
			i++;
		}
		if (process_line(line, d))
			changed = 1;
		i = 0;
		while (i < 4)
		{
			d->board[i][j] = line[i];
			i++;
		}
		j++;
	}
	return (changed);
}

int	move_down(t_data *d)
{
	int	i;
	int	j;
	int	line[4];
	int	changed;

	j = 0;
	changed = 0;
	while (j < 4)
	{
		i = 0;
		while (i < 4)
		{
			line[i] = d->board[3 - i][j];
			i++;
		}
		if (process_line(line, d))
			changed = 1;
		i = 0;
		while (i < 4)
		{
			d->board[3 - i][j] = line[i];
			i++;
		}
		j++;
	}
	return (changed);
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
