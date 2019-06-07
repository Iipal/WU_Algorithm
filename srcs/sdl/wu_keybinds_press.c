/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wu_keybinds_press.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/06 11:09:19 by tmaluh            #+#    #+#             */
/*   Updated: 2019/06/07 10:13:05 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wu_algo.h"

void	wu_keybinds_press(SDL_Keycode key, Environment *restrict const env) {
	if (SDLK_r == key)
		env->is_re_draw = wu_randomatize_lines_pos(env->line_starts,
			env->line_ends, env->flags.max_line_lenghts,
			env->flags.lines_counter);
}
