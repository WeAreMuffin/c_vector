/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaubin <aaubin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/13 00:54:38 by aaubin            #+#    #+#             */
/*   Updated: 2014/02/13 00:55:00 by aaubin           ###   ########.fr       */
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

void			test(char *test, int assertion)
{
	printf("Testing %-60s", test);
	assertion ? printf("\e[32m✓\e[0m") : printf("\e[31mFAIL\e[0m");
	printf("\n");
	assert(assertion);
}

int				main(void)
{
	t_vector	*v;
	t_car		*c;
	t_car		*sec;

	// create a new vector tests
	v = new_vector(sizeof(t_car), NULL);
	test("Creating a new vector<t_car>", (v != NULL));

	c = create_car(4, 5, 150, 0xFFFFFF);
	sec = create_car(0, 0, 0, 0);
	assert(c != NULL && sec != NULL);


	// Push tests
	v->push(c, v);
	test("Pushing a first t_car element", (v->count == 1));
	assert(v->elt_size == sizeof(t_car));

	c = create_car(2, 0, 100, 0xffccaa);
	assert(c != NULL);
	v->push(c, v);
	test("Pushing a second t_car element", (v->count == 2));

	c = create_car(1, 0, 10, 0xffffaa);
	assert(c != NULL);
	v->push(c, v);
	test("Pushing a 3th t_car element", (v->count == 3));

	c = create_car(8, 3, 150, 0xffffaa);
	assert(c != NULL);
	v->push(c, v);
	test("Pushing a 4th t_car element", (v->count == 4));


	// Pop tests
	v->pop(sec, v);
	test("Popping the last (4th) element", (sec != NULL && sec->wheels == 8));
	v->pop(sec, v);
	test("Popping the last (3th) element", (sec != NULL && sec->wheels == 1));
	v->pop(sec, v);
	test("Popping the last (2th) element", (sec != NULL && sec->wheels == 2));

	// Repush tests
	c = create_car(50, 3, 150, 0xffffaa);
	assert(c != NULL);
	v->push(c, v);
	test("Pushing a 2th t_car element with 50 wheels", (v->count == 2));

	// Remove tests
	v->free(v);
	test("Cleaning up the vector", (v->count == 0 && v->content = NULL));

	return (0);
}
