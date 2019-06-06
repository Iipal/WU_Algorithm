/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wu_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/05 18:55:39 by tmaluh            #+#    #+#             */
/*   Updated: 2019/06/06 14:01:24 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wu_algo.h"

void	wu_free(Environment *restrict env)
{
	if (env)
	{
		FREE(env->line_starts, free);
		FREE(env->line_ends, free);
		FREE(env->sdl.w, SDL_DestroyWindow);
		FREE(env, free);
	}
}
