/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wu_algo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/06 09:00:31 by tmaluh            #+#    #+#             */
/*   Updated: 2019/06/06 12:06:21 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wu_algo.h"

__header_always_inline __v2du
wu_calc_endpoint(__v2df xy, const double_t gradient, const bool steep,
	SDL_Surface *restrict const surf)
{
	const __v2df	end = { u_round(xy[0]),
		xy[1] + gradient * (u_round(xy[0]) - xy[0]) };
	const double_t	xgap = u_rfpart(xy[0] + 0.5f);
	const __v2du	pxl = {end[0], u_ipart(end[1])};

	if (steep)
	{
		u_plot(pxl[1]    , pxl[0], u_rfpart(end[1]) * xgap, surf);
		u_plot(pxl[1] + 1, pxl[0],  u_fpart(end[1]) * xgap, surf);
	}
	else
	{
		u_plot(pxl[0], pxl[1]    , u_rfpart(end[1]) * xgap, surf);
		u_plot(pxl[0], pxl[1] + 1,  u_fpart(end[1]) * xgap, surf);
	}
	return (pxl);
}

void	wu_draw_line(__v2df xy0, __v2df xy1, SDL_Surface *restrict const surf)
{
	const bool	steep = fabs(xy1[1] - xy0[1]) > fabs(xy1[0] - xy0[0]);
	double_t	gradient;

	if (steep)
	{
		SWAP(xy0[0], xy0[1]);
		SWAP(xy1[0], xy1[1]);
	}
	if (xy0[0] > xy1[0])
	{
		SWAP(xy0[0], xy1[0]);
		SWAP(xy0[1], xy1[1]);
	}
	{
		const __v2df	d = {xy1[0] - xy0[0], xy1[1] - xy0[1]};
		gradient = d[1] / d[0];
		if (0.0f == d[0])
			gradient = 1.0;
	}

	// handle first endpoint
	const __v2du	pxl1 = wu_calc_endpoint(xy0, gradient, steep, surf);

	double_t intery = (xy0[1] + gradient * (u_round(xy0[0]) - xy0[0]))
					+ gradient;

	// handle second endpoint
	const __v2du	pxl2 = wu_calc_endpoint(xy1, gradient, steep, surf);

	for (unsigned long long i = pxl1[0] + 1; i < pxl2[0] - 1; i++)
	{
		if (steep)
		{
			u_plot(u_ipart(intery)    , i, u_rfpart(intery), surf);
			u_plot(u_ipart(intery) + 1, i,  u_fpart(intery), surf);
		}
		else
		{
			u_plot(i, u_ipart(intery)    , u_rfpart(intery), surf);
			u_plot(i, u_ipart(intery) + 1,  u_fpart(intery), surf);
		}
		intery += gradient;
	}
}

void	wu_algo(Environment *restrict const env)
{
	size_t	i;

	i = ~0UL;
	SDL_FillRect(env->sdl.wsurf, NULL, 0x0);
	while (MAX_LINES > ++i)
		wu_draw_line(env->line_starts[i], env->line_ends[i], env->sdl.wsurf);
	SDL_UpdateWindowSurface(env->sdl.w);
}
