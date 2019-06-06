/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wu_algo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/06 09:00:31 by tmaluh            #+#    #+#             */
/*   Updated: 2019/06/06 10:25:41 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wu_algo.h"

# define COLOR_MAX  255
# define COLOR_MIN  0

# define INRANGE(c)	((COLOR_MAX < (c)) \
	? COLOR_MAX : ((COLOR_MIN > (c)) \
		? COLOR_MIN : (c)))

typedef struct	s_clr
{
	uint8_t	r;
	uint8_t	g;
	uint8_t	b;
}	t_clr;

typedef union	u_color
{
	uint32_t	hex;
	t_clr		c;
}	Color;

inline Color	sdl_clrs_bright_inc(Color clr1,
								const Color clr2,
								const float_t percent)
{
	Color	out;

	out = clr1;
	if (.0f < percent)
		out.c = (t_clr){INRANGE(clr1.c.r + (clr2.c.r * percent)),
						INRANGE(clr1.c.g + (clr2.c.g * percent)),
						INRANGE(clr1.c.b + (clr2.c.b * percent))};
	return (out);
}

inline void		u_plot(unsigned long long x, unsigned long long y,
	double_t c, SDL_Surface *restrict const surf)
{
	Uint32 *restrict const	pxls = (Uint32 *restrict const)surf->pixels;

	if (x && y && WIN_X > x && WIN_Y > y)
		if (0.0f <= c && 1.0f >= c)
			pxls[y * surf->w + x] =
				sdl_clrs_bright_inc(CLR_BLACK, CLR_WHITE, c * 100.0f).hex;
}

inline double_t	u_ipart(double_t x) { return (floor(x)); }
inline double_t	u_round(double_t x) { return (u_ipart(x + 0.5f)); }
inline double_t	u_fpart(double_t x) { return (x - floor(x)); }
inline double_t	u_rfpart(double_t x) { return (1 - u_fpart(x)); }

void	wu_draw_line(__v2df xy0, __v2df xy1, SDL_Surface *restrict const surf)
{
	const bool	steep = fabs(xy1[1] - xy0[1]) > fabs(xy1[0] - xy0[0]);
	__v2df		d;
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
	d = (__v2df){xy1[0] - xy0[0], xy1[1] - xy0[1]};
	gradient = d[1] / d[0];
	if (0.0f == d[0])
		gradient = 1.0;

	//handle first endpoint
	const __v2df	end0 = {u_round(xy0[0]),
		xy0[1] + gradient * (u_round(xy0[0]) - xy0[0])};
	const double_t	xgap0 = u_rfpart(xy0[0] + 0.5f);
	const __v2du	pxl1 = {end0[0], u_ipart(end0[1])};

	if (steep)
	{
		u_plot(pxl1[1]    , pxl1[0], u_rfpart(end0[1]) * xgap0, surf);
		u_plot(pxl1[1] + 1, pxl1[0],  u_fpart(end0[1]) * xgap0, surf);
	}
	else
	{
		u_plot(pxl1[0], pxl1[1]    , u_rfpart(end0[1]) * xgap0, surf);
		u_plot(pxl1[0], pxl1[1] + 1,  u_fpart(end0[1]) * xgap0, surf);
	}

	double_t	intery = end0[1] + gradient;

	// handle second endpoint
	const __v2df	end1 = {u_round(xy1[0]),
		xy1[1] + gradient * (u_round(xy1[0]) - xy1[1])};
	const double_t	xgap1 = u_fpart(xy1[0] + 0.5f);
	const __v2du	pxl2 = {end1[0], u_ipart(end1[1])};

	if (steep)
	{
		u_plot(pxl2[1]    , pxl2[0], u_rfpart(end1[1]) * xgap1, surf);
		u_plot(pxl2[1] + 1, pxl2[0],  u_fpart(end1[1]) * xgap1, surf);
	}
	else
	{
		u_plot(pxl2[0], pxl2[1]    , u_rfpart(end1[1]) * xgap1, surf);
		u_plot(pxl2[0], pxl2[1] + 1,  u_fpart(end1[1]) * xgap1, surf);
	}

	if (steep)
		for (unsigned long long i = pxl1[0] + 1; i < pxl2[0] - 1; i++)
		{
			u_plot(u_ipart(intery)    , i, u_rfpart(intery), surf);
			u_plot(u_ipart(intery) + 1, i,  u_fpart(intery), surf);
			intery += gradient;
		}
	else
		for (unsigned long long i = pxl1[0] + 1; i < pxl2[0] - 1; i++)
		{
			u_plot(i, u_ipart(intery)    , u_rfpart(intery), surf);
			u_plot(i, u_ipart(intery) + 1,  u_fpart(intery), surf);
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
