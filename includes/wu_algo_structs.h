/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wu_algo_structs.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/05 18:27:41 by tmaluh            #+#    #+#             */
/*   Updated: 2019/06/07 09:45:14 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WU_ALGO_STRUCTS_H
# define WU_ALGO_STRUCTS_H

# define MAX_LINES 10

# include <stdbool.h>
# include <SDL2/SDL.h>

typedef struct	s_time {
	float_t	old;
	float_t	current;
	float_t	res;
} Time;

typedef struct	s_sdl {
	SDL_Window	*w;
	SDL_Surface	*wsurf;
	Uint32		*pxls;
	SDL_Event	e;
} Sdl;

typedef struct	s_flags {
	uint32_t	max_line_lenghts;
	uint32_t	lines_counter;
	bool		is_mll;
	bool		is_lc;
} Flags;

typedef struct	s_environment {
	Sdl		sdl;
	Time	fps;
	Flags	flags;
	__v2df	*line_starts;
	__v2df	*line_ends;
} Environment;

#endif
