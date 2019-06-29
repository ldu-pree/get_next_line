/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldu-pree <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/23 15:06:37 by ldu-pree          #+#    #+#             */
/*   Updated: 2019/05/23 17:31:21 by ldu-pree         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	size_t	i;
	int		s1_end;

	i = 0;
	while (s1[i])
		i++;
	s1_end = i;
	while (s2[i - s1_end] && i - s1_end < n)
	{
		s1[i] = s2[i - s1_end];
		i++;
	}
	s1[i] = '\0';
	return (s1);
}
