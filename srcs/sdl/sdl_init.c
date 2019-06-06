/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/05 18:20:33 by tmaluh            #+#    #+#             */
/*   Updated: 2019/06/06 22:09:16 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wu_algo.h"

bool	sdl_init(Sdl *restrict const sdl,
				const char *title,
				const uint16_t w,
				const uint16_t h) {
	IF_VAMSG(0 > SDL_Init(SDL_INIT_EVENTS), false, "%s\n", SDL_GetError());
	IF_NOT_VAMSG(sdl->w = SDL_CreateWindow(title,
		SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
		w, h, SDL_WINDOW_SHOWN), false, "%s\n", SDL_GetError());
	IF_NOT_VAMSG(sdl->wsurf = SDL_GetWindowSurface(sdl->w),
		false, "%s\n", SDL_GetError());
	sdl->pxls = (Uint32*)sdl->wsurf->pixels;
	return true;
}
