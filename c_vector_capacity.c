/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_vector_capacity.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleger <aleger@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/13 16:15:00 by aleger            #+#    #+#             */
/*   Updated: 2014/02/13 17:50:07 by aleger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "c_vector.h"
#include <stdlib.h>

int				vector_size(t_vector *self)
{
	return (self->count);
}

size_t			vector_capacity(t_vector *self)
{
	return (sizeof(self));
}

int				vector_is_empty(t_vector *self, int request)
{
	return ((VECTOR_INDEX(request)) ? 1 : 0);
}

void			*vector_at(t_vector *self, int request)
{
	return (VECTOR_INDEX(request));
}
