/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl_render_loop.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/05 19:01:50 by tmaluh            #+#    #+#             */
/*   Updated: 2019/06/06 16:47:01 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wu_algo.h"

void	sdl_render_loop(Environment *restrict const env) {
	bool	quit;

	quit = false;
	while (!quit) {
		printf("%f\n", env->fps.res * 1000);
		while (SDL_PollEvent(&env->sdl.e) > 0)
			if (SDL_QUIT == env->sdl.e.type)
				quit = true;
			else if (SDL_KEYDOWN == env->sdl.e.type) {
				if (SDLK_ESCAPE == env->sdl.e.key.keysym.sym)
					quit = true;
				else
					wu_keybinds_press(env->sdl.e.key.keysym.sym, env);
			}
		wu_algo(env);
		wu_fps(&env->fps);
	}
}
