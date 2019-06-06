/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wu_algo_utils.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/06 10:34:15 by tmaluh            #+#    #+#             */
/*   Updated: 2019/06/06 10:35:51 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WU_ALGO_UTILS_H
# define WU_ALGO_UTILS_H

# include "wu_algo_macroses.h"
# include "wu_algo_colors.h"
# include <SDL2/SDL.h>

__header_always_inline void
u_plot(unsigned long long x, unsigned long long y,
	double_t c, SDL_Surface *restrict const surf) {
	Uint32 *restrict const	pxls = (Uint32 *restrict const)surf->pixels;

	if (x && y && WIN_X > x && WIN_Y > y)
		if (0.0f <= c && 1.0f >= c)
			pxls[y * surf->w + x] =
				clrs_bright_inc(CLR_BLACK, CLR_WHITE, c).hex;
}

__header_always_inline double_t
u_ipart(double_t x) { return (floor(x)); }

__header_always_inline double_t
u_round(double_t x) { return (u_ipart(x + 0.5f)); }

__header_always_inline double_t
u_fpart(double_t x) { return (x - floor(x)); }

__header_always_inline double_t
u_rfpart(double_t x) { return (1 - u_fpart(x)); }

#endif