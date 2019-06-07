/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wu_flags_init_def_values.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/06 13:49:49 by tmaluh            #+#    #+#             */
/*   Updated: 2019/06/07 09:51:18 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wu_flags.h"

inline void	wu_init_flags_def_values(Flags *restrict const f) {
	*f = (Flags){DEF_MAX_LINE_LEN, DEF_LINES_COUNTER, false, false};
}
