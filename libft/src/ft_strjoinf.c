/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoinf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edcastro <edcastro@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 13:00:33 by edcastro          #+#    #+#             */
/*   Updated: 2023/11/15 22:52:45 by edcastro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

static char	*ft_strcat(char *dest, char *src)
{
	unsigned int	i;
	unsigned int	dest_len;

	dest_len = ft_strlen(dest);
	i = 0;
	while (src[i] != '\0')
	{
		dest[dest_len + i] = src[i];
		i++;
	}
	dest[dest_len + i] = '\0';
	return (dest);
}

char	*ft_strjoinf(char const *s1, char const *s2)
{
	int		len;
	char	*strs;

	if (s1 == 0)
		return (0);
	len = ft_strlen(s1) + ft_strlen(s2);
	strs = ft_calloc(len + 1, sizeof(char));
	if (strs == NULL)
		return (NULL);
	strs = ft_strcat(strs, (char *)s1);
	strs = ft_strcat(strs, (char *)s2);
	free((void *)s1);
	return (strs);
}