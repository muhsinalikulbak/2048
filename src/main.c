/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhsin <muhsin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/12 11:21:07 by muhsin            #+#    #+#             */
/*   Updated: 2026/11/15 21:05:41 by muhsin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/game_loop.h"
#include "../libft/libft.h"
#include "../inc/draw.h"

int	main(void)
{
	t_data	d;

	if (draw_init(&d) == 1)
	{
		ft_putendl_fd("Color is unsupported", 2);
		return (1);
	}
	game_loop(&d);
	endwin();
	return (0);
}
