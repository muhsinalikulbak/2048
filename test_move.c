#include "inc/game_loop.h"
#include "inc/move_board.h"
#include <stdio.h>
#include <string.h>

static void	set_line(t_data *d, int dir, int i, int v[4])
{
	int	k;

	k = 0;
	while (k < 4)
	{
		if (dir == 0) // left
			d->board[i][k] = v[k];
		else if (dir == 1) // right
			d->board[i][3 - k] = v[k];
		else if (dir == 2) // up
			d->board[k][i] = v[k];
		else if (dir == 3) // down
			d->board[3 - k][i] = v[k];
		k++;
	}
}

static void	get_line(t_data *d, int dir, int i, int v[4])
{
	int	k;

	k = 0;
	while (k < 4)
	{
		if (dir == 0) // left
			v[k] = d->board[i][k];
		else if (dir == 1) // right
			v[k] = d->board[i][3 - k];
		else if (dir == 2) // up
			v[k] = d->board[k][i];
		else if (dir == 3) // down
			v[k] = d->board[3 - k][i];
		k++;
	}
}

static int	check_line(int got[4], int expected[4])
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (got[i] != expected[i])
			return (0);
		i++;
	}
	return (1);
}

static int	check_others_zero(t_data *d, int dir, int i)
{
	int	j;
	int	k;

	j = 0;
	while (j < 4)
	{
		if (j != i)
		{
			k = 0;
			while (k < 4)
			{
				if (dir == 0 || dir == 1)
				{
					if (d->board[j][k] != 0)
						return (0);
				}
				else
				{
					if (d->board[k][j] != 0)
						return (0);
				}
				k++;
			}
		}
		j++;
	}
	return (1);
}

static void	reset_board(t_data *d)
{
	int	i;
	int	j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			d->board[i][j] = 0;
			j++;
		}
		i++;
	}
	d->score = 0;
	d->won = false;
}

static int	run_test(t_data *d, int dir, int line_idx, int input[4], int expected[4], int expected_score, int expected_ret, const char *dir_name)
{
	int	got[4];
	int	ret;
	int	failures;

	reset_board(d);
	set_line(d, dir, line_idx, input);
	if (dir == 0)
		ret = move_left(d);
	else if (dir == 1)
		ret = move_right(d);
	else if (dir == 2)
		ret = move_up(d);
	else if (dir == 3)
		ret = move_down(d);
	get_line(d, dir, line_idx, got);
	failures = 0;
	if (!check_line(got, expected))
	{
		printf("FAIL %s line %d: input [%d %d %d %d] expected [%d %d %d %d] got [%d %d %d %d]\n",
			dir_name, line_idx, input[0], input[1], input[2], input[3],
			expected[0], expected[1], expected[2], expected[3],
			got[0], got[1], got[2], got[3]);
		failures++;
	}
	if (d->score != expected_score)
	{
		printf("FAIL %s line %d: score expected %d got %d\n",
			dir_name, line_idx, expected_score, d->score);
		failures++;
	}
	if (ret != expected_ret)
	{
		printf("FAIL %s line %d: return expected %d got %d\n",
			dir_name, line_idx, expected_ret, ret);
		failures++;
	}
	if (!check_others_zero(d, dir, line_idx))
	{
		printf("FAIL %s line %d: other lines not zero\n",
			dir_name, line_idx);
		failures++;
	}
	return (failures);
}

int	main(void)
{
	t_data	d;
	int	failures;
	int	dir;
	int	line_idx;
	const char	*dir_names[] = {"left", "right", "up", "down"};

	// Test cases: input, expected, score, return
	int	cases[][10] = {
		{2, 2, 4, 0, 4, 4, 0, 0, 4, 1},
		{2, 2, 2, 2, 4, 4, 0, 0, 8, 1},
		{0, 2, 0, 2, 4, 0, 0, 0, 4, 1},
		{2, 0, 0, 2, 4, 0, 0, 0, 4, 1},
		{4, 4, 8, 8, 8, 16, 0, 0, 24, 1},
		{2, 4, 2, 4, 2, 4, 2, 4, 0, 0},
		{2, 4, 8, 16, 2, 4, 8, 16, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 2, 2, 0, 0, 0, 0, 1}
	};
	int	num_cases;
	int	case_idx;

	num_cases = sizeof(cases) / sizeof(cases[0]);
	failures = 0;
	dir = 0;
	while (dir < 4)
	{
		line_idx = 0;
		while (line_idx < 4)
		{
			case_idx = 0;
			while (case_idx < num_cases)
			{
				failures += run_test(&d, dir, line_idx,
					&cases[case_idx][0], &cases[case_idx][4],
					cases[case_idx][8], cases[case_idx][9],
					dir_names[dir]);
				case_idx++;
			}
			line_idx++;
		}
		dir++;
	}
	if (failures == 0)
		printf("ALL PASS\n");
	else
		printf("%d FAILED\n", failures);
	return (failures);
}
