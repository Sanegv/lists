#ifndef DEF_LISTES
#define DEF_LISTES

#include <stdlib.h>
#include <stdio.h>

//structs
typedef struct elem Elem;
struct elem {
    struct elem *next;
    int i;
};

typedef struct liste Liste;
struct liste{
    Elem *first;
    int size;
};

//fonctions
Liste *init();
void addFirst(Liste *l, int newInt);
void delFirstElem(Liste *l);
void printListe(Liste *l);
void delListe(Liste *l);
int getSize(Liste *l);
Elem *seek(Liste *l, int wanted);
void insert(Liste *l, int newInt, Elem *e);
void delElem(Liste *l, Elem *e);
void addLast(Liste *l, int newInt);

#endif