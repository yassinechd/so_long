/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yachadla <yachadla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 18:03:15 by yass              #+#    #+#             */
/*   Updated: 2023/11/29 15:41:54 by yachadla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*cs1;
	unsigned char	*cs2;

	cs1 = (unsigned char *)s1;
	cs2 = (unsigned char *)s2;
	while (n > 0 && (*cs1 == *cs2))
	{
		if (*cs1 == '\0')
			return (*cs1 - *cs2);
		cs1++;
		cs2++;
		n--;
	}
	if (n)
		return (*cs1 - *cs2);
	return (0);
}
