#include "listes.h"

Liste *init(){
    Liste *l = malloc(sizeof(Liste));
    Elem *e = malloc(sizeof(Elem));

    if(l == NULL || e == NULL)
        exit(EXIT_FAILURE);

    l->size = 0;
    e->i = 0;
    e->next = NULL;
    l->first = e;
    l->size++;

    return l;
}

void addFirst(Liste *l, int newInt){
    Elem *e = malloc(sizeof(Elem));
    if(l == NULL || e == NULL)
        exit(EXIT_FAILURE);
    e->i = newInt;

    e->next = l->first;
    l->first = e;
    l->size++;
}

void delFirstElem(Liste *l){
    if(l == NULL)
        exit(EXIT_FAILURE);

    if(l->first != NULL){
        Elem *del = l->first;
        l->first = l->first->next;
        free(del);
        l->size--;
    }
}

void printListe(Liste *l){
    if(l == NULL)
        exit(EXIT_FAILURE);

    Elem *e = l->first;

    while(e != NULL){
        printf("%d -> ",e->i);
        e = e->next;
    }
    printf("NULL\n");
}

void delListe(Liste *l){
    if(l == NULL)
        exit(EXIT_FAILURE);
    
    while(l->first != NULL)
        delFirstElem(l);
    
    free(l);
}

int getSize(Liste *l){
    return l->size;
}

Elem *seek(Liste *l, int wanted){
    if(l == NULL)
        exit(EXIT_FAILURE);
    
    Elem *e = l->first;
    while(e->next != NULL){
        if(e->i == wanted)
            return e;
        e = e->next;
    }
    return NULL;
}

void insert(Liste *l, int newInt, Elem *insert){
    if(l == NULL || insert == NULL)
        exit(EXIT_FAILURE);
    
    Elem *e = l->first;
    while(e != NULL){
        if(e == insert){
            Elem *new = malloc(sizeof(Elem));
            new->i = newInt;

            new->next = e->next;
            e->next = new;
            l->size++;
            return;
        }
        e = e->next;
    }
    printf("Elem not in Liste\n");
}

void delElem(Liste *l, Elem *del){
    if(l == NULL || del == NULL)
        exit(EXIT_FAILURE);
    
    if(l->first == NULL){
        delFirstElem(l);
        return;
    }

    Elem *e = l->first;
    while(e != NULL){
        if(e->next == del){
            e->next = e->next->next;
            free(del);
            l->size--;
        }
        e = e->next;
    }
    printf("Elem not in list\n");
}

void addLast(Liste *l, int newInt){
    if(l == NULL)
        exit(EXIT_FAILURE);
    
    if(l->first == NULL){
        addFirst(l, newInt);
        return;
    }

    Elem *e = l->first;
    while(e->next != NULL)
        e = e->next;
    Elem *new = malloc(sizeof(Elem));
    new->next = NULL;
    new->i = newInt;
    e->next = new;
    l->size++;
}