/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wu_algo.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/05 18:17:12 by tmaluh            #+#    #+#             */
/*   Updated: 2019/06/05 20:06:43 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WU_ALGO_H
# define WU_ALGO_H

# include "wu_algo_macroses.h"
# include "wu_algo_structs.h"
# include <stdbool.h>
# include <unistd.h>
# include <stdarg.h>

bool	sdl_init(Sdl *restrict const sdl,
				const char *title,
				const uint16_t w,
				const uint16_t h);

void	sdl_render_loop(Environment *restrict const env);

void	wu_fps(Time *restrict const fps);

void	wu_free(Environment *restrict env);

#endif
