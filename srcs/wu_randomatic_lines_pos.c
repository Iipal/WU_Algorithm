/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wu_randomatic_lines_pos.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/06 09:16:26 by tmaluh            #+#    #+#             */
/*   Updated: 2019/06/06 13:17:34 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wu_algo.h"

void	wu_randomatic_lines_pos(__v2df starts[], __v2df ends[],
								const uint32_t max_line_lenght)
{
	size_t	i;

	i = ~0UL;
	while (MAX_LINES > ++i)
	{
		starts[i] = (__v2df){u_rand(WIN_X), u_rand(WIN_Y)};
		ends[i] = (__v2df){u_rand(WIN_X), u_rand(WIN_Y)};
		while (u_line_len(starts[i], ends[i]) > max_line_lenght
		&& (starts[i][0] != ends[i][0] || starts[i][1] != ends[i][1]))
			ends[i] = (__v2df){u_rand(WIN_X), u_rand(WIN_Y)};
	}
}
