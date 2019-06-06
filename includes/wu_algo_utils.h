/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wu_algo_utils.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/06 10:34:15 by tmaluh            #+#    #+#             */
/*   Updated: 2019/06/06 22:39:11 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WU_ALGO_UTILS_H
# define WU_ALGO_UTILS_H

# include "wu_algo_macroses.h"
# include "wu_algo_colors.h"

__wu_always_inline double_t
u_ipart(double_t x) { return floor(x); }

__wu_always_inline double_t
u_round(double_t x) { return u_ipart(x + 0.5f); }

__wu_always_inline double_t
u_fpart(double_t x) { return x - floor(x); }

__wu_always_inline double_t
u_rfpart(double_t x) { return 1 - u_fpart(x); }

// formula for finding the length of the segment in two-dimensional coordinates
//	A = √(X²+Y²) = √((X2-X1)²+(Y2-Y1)²).
__wu_always_inline double_t
u_line_len(__v2df start, __v2df end) {
	const double_t	x = end[0] - start[0];
	const double_t	y = end[1] - start[1];

	return sqrt((x * x) + (y * y));
}

#endif
