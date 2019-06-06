/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wu_fps.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/05 20:02:17 by tmaluh            #+#    #+#             */
/*   Updated: 2019/06/06 16:47:04 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wu_algo.h"

void	wu_fps(Time *restrict const fps) {
	fps->old = fps->current;
	fps->current = SDL_GetTicks();
	fps->res = (fps->current - fps->old) / 1000.0f;
}
