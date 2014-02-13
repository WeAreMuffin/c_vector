/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaubin <aaubin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/13 00:54:38 by aaubin            #+#    #+#             */
/*   Updated: 2014/02/13 18:46:05 by aleger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <assert.h>
#include <stdio.h>
#include "c_vector.h"

typedef struct	s_car
{
	int			wheels;
	int			doors;
	int			max_speed;
	int			color;
}				t_car;

t_car			*create_car(int w, int d, int ms, int c)
{
	t_car		*car;

	car = (t_car *)malloc(sizeof(t_car));
	if (car)
	{
		car->color = c;
		car->doors = d;
		car->max_speed = ms;
		car->wheels = w;
	}
	return (car);
}

void			print_car(t_car *c)
{
	printf("A car wich have %i wheels, %i doors, %x color and who can go up to %i km/h !\n",
		c->wheels, c->doors, c->color, c->max_speed);
}

int				main(void)
{
	t_vector	*v;
	t_car		*c;
	int			i;

	// create a new vector
	v = new_vector(sizeof(t_car), NULL);
	assert(v);

	c = create_car(4, 5, 150, 0xFFFFFF);
	assert(c);

	print_car(c);
	v->push(c, v);
	printf("%d\n", v->size(v));

	c = create_car(2, 0, 100, 0xffccaa);
	assert(c);

	print_car(c);
	v->push(c, v);
	printf("%d\n", v->size(v));

	v->pop(c, v);

	print_car(c);
	v->pop(c, v);
	printf("%d\n", v->size(v));

	print_car(c);
	printf("\n");
	for (i = 0; i < v->size(v); ++i) {
		c = (t_car *)v->at(v, i);
		print_car(c);
	}
	printf("\n");
	print_car((t_car *)v->front(v));
	printf("\n");
	print_car((t_car *)v->back(v));
	printf("\n%d\n", v->is_empty(v, 20));
	printf("\n%d\n", v->is_empty(v, 2));
	printf("\n%zu\n", v->v_capacity(v));
	return (0);
}
