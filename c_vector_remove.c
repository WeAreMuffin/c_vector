/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_vector_remove.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaubin <aaubin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/13 18:40:23 by aaubin            #+#    #+#             */
/*   Updated: 2014/02/15 05:23:29 by aleger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
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
	int			index;

	index = (int)i;
	if (i > 0)
	{
		if (!VECTOR_INBOUNDS(i))
			return (0);
		while (index < (int)(self->count - 1))
		{
			vector_memcpy(VECTOR_INDEX(index), VECTOR_INDEX(index + 1),
							self->elt_size);
			++index;
		}
		--(self->count);
		return (1);
	}
	else
		return (0);
}
