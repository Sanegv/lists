#include "listes.h"

int main(){
    //init
    Liste *l =  init();

    //fonctions
    printListe(l);

    addFirst(l, 5);
    addFirst(l,42);
    addFirst(l, 5301);
    insert(l, 11235, seek(l,42));
    printListe(l);
    printf("%d\n",getSize(l));
    delElem(l, seek(l,42));
    printListe(l);
    printf("%d\n",getSize(l));

    delFirstElem(l);
    printListe(l);
    addLast(l, 1789);
    printListe(l);

    //frees & return
    delListe(l);
    return 0;
}