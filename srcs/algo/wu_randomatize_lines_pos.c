/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wu_randomatize_lines_pos.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/06 09:16:26 by tmaluh            #+#    #+#             */
/*   Updated: 2019/06/07 10:12:15 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wu_algo.h"

bool	wu_randomatize_lines_pos(__v2df starts[], __v2df ends[],
								const uint32_t max_line_lenght,
								const uint32_t max_lines_counter) {
	size_t	i = ~0UL;

	while (max_lines_counter > ++i) {
		starts[i]   = (__v2df){ u_rand(WIN_X), u_rand(WIN_Y) };
		ends[i]     = (__v2df){ u_rand(WIN_X), u_rand(WIN_Y) };
		while (u_line_len(starts[i], ends[i]) > max_line_lenght
		&& (starts[i][0] != ends[i][0] || starts[i][1] != ends[i][1]))
			ends[i] = (__v2df){ u_rand(WIN_X), u_rand(WIN_Y) };
	}
	return true;
}
