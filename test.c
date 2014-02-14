/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaubin <aaubin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/13 00:54:38 by aaubin            #+#    #+#             */
/*   Updated: 2014/02/14 16:15:11 by aleger           ###   ########.fr       */
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
	printf("\e[37m▸ Testing \e[0m%-60s", test);
	assertion ? printf("\e[32m✓\e[0m") : printf("\e[31mFAIL\e[0m");
	printf("\n");
	assert(assertion);
}

void			map_function(t_car *elt)
{
	elt->max_speed = 999;
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

	// Iteration tests
	test("[start] Iterate on the t_car elements", 1);
	while ((c = v->each(v)))
	{
		printf("\t - [car %zu] ", v->cursor);
		print_car(c);
	}
	test("[end] Iterate on the t_car elements", (!c && v->cursor == 0));

	// Re-Iteration tests
	test("[start] Re-Iterate on the t_car elements", 1);
	while ((c = v->each(v)))
	{
		printf("\t - [car %zu] ", v->cursor);
		print_car(c);
	}
	test("[end] Re-Iterate on the t_car elements", (!c && v->cursor == 0));

	v->map(v, map_function);
	test("Apply function by mapping on the t_car elements", (v));

	// Re-Iteration after map tests
	test("[start] Re-Iterate after map on the t_car elements", 1);
	while ((c = v->each(v)))
	{
		printf("\t - [car %zu] ", v->cursor);
		print_car(c);
		assert(c->max_speed == 999);
	}
	test("[end] Re-Iterate after map on the t_car elements",
			(!c && v->cursor == 0));

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
	i = 0;
	test("Trying to make a parking of 300 cars", 1);
	write(1, "\n", 1);
	while (i < 299)
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
		i++;
		write(1, " ✩ ", 5);
		if (i % 23 == 0)
			write(1, "\n", 1);
	}
	free(sec);

	write(1, "\n\e[37mRun [leaks test_vector] to check leaks, \
		  then press\e[34m Enter \e[0m", 77);
	read(0, NULL, 1);

	/*
	** =========================== END OF AAUBIN TESTS =========================
	*/

	/* Couscous tests */

//	printf("\n\n\n================= COUSCOUUUUUUS =====================\n\n");
	// create a new vector
	v = new_vector(sizeof(t_car), NULL);
	assert(v);

//	printf("%zu\n", v->size(v));
//	printf("%zu\n", v->count);
	test("Size is 0", v->size(v) == 0);
	c = create_car(4, 0, 150, 0xFFFFFF);
	assert(c);
	t1 = c;

	v->push(c, v);
	free(c);
	test("Size is 1", v->size(v) == 1);

	c = create_car(2, 1, 100, 0xffccaa);
	assert(c);

	v->push(c, v);
	free(c);
	test("Size is 2", v->size(v) == 2);

	c = create_car(5, 2, 380, 0xCACA);
	assert(c);
	t2 = c;

	v->push(c, v);
	free(c);
	test("Size is 3", v->size(v) == 3);


	test("Good capacity", v->v_capacity(v) == v->capacity);

	v->swap(v, 0, 1);
//	printf("%d\n", ((t_car *)v->at(v, 0))->max_speed);
//	printf("%d\n", ((t_car *)v->at(v, 1))->max_speed);

	v->swap(v, 0, 1);
//	printf("%d\n", ((t_car *)v->at(v, 0))->max_speed);
//	printf("%d\n", ((t_car *)v->at(v, 1))->max_speed);

	c = v->data(v, 0);
	c->max_speed = 600;
//	printf("c: %d at: %d\n", c->max_speed, ((t_car *)v->at(v, 0))->max_speed);

	v->free(v);
	test("Cleaning up the vector", (v->count == 0 && v->content == NULL));
	(void)sec;
	(void)i;

	printf("\n\t\t\e[32m====\tOkay ! All seems works well !\t====\e[0m\n");
	return (0);
}
