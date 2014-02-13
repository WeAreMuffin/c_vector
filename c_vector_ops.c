/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_vector_ops.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaubin <aaubin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/12 22:11:51 by aaubin            #+#    #+#             */
/*   Updated: 2014/02/13 22:47:46 by aleger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "c_vector.h"

static void			vector_extend(size_t size, t_vector *self)
{
	size_t			old_c;

	old_c = self->capacity;
	if (size > self->capacity)
		self->capacity = size;
	else
		self->capacity *= 2;
	self->content = ft_realloc(self->content, old_c,
								self->elt_size * self->capacity);
}

static int			vector_insert(void *elem, size_t index, t_vector *self)
{
	void			*target;

	if ((int)index > -1)
	{
		if (!VECTOR_INBOUNDS(index))
			return (0);
		target = VECTOR_INDEX(index);
	}
	else
	{
		if (!VECTOR_SPACE(self))
			vector_extend(0, self);
		target = VECTOR_INDEX(self->count);
		self->count++;
	}
	ft_memcpy(target, elem, self->elt_size);
	return (1);
}

int					vector_push(void *elem, t_vector *self)
{
	return (vector_insert(elem, -1, self));
}

void				vector_pop(void *elem, t_vector *self)
{
	ft_memcpy(elem, VECTOR_INDEX(self->count - 1), self->elt_size);
	self->count--;
}

void				vector_swap(t_vector *self, int index_1, int index_2)
{
	void			*content_tmp;

	content_tmp = malloc(self->elt_size);
	if (content_tmp)
	{
		ft_memcpy(content_tmp, VECTOR_INDEX(index_1), self->elt_size);
		c_vector_memmove(VECTOR_INDEX(index_1), VECTOR_INDEX(index_2),
				self->elt_size);
		ft_memcpy(VECTOR_INDEX(index_2), content_tmp, self->elt_size);
	}
}
