/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   u_rand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/06 09:02:39 by tmaluh            #+#    #+#             */
/*   Updated: 2019/06/06 18:16:49 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wu_algo.h"

size_t	u_rand(size_t limit) {
	size_t			ponies;
	const int32_t	fd = open("/dev/urandom", O_RDONLY);

	if (0 < fd) {
		read(fd, &ponies, sizeof(size_t));
		close(fd);
		return ponies % limit;
	}
	return 0UL;
}
