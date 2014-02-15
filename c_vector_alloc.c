/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaubin <aaubin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/12 22:10:00 by aaubin            #+#    #+#             */
/*   Updated: 2014/02/15 05:24:16 by aleger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "c_vector.h"

static void			vector_bzero(void *s, size_t n)
{
	char			*t;

	if (n)
	{
		t = s;
		while (n)
		{
			*t++ = 0;
			n--;
		}
	}
}

void				*vector_memcpy(void *s1, const void *s2, size_t n)
{
	char			*dp;
	const char		*sp;

	sp = s2;
	dp = s1;
	while (n--)
		*dp++ = *sp++;
	return (s1);
}

static void			vector_memdel(void **ap)
{
	if (ap != NULL)
	{
		free(*ap);
		*ap = NULL;
	}
}

void				*vector_memalloc(size_t size)
{
	void				*memory;
	unsigned int		counter;
	char				*explorer;

	counter = 0;
	memory = (void *)malloc(size);
	explorer = (char *)memory;
	if (memory != NULL)
	{
		while (counter++ < size)
			*explorer++ = 0;
	}
	return (memory);
}

void					*vector_realloc(void *ptr, size_t old, size_t size)
{
	void				*new;

	if (ptr == NULL)
		return (NULL);
	if (size == 0)
		new = (void *)vector_memalloc(sizeof(char));
	else
		new = (void *)vector_memalloc(size);
	if (new == NULL)
		return (NULL);
	vector_bzero(new, (size) ? size : sizeof(char));
	if (old > size)
		vector_memcpy(new, ptr, (size) ? size : sizeof(char));
	else
		vector_memcpy(new, ptr, old);
	vector_memdel((void *)&ptr);
	return (new);
}
