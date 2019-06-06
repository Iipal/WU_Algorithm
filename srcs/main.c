/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/05 18:16:19 by tmaluh            #+#    #+#             */
/*   Updated: 2019/06/06 11:10:52 by tmaluh           ###   ########.fr       */
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
	wu_randomatic_lines_pos(env->line_starts, env->line_ends);
	sdl_render_loop(env);
	wu_free(env);
}
