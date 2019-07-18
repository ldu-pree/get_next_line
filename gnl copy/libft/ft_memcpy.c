/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldu-pree <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/23 17:08:49 by ldu-pree          #+#    #+#             */
/*   Updated: 2019/05/28 10:57:15 by ldu-pree         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *restrict s1, const void *restrict s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (s1 == '\0' && s2 == '\0')
			break ;
		((char*)s1)[i] = ((char*)s2)[i];
		i++;
	}
	return (s1);
}
