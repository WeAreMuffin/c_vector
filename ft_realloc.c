/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaubin <aaubin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/12 22:10:00 by aaubin            #+#    #+#             */
/*   Updated: 2014/02/12 22:12:18 by aaubin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "c_vector.h"

static void			ft_bzero(void *s, size_t n)
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

void				*ft_memcpy(void *s1, const void *s2, size_t n)
{
	char			*dp;
	const char		*sp;

	sp = s2;
	dp = s1;
	while (n--)
		*dp++ = *sp++;
	return (s1);
}

static void			ft_memdel(void **ap)
{
	if (ap != NULL)
	{
		free(*ap);
		*ap = NULL;
	}
}

void				*ft_memalloc(size_t size)
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

void					*ft_realloc(void *ptr, size_t old, size_t size)
{
	void				*new;

	if (ptr == NULL)
		return (NULL);
	if (size == 0)
		new = (void *)ft_memalloc(sizeof(char));
	else
		new = (void *)ft_memalloc(size);
	if (new == NULL)
		return (NULL);
	ft_bzero(new, (size) ? size : sizeof(char));
	if (old > size)
		ft_memcpy(new, ptr, (size) ? size : sizeof(char));
	else
		ft_memcpy(new, ptr, old);
	ft_memdel((void *)&ptr);
	return (new);
}
