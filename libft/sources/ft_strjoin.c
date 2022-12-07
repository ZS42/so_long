/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsyyida <zsyyida@student42abudhabi.ae>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 11:22:19 by zsyyida           #+#    #+#             */
/*   Updated: 2022/10/04 09:18:03 by zsyyida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char *s1, char const *s2)
{
	char	*join;
	int		i;
	int		j;

	i = -1;
	j = -1;
	if (!s1 || !s2)
	{
		return (NULL);
	}
	join = ft_calloc((ft_strlen(s1) + ft_strlen(s2) + 2), sizeof(char));
	if (!join)
		return (NULL);
	while (s1[++i])
		join[++j] = s1[i];
	join[++j] = ' ';
	if (s1 != NULL)
		ft_free_s(s1);
	i = -1;
	while (s2[++i])
		join[++j] = s2[i];
	join[++j] = '\0';
	return (join);
}
