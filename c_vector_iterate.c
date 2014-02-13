/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_vector_iterate.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaubin <aaubin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/13 21:48:38 by aaubin            #+#    #+#             */
/*   Updated: 2014/02/13 21:48:52 by aaubin           ###   ########.fr       */
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
	return (self->at(self, pos));
}
