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

void			vector_free(t_vector *self)
{
	size_t i;

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
