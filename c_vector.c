/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_vector.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaubin <aaubin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/12 22:11:51 by aaubin            #+#    #+#             */
/*   Updated: 2014/02/13 18:31:48 by aleger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "c_vector.h"

static void			c_vector_extend(size_t size, t_vector *self)
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

static int			c_vector_insert(void *elem, size_t index, t_vector *self)
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
			c_vector_extend(0, self);
		target = VECTOR_INDEX(self->count);
		self->count++;
	}
	ft_memcpy(target, elem, self->elt_size);
	return (1);
}

static int			c_vector_push(void *elem, t_vector *self)
{
	return (c_vector_insert(elem, -1, self));
}

static void			c_vector_pop(void *elem, t_vector *self)
{
	ft_memcpy(elem, VECTOR_INDEX(self->count - 1), self->elt_size);
	self->count--;
}

t_vector			*new_vector(size_t elt_size, void (*_delete)(void *))
{
	t_vector		*v;

	v = (t_vector *)malloc(sizeof(t_vector));
	if (v)
	{
		v->count = 0;
		v->capacity = VECTOR_INIT_SIZE;
		v->content = ft_memalloc(elt_size * v->capacity);
		v->elt_size = elt_size;
		v->pop = c_vector_pop;
		v->push = c_vector_push;
		v->free = c_vector_free;
		v->remove = c_vector_remove;
		v->v_capacity = &vector_capacity;
		v->is_empty = &vector_is_empty;
		v->at = &vector_at;
		v->size = &vector_size;
		v->front = &vector_front;
		v->back = &vector_back;
		v->delete_function = _delete != NULL ? _delete : NULL;
	}
	return (v);
}
