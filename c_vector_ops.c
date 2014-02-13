/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_vector_ops.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaubin <aaubin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/12 22:11:51 by aaubin            #+#    #+#             */
/*   Updated: 2014/02/13 22:11:52 by aleger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "c_vector.h"

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
