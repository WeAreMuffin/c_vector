/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_vector.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaubin <aaubin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/12 22:11:51 by aaubin            #+#    #+#             */
/*   Updated: 2014/02/13 22:43:32 by aleger           ###   ########.fr       */
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
# define VECTOR_INDEX(i) ((char *)(self)->content + ((self)->elt_size * (i)))

typedef struct			s_vector
{
	size_t				count;
	size_t				cursor;
	size_t				capacity;
	void				*content;
	size_t				elt_size;
	int					(*push)(void *, struct s_vector *);
	void				(*pop)(void *, struct s_vector *);
	size_t				(*size)(struct s_vector *);
	void				(*free)(struct s_vector *);
	int					(*remove)(size_t, struct s_vector *);
	size_t				(*v_capacity)(struct s_vector *);
	int					(*is_empty)(struct s_vector *);
	void				(*swap)(struct s_vector *, int, int);
	void				*(*at)(struct s_vector *, int);
	void				*(*data)(struct s_vector *, int);
	void				*(*front)(struct s_vector *);
	void				*(*back)(struct s_vector *);
	void				*(*each)(struct s_vector *);
	void				(*map)(struct s_vector *self, void (*fct)(void *elt));
	void				(*delete_function)(void *);
}						t_vector;

t_vector				*new_vector(size_t elt_size, void (*_delete)(void *));

/*
** memory helpers
*/

void					*ft_realloc(void *ptr, size_t old, size_t size);
void					*ft_memcpy(void *s1, const void *s2, size_t n);
void					*ft_memalloc(size_t size);
void					*c_vector_memmove(void *s1, const void *s2, size_t n);

/*
** vector_capacity
*/

size_t					vector_size(t_vector *self);
size_t					vector_capacity(t_vector *self);
int						vector_is_empty(t_vector *self);

/*
** vector_operations
*/

void					vector_swap(t_vector *self, int index_1, int index_2);
void					vector_pop(void *elem, t_vector *self);
int						vector_push(void *elem, t_vector *self);

/*
** vector_access
*/

void					*vector_at(t_vector *self, int request);
void					*vector_front(t_vector *self);
void					*vector_back(t_vector *self);
void					*vector_data(t_vector *self, int request);

/*
** Iterate functions
*/
void					*c_vector_each(t_vector *self);
void					c_vector_map(t_vector *self, void (*fct)(void *elt));

/*
** delete functions
*/

void					c_vector_free(t_vector *self);
int						c_vector_remove(size_t i, t_vector *self);

#endif /* !C_VECTOR_H */
