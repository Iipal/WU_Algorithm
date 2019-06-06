/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wu_algo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/06 09:00:31 by tmaluh            #+#    #+#             */
/*   Updated: 2019/06/06 19:10:54 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wu_algo.h"

void	wu_draw_line(const bool steep, const double_t gradient, double_t intery,
	const __v2du pxl1, const __v2du pxl2, Uint32 *restrict const pxls) {
	for (unsigned long long i = pxl1[0] + 1; i < pxl2[0] - 1; i++) {
		if (steep) {
			u_plot(u_ipart(intery)    , i, u_rfpart(intery), pxls);
			u_plot(u_ipart(intery) + 1, i,  u_fpart(intery), pxls);
		} else {
			u_plot(i, u_ipart(intery)    , u_rfpart(intery), pxls);
			u_plot(i, u_ipart(intery) + 1,  u_fpart(intery), pxls);
		}
		intery += gradient;
	}
}

__header_always_inline __v2du
wu_calc_endpoint(__v2df xy, const double_t gradient, const bool steep,
	Uint32 *restrict const pxls) {
	const __v2df	end = { u_round(xy[0]),
		xy[1] + gradient * (u_round(xy[0]) - xy[0]) };
	const double_t	xgap = u_rfpart(xy[0] + 0.5f);
	const __v2du	pxl = {end[0], u_ipart(end[1])};

	if (steep) {
		u_plot(pxl[1]    , pxl[0], u_rfpart(end[1]) * xgap, pxls);
		u_plot(pxl[1] + 1, pxl[0],  u_fpart(end[1]) * xgap, pxls);
	} else {
		u_plot(pxl[0], pxl[1]    , u_rfpart(end[1]) * xgap, pxls);
		u_plot(pxl[0], pxl[1] + 1,  u_fpart(end[1]) * xgap, pxls);
	}
	return pxl;
}

__header_always_inline void
wu_calc_line(__v2df xy0, __v2df xy1, Uint32 *restrict const pxls) {
	const bool	steep = fabs(xy1[1] - xy0[1]) > fabs(xy1[0] - xy0[0]);
	double_t	gradient;

	if (steep) {
		SWAP(xy0[0], xy0[1]);
		SWAP(xy1[0], xy1[1]);
	}
	if (xy0[0] > xy1[0]) {
		SWAP(xy0[0], xy1[0]);
		SWAP(xy0[1], xy1[1]);
	}

	{
		const __v2df	d = {xy1[0] - xy0[0], xy1[1] - xy0[1]};
		gradient = d[1] / d[0];
		if (0.0f == d[0])
			gradient = 1.0;
	}
	wu_draw_line(steep, gradient,
		(xy0[1] + gradient * (u_round(xy0[0]) - xy0[0])) + gradient,
		wu_calc_endpoint(xy0, gradient, steep, pxls),
		wu_calc_endpoint(xy1, gradient, steep, pxls), pxls);
}

void	wu_algo(Environment *restrict const env) {
	size_t	i = ~0UL;

	SDL_FillRect(env->sdl.wsurf, NULL, g_bg_clr.hex);
	while (env->flags.lines_counter > ++i)
		wu_calc_line(env->line_starts[i], env->line_ends[i], env->sdl.pxls);
	SDL_UpdateWindowSurface(env->sdl.w);
}
