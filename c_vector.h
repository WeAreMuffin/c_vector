/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_vector.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaubin <aaubin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/12 22:11:51 by aaubin            #+#    #+#             */
/*   Updated: 2014/02/12 22:12:20 by aaubin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef C_VECTOR_H
# define C_VECTOR_H

# include <stdio.h>
# include <stdlib.h>
# include <ctype.h>
# include <string.h>

/*
** the base size
*/
# define VECTOR_INIT_SIZE	4

/*
** a little helper who checks if there is enough space in the current
** vector.
*/
# define VECTOR_SPACE(self)	(((self)->count + 1) <= (self)->capacity)

/*
** check if the given index is into the indexes of the vector
*/
# define VECTOR_INBOUNDS(i)	(((int) i) >= 0 && (i) < (self)->count)

/*
** returns the loaction of the pointer at the given index
*/
# define VECTOR_INDEX(i)	((char *)(self)->content + ((self)->elt_size * (i)))

typedef struct			s_vector
{
	size_t				count;
	size_t				capacity;
	void				*content;
	size_t				elt_size;
	int					(*push)(void *, struct s_vector *);
	void				(*pop)(void *, struct s_vector *);
	void				(*delete_function)(void *);
}						t_vector;

t_vector				*new_vector(size_t elt_size, void (*_delete)(void *));

/*
** memory helpers
*/
void					*ft_realloc(void *ptr, size_t old, size_t size);
void					*ft_memcpy(void *s1, const void *s2, size_t n);
void					*ft_memalloc(size_t size);

#endif /* !C_VECTOR_H */
