/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/05 18:16:19 by tmaluh            #+#    #+#             */
/*   Updated: 2019/06/05 19:12:40 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wu_algo.h"

int		main(void)
{
	Environment	*env;

	IF_NOT_VAMSG(env = (Environment*)malloc(sizeof(Environment)), 0,
		"Can't allocate %zu bytes memory for `env` aka `Environment*`",
		sizeof(Environment));
	IF_NOT_DO(sdl_init(&env->sdl, WIN_TITLE, WIN_X, WIN_Y), wu_free(env), 0);
	sdl_render_loop(env);
}
