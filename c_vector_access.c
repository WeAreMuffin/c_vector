/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_vector_access.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleger <aleger@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/13 17:56:41 by aleger            #+#    #+#             */
/*   Updated: 2014/02/13 18:35:44 by aleger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "c_vector.h"

void			*vector_at(t_vector *self, int request)
{
	return (VECTOR_INDEX(request));
}

void			*vector_front(t_vector *self)
{
	return (VECTOR_INDEX(0));
}

void			*vector_back(t_vector *self)
{
	return (VECTOR_INDEX(self->size(self)));
}
