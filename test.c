/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaubin <aaubin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/13 00:54:38 by aaubin            #+#    #+#             */
/*   Updated: 2014/02/13 20:12:02 by aleger           ###   ########.fr       */
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
	t_car		*t1;
	t_car		*t2;
	int			i;

	// create a new vector tests
	v = new_vector(sizeof(t_car), NULL);
	test("Creating a new vector<t_car>", (v != NULL));

	c = create_car(4, 5, 150, 0xFFFFFF);
	sec = create_car(0, 0, 0, 0);
	assert(c != NULL && sec != NULL);


	// Push tests
	v->push(c, v);
	free(c);
	test("Pushing a first t_car element", (v->count == 1));
	assert(v->elt_size == sizeof(t_car));

	c = create_car(2, 0, 100, 0xffccaa);
	assert(c != NULL);
	v->push(c, v);
	free(c);
	test("Pushing a second t_car element", (v->count == 2));

	c = create_car(1, 0, 10, 0xffffaa);
	assert(c != NULL);
	v->push(c, v);
	free(c);
	test("Pushing a 3th t_car element", (v->count == 3));

	c = create_car(8, 3, 150, 0xffffaa);
	assert(c != NULL);
	v->push(c, v);
	free(c);
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
	free(c);
	test("Pushing a 2th t_car element with 50 wheels", (v->count == 2));

	// RemoveOne tests
	v->remove(1, v);
	test("Removing the (2th) element", (v->count == 1));
	v->pop(sec, v);
	test("Popping the last (1st) element", (sec != NULL && sec->wheels == 4));
	test("Is the vector empty ?", (v->count == 0));

	// Remove tests
	v->free(v);
	test("Cleaning up the vector", (v->count == 0 && v->content == NULL));
	free(v);

	// Memory leaks test loop
	i = 300;
	test("Trying to make a parking of 300 cars", 1);
	while (i)
	{
		v = new_vector(sizeof(t_car), NULL);
		c = create_car(2, 0, 100, 0xffccaa);
		assert(c != NULL);
		v->push(c, v);
		free(c);
		c = create_car(2, 0, 100, 0xffccaa);
		assert(c != NULL);
		v->push(c, v);
		free(c);
		c = create_car(2, 0, 100, 0xffccaa);
		assert(c != NULL);
		v->push(c, v);
		free(c);
		c = create_car(2, 0, 100, 0xffccaa);
		assert(c != NULL);
		v->push(c, v);
		free(c);
		v->pop(sec, v);
		v->pop(sec, v);
		v->remove(1, v);
		v->free(v);
		free(v);
		i--;
		write(1, "-o=o ", 5);
		if (i % 14 == 0)
			write(1, "\n", 1);
	}
	free(sec);

	write(1, "\n\e[37mRun [leaks test_vecor] to check leaks, then press\e[34m Enter \e[0m", 80);
	read(0, NULL, 1);

	/*
	** =========================== END OF AAUBIN TESTS =========================
	*/

	/* Couscous tests */

	printf("\n\n\n================= COUSCOUUUUUUS =====================\n\n");
	// create a new vector
	v = new_vector(sizeof(t_car), NULL);
	assert(v);

	test("Size is 0", v->size(v) == 0);
	c = create_car(4, 0, 150, 0xFFFFFF);
	assert(c);
	t1 = c;

	v->push(c, v);
	test("Size is 1", v->size(v) == 1);

	c = create_car(2, 1, 100, 0xffccaa);
	assert(c);

	v->push(c, v);
	test("Size is 2", v->size(v) == 2);

	c = create_car(5, 2, 380, 0xCACA);
	assert(c);
	t2 = c;

	v->push(c, v);
	test("Size is 3", v->size(v) == 3);


	printf("\n");
	for (i = 0; i < v->size(v); ++i)
	{
		c = (t_car *)v->at(v, i);
		test("Good car", c->doors == i);
	}
	printf("\n");
	test("Front car", t1->doors == ((t_car *)v->front(v))->doors);
	test("Back car", t2->doors == ((t_car *)v->back(v))->doors);

	printf("\n");
	test("Good capacity", v->v_capacity(v) == v->capacity);
	
	v->free(v);
	test("Cleaning up the vector", (v->count == 0 && v->content == NULL));
	return (0);
}
