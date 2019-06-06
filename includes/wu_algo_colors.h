/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wu_algo_colors.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/06 10:28:45 by tmaluh            #+#    #+#             */
/*   Updated: 2019/06/06 19:14:30 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WU_ALGO_COLORS_H
# define WU_ALGO_COLORS_H

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
	RGB		c;
}	Color;

__header_always_inline Color
clrs_bright_inc(Color clr1, const Color clr2, const float_t percent) {
	Color	out;

	out = clr1;
	if (.0f < percent)
		out.c = (RGB) { INRANGE(clr1.c.r + (clr2.c.r * percent)),
						INRANGE(clr1.c.g + (clr2.c.g * percent)),
						INRANGE(clr1.c.b + (clr2.c.b * percent)) };
	return (out);
}

#endif
