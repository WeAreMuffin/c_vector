c_vector
========

A simple vector-like struct in C

# Introduction aux vecteurs

Il existe en C++ une classe [**vector**][vector]. Cette classe permet de stocker des &eacute;l&eacute;ments de n'importe quel type.


> A l'inverse des vecteurs en math&eacute;matiques, les vecteurs en langage de programmation sont simplement des tableaux d'&eacute;l&eacute;ments.

Ils permettent de ne plus avoir &agrave; se soucier de la gestion de la m&eacute;moire, et cette classe dispose de nombreuse m&eacute;thodes pour manipuler les &eacute;l&eacute;ments stock&eacute;s.

Afin de rendre nos codes plus propres, nous avons d&eacute;cid&eacute; d'adapter ces fonctions en C. Je vous propose donc de faire un tour rapide sur les fonctions &agrave; disposition avec des exemples simples.

> Vous pouvez bien s&ucirc;r cr&eacute;er vos propres fonctions et, pourquoi pas, les proposer au reste de la communaut&eacute;.

# Utiliser le vecteur

Cette librairie permet seulement d'enregistrer des pointeurs. Utile pour un tableau de structure par exemple.
> Pourquoi ne pas l'utiliser pour lemin ?

La fonction ci-dessous permet de cr&eacute;er un nouveau vecteur. En dessous du prototype sont pr&eacute;sent&eacute;s ses param&egrave;tres ainsi que son utilisation.

```c
t_vector   *new_vector(size_t elt_size, void (*_delete)(void *))
```
Prend 2 param&egrave;tres :
- la taille de la donn&eacute;e (ex: `sizeof(t_muffin)`)
- une fonction destructrice. 

Exemple d'utilisation:

```c
typedef struct   s_exemple
{
    char         *nom;
}                t_exemple;
 
void      fonction_qui_casse_tout(t_exemple *ex)
{
    free(ex->nom);
    free(ex);
}

void    affiche_nom(t_exemple *e)
{
    ft_putstr(e->nom);
}

int         main()
{
    t_vector    *vector;
    t_exemple   *ex;

    ex = (t_exemple *)malloc(sizeof(ex));
    ex->nom = "Super Muffin";
    vector = new_vector(sizeof(ex), &fonction_qui_casse_tout);
    vector->push(ex, vector);
    ft_putstr("Je suis un ");
    vector->map(vector, &affiche_nom);
    return (1);
}
```
> Cet exemple stocke `ex` dans le vecteur et applique la fonction `affiche_nom` &agrave; tous les &eacute;l&eacute;ments du vecteur. On obtiendra donc: 
>  ```c
>  $> Je suis un Super Muffin
>  ```

# Les fonctions du vecteur

Dans les descriptions suivantes, la premi&egrave;re ligne correspond au prototype de la fonction (pour les curieux), la suivante correspond &agrave; son utilisation.
>  Nous devrons passer la r&eacute;f&eacute;rence du pointeur dans chaque fonction, ce qui n'est pas forc&eacute;ment beau mais est le seul moyen d'utilisation.

### empty
Retourne un bool&eacute;en: 1 si le vecteur est `NULL`, 0 si des &eacute;l&eacute;ments sont &agrave; l'int&eacute;rieur.
```c
int		vector_is_empty(t_vector *self);

self->empty(self);
```
>   Vous n'aurez &agrave; utiliser cette fonction que dans de rare cas.

### size
Retourne le nombre d'&eacute;l&eacute;ments stock&eacute;s dans le vecteur.
```c
size_t     vector_size(t_vector *self);

self->size(self);
```

### v_capacity
Retourne la capacit&eacute; de stockage du vecteur.
```c
size_t	vector_capacity(t_vector *self);

self->v_capacity(self);
```
>  Vous n'aurez &agrave; utiliser cette fonction que dans de rare cas.

### swap
Intervertit deux &eacute;l&eacute;ments du vecteur.
```c
void	vector_swap(t_vector *self, int index_1, int index_2);

self->swap(self, 1, 2);
```
>  1 devient donc 2, et 2 devient 1.


### pop
Copie un &eacute;l&eacute;ment du vecteur dans le pointeur &agrave; remplir `elem`, en partant de la fin.
```c
void	vector_pop(void *elem, t_vector *self);

self->pop(ptr, self);
```
>  Correspond &agrave; la m&eacute;thode LIFO (Last In First Out)

### pop_front
Copie un &eacute;l&eacute;ment du vecteur dans le pointeur &agrave; remplir `elem`, en partant du d&eacute;but.
```c
void	vector_pop_front(void *elem, t_vector *self);

self->pop_front(ptr, self);
```
>  Correspond &agrave; la m&eacute;thode FIFO (First In First Out)

### push
Stocke l'&eacute;l&eacute;ment `elem` en derni&egrave;re position du vecteur.
```c
int		vector_push(void *elem, t_vector *self);

self->push(ptr, self);
```
>  Renvoie 0 en cas d'erreur, 1 si tout va bien.

### push_front
Stocke l'&eacute;l&eacute;ment `elem` en premi&egrave;re position du vecteur.
```c
int		vector_push_front(void *elem, t_vector *self);

self->push_front(ptr, self);
```
>  Les anciens &eacute;l&eacute;ments seront donc d&eacute;cal&eacute;s sur la droite !

### at
Retourne une copie de l'&eacute;l&eacute;ment pr&eacute;sent dans le vecteur &agrave; l'index donn&eacute;.
```c
void	*vector_at(t_vector *self, int request);

self->at(self, 5);
```

### front
Retourne le premier &eacute;l&eacute;ment du vecteur.
```c
void	*vector_front(t_vector *self);

self->front(self);
```
>  Toute modification sera enregistr&eacute;e dans le vecteur.


### back
Retourne le dernier &eacute;l&eacute;ment du vecteur.
```c
void	*vector_back(t_vector *self);

self->back(self);
```
>  Toute modification sera enregistr&eacute;e dans le vecteur.

### data
Retourne l'&eacute;l&eacute;ment du vecteur &agrave; l'index donn&eacute;.
```c
void	*vector_data(t_vector *self, int request);

self->data(self, 5);
```
>  &Agrave; l'inverse de `at()`, `data()` permet d'enregistrer dans le vecteur toutes les modifications faites sur le pointeur de retour.


### each
Retourne chaque &eacute;l&eacute;ment du vecteur (avec un appel en boucle). La m&eacute;moire du vecteur sera affect&eacute;e.
```c
void	*c_vector_each(t_vector *self);

while ((ptr = self->each(self)))
      do_stuff(ptr);

```
>  Notez que vous n'avez pas besoin de compteur, `NULL` sera renvoy&eacute; une fois le vecteur parcouru.

### map
Applique une fonction sur chaque &eacute;l&eacute;ment du vecteur.
```c
void	c_vector_map(t_vector *self, void (*fct)(void *elt));

self->map(self, &affiche_nom);
```
>  Un seul appel &agrave; la fonction est n&eacute;cessaire.

### remove
Supprime un &eacute;l&eacute;ment &agrave; un index donn&eacute;.
```c
int		c_vector_remove(size_t i, t_vector *self);

self->remove(5, self);
```
>  Tous les &eacute;l&eacute;ments &agrave; droite seront d&eacute;cal&eacute;s vers la gauche.

Si jamais vous &ecirc;tes arriv&eacute;s l&agrave; par hasard, le lien vers la librairie : [c_vector][c_vector]

Cheers & Octocats !

[vector]: http://www.cplusplus.com/reference/vector/vector/
[c_vector]: https://github.com/WeAreMuffin/c_vector
