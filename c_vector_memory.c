/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_vector_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaubin <aaubin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/13 19:18:02 by aaubin            #+#    #+#             */
/*   Updated: 2014/02/13 19:18:18 by aaubin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

static void		cptb(char *ptr1, char *ptr2, size_t n)
{
	while (n)
	{
		ptr1[n - 1] = ptr2[n - 1];
		--n;
	}
}

static void		cpfw(char *ptr1, char *ptr2, size_t n)
{
	while (n)
	{
		*ptr1 = *ptr2;
		++ptr1;
		++ptr2;
		--n;
	}
}

void			*c_vector_memmove(void *s1, const void *s2, size_t n)
{
	char	*ptr1;
	char	*ptr2;

	ptr1 = (char *)s1;
	ptr2 = (char *)s2;
	if (ptr1 > ptr2)
		cptb(ptr1, ptr2, n);
	else
		cpfw(ptr1, ptr2, n);
	return (s1);
}
