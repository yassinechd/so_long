/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yachadla <yachadla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 18:03:04 by yass              #+#    #+#             */
/*   Updated: 2023/11/30 22:45:52 by yachadla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	sizes1;
	size_t	sizes2;

	if (!s1 || !s2)
		return (NULL);
	sizes1 = ft_strlen(s1);
	sizes2 = ft_strlen(s2);
	str = (char *)malloc(sizeof(char) * (sizes1 + sizes2 + 1));
	if (!str)
		return (NULL);
	ft_strlcpy(str, s1, sizes1 + 1);
	ft_strlcat(str, s2, sizes1 + sizes2 + 1);
	return (str);
}
