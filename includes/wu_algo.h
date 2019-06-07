/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wu_algo.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/05 18:17:12 by tmaluh            #+#    #+#             */
/*   Updated: 2019/06/07 10:13:27 by tmaluh           ###   ########.fr       */
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

size_t	u_rand(size_t limit);

bool	sdl_init(Sdl *restrict const sdl,
				const char *title,
				const uint16_t w,
				const uint16_t h);
bool	wu_randomatize_lines_pos(__v2df starts[], __v2df ends[],
				const uint32_t max_line_lenght,
				const uint32_t max_lines_counter);

void	sdl_render_loop(Environment *restrict const env);
void	wu_keybinds_press(SDL_Keycode key, Environment *restrict const env);

void	wu_algo(Environment *restrict const env);

void	wu_free(Environment *restrict env);

#endif
