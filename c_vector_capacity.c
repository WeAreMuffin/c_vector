/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_vector_capacity.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleger <aleger@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/13 16:15:00 by aleger            #+#    #+#             */
/*   Updated: 2014/02/13 19:59:47 by aleger           ###   ########.fr       */
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
	return (self->capacity);
}

int				vector_is_empty(t_vector *self, int request)
{
	return (self->count == 0);
}
