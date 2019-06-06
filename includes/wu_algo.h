/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wu_algo.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/05 18:17:12 by tmaluh            #+#    #+#             */
/*   Updated: 2019/06/06 10:36:56 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WU_ALGO_H
# define WU_ALGO_H

# include "wu_algo_macroses.h"
# include "wu_algo_structs.h"
# include "wu_algo_colors.h"
# include "wu_algo_utils.h"

# include <stdbool.h>
# include <unistd.h>
# include <stdarg.h>
# include <fcntl.h>

bool	sdl_init(Sdl *restrict const sdl,
				const char *title,
				const uint16_t w,
				const uint16_t h);
void	wu_init_lines_pos(__v2df starts[], __v2df ends[]);

void	sdl_render_loop(Environment *restrict const env);

void	wu_algo(Environment *restrict const env);

void	wu_fps(Time *restrict const fps);

size_t	u_rand(size_t limit);

void	wu_free(Environment *restrict env);

#endif
