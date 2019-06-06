/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wu_algo_structs.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/05 18:27:41 by tmaluh            #+#    #+#             */
/*   Updated: 2019/06/06 11:04:15 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WU_ALGO_STRUCTS_H
# define WU_ALGO_STRUCTS_H

# define MAX_LINES 10

# include <SDL2/SDL.h>

typedef struct	s_time {
	float_t	old;
	float_t	current;
	float_t	res;
	float_t	ms;
	float_t	fps;
}				Time;

typedef struct	s_sdl {
	SDL_Window	*w;
	SDL_Surface	*wsurf;
	uint32_t	*pxls;
	SDL_Event	e;
}				Sdl;

typedef struct	s_environment {
	Sdl		sdl;
	Time	fps;
	__v2df	line_starts[MAX_LINES];
	__v2df	line_ends[MAX_LINES];
}				Environment;

#endif
