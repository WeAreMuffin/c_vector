/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_vector_iterate.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaubin <aaubin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/13 21:48:38 by aaubin            #+#    #+#             */
/*   Updated: 2014/02/15 02:07:41 by aleger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "c_vector.h"

void			*c_vector_each(t_vector *self)
{
	int			pos;

	if (self->cursor >= self->count)
	{
		self->cursor = 0;
		return (NULL);
	}
	pos = self->cursor;
	self->cursor++;
	return (self->data(self, pos));
}

void			c_vector_map(t_vector *self, void (*fct)(void *elt))
{
	int			pos;

	pos = 0;
	while (pos < (int)self->count)
	{
		fct(self->data(self, pos));
		pos++;
	}
}

void			vector_pop_front(void *elem, t_vector *self)
{
	static int	index = 0;

	if (index >= (int)self->count)
	{
		index = 0;
		return ;
	}
	vector_memcpy(elem, VECTOR_INDEX(index), self->elt_size);
	++index;
}

int				vector_push_front(void *elem, t_vector *self)
{
	if (self->push(elem, self))
	{
		c_vector_memmove(VECTOR_INDEX(1), VECTOR_INDEX(0),
						self->elt_size * (self->count - 1));
		vector_memcpy(VECTOR_INDEX(0), elem, self->elt_size);
		return (1);
	}
	return (0);
}
