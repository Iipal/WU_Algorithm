/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wu_algo_colors.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/06 10:28:45 by tmaluh            #+#    #+#             */
/*   Updated: 2019/06/07 09:52:06 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WU_ALGO_COLORS_H
# define WU_ALGO_COLORS_H

# include "wu_algo_macroses.h"
# include <stdint.h>
# include <math.h>

# define COLOR_MAX  255
# define COLOR_MIN  0

# define INRANGE(c)	((COLOR_MAX < (c)) \
	? COLOR_MAX : ((COLOR_MIN > (c)) \
		? COLOR_MIN : (c)))

# define CLR_BLACK (Color){0x0}
# define CLR_WHITE (Color){0xffffff}

typedef struct	s_rgb {
	uint8_t	r;
	uint8_t	g;
	uint8_t	b;
}	RGB;

typedef union	u_color {
	uint32_t	hex;
	RGB			c;
}	Color;

Color	g_bg_clr;
bool	g_is_bgc;
Color	g_fg_clr;
bool	g_is_fgc;

__wu_always_inline Color
clrs_bright_inc(Color clr1, const Color clr2, const float_t percent) {
	Color	out = clr1;

	if (.0f < percent)
		out.c = (RGB) { INRANGE(clr1.c.r + (clr2.c.r * percent)),
						INRANGE(clr1.c.g + (clr2.c.g * percent)),
						INRANGE(clr1.c.b + (clr2.c.b * percent)) };
	return (out);
}

__wu_always_inline void
putpxl_plot(const uint64_t x, const uint64_t y,
	const double_t c, Uint32 *restrict const pxls) {

	if (0.0f <= c && 1.0f >= c)
		if (x && y && WIN_X > x && WIN_Y > y) {
			Color	pxl_clr = clrs_bright_inc(CLR_BLACK, g_fg_clr, c);
			Color	orig = {pxls[y * WIN_X + x]};
			if (1.0f > c && orig.hex)
				pxl_clr = clrs_bright_inc(pxl_clr, orig, 1.0f - c);
			pxls[y * WIN_X + x] = pxl_clr.hex;
		}
}

#endif
