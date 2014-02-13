/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_vector_remove.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaubin <aaubin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/13 18:40:23 by aaubin            #+#    #+#             */
/*   Updated: 2014/02/13 18:40:37 by aaubin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "c_vector.h"

void			c_vector_free(t_vector *self)
{
	size_t		i;

	i = 0;
	if (self->delete_function != NULL)
	{
		while (i < self->count)
		{
			self->delete_function(VECTOR_INDEX(i));
			i++;
		}
	}
	self->count = 0;
	self->capacity = 0;
	free(self->content);
	self->content = NULL;
}

int				c_vector_remove(size_t i, t_vector *self)
{
	if (i > 0)
	{
		if (!VECTOR_INBOUNDS(i))
			return (0);
		c_vector_memmove(VECTOR_INDEX(i), VECTOR_INDEX(i + 1), self->elt_size);
		self->count--;
		return (1);
	}
	else
	{
		return (0);
	}
}
