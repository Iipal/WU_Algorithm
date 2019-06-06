/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wu_flags_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/06 13:28:33 by tmaluh            #+#    #+#             */
/*   Updated: 2019/06/06 16:49:03 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wu_flags.h"

bool	u_isalpha_str(const char *const str) {
	size_t	i = ~0UL;

	while (str[++i])
		if (!isalpha(str[i]))
			return (false);
	return (true);
}

bool	u_isdigits_str(const char *const str) {
	size_t	i = ~0L;

	while (str[++i])
		if (!isdigit(str[i]))
			return (false);
	return (true);
}

bool	u_is_one_of_str(const char *const cmp,
						const bool cmp_len,
						size_t n, ...) {
	va_list	ap;
	char	*temp;
	bool	is_one_of = false;

	va_start(ap, n);
	while (n-- && !is_one_of) {
		temp = va_arg(ap, char*);
		if (true == cmp_len && !strncmp(cmp, temp, strlen(temp))) {
			is_one_of = true;
			break ;
		} else if (false == cmp_len && !strcmp(cmp, temp)) {
			is_one_of = true;
			break ;
		}
	}
	va_end(ap);
	return (is_one_of);
}
