#include <stdio.h>
#include <stdlib.h>
#include "list.h"

/*
 * List interface
 */
typedef struct node node_t;
struct node {/*korsn som helst type data*/
    void *data; //peker til void som er korsen som betyr at den peker til korsen som helst data type. 
    struct node *next; //peker mot neste node 
};




struct list{
    struct node *head;
    struct node *tail;
    int size; // trengs av andre funksjoner som jeg har lagd, men ikke av selve funksjonen
};


typedef struct iterator{ //den funksjonen som går videre
    list_t *list;
    node_t *node;
} list_iterator_t;

//new_node er "head"

node_t *create_node(void *item) { //tom node som blir definert, 
    node_t *new_node = (node_t*)malloc(sizeof(node_t)); //allokert plass til ny node.
    if (new_node == NULL)
    {
        printf("Memory allocation error / Didnt Find node please try again:"); //didnt find node
        return NULL;
    }
    new_node->data=item;
    new_node->next=NULL;
    return new_node; 
}


/*
 * Returns a newly created, empty list.
 */
list_t *list_create(void){
    list_t *newList = (list_t*)malloc(sizeof(list_t)); //allokert plass til "new list variabel"
    if (newList == NULL)
    {
        printf("Memory allocation error / Didnt Find node please try again:"); //didnt find node
        return NULL;

    }
newList->head = NULL;
newList->tail = NULL; 
newList->size= 0;
return newList; 



};

/*
 * Frees the list; list and nodes, but not the items it holds.
 vet ikke hva å gjøre her og hvorfor
 */
void list_destroy(list_t *list){ //skal frigjøre minnet som lista bruker (liste + noder), men ikke elementene i lista, altså det skal frigjøres plass
    node_t *current = list->head; // si at 
    node_t *next_node; //intiialiser next node

    while (current != NULL){
        next_node = current->next;
        free (current);
        current = next_node;
    }

    free (list);
}



/*
 * Adds an item first in the provided list.
 */
void list_addfirst(list_t *list, void *item){
    node_t *new_node =create_node(item); //bruker funksjonen create node til å lage en node med data, og new node blir satt som det som blir lagd.
    if (new_node ==NULL)
        return; //dersom malloc feiler
    
    new_node->next = list->head; //new node peker på hode noden til å være neste node. 
    list->head = new_node; //gjort ny node til hode noden
    if (list->size == 0) //ingen noder i lista
      list->tail = new_node; //hvis det ikke er en annen node annen en header noden så er den hale hoden også (det er kun 1 boks)

    list->size++; //added 1 in the list size
}


/*
 * Adds an item last in the provided list.
 */
void list_addlast(list_t *list, void *item) {
    node_t *new_node =create_node(item); 
    if (new_node ==NULL)
        return; //dersom malloc feiler
    if (list->size == 0) {
      list->head = new_node; // could be more efficient needs to be the same as list_addfirst
      list->tail = new_node;
    } else {
    list->tail->next = new_node; //in a way being current
    list->tail = new_node;
    }

    list->size++; //lista blei 1 større --here we are.

}



/*
 * Removes an item from the provided list, only freeing the node.
 */
void list_remove(list_t *list, void *item) {
    // Spesial tilfellet
    if (list->head->data == item) {
        node_t *node = list->head->next;
        free (list->head);
        list->head = node;
        list->size--;
        return;
    }

    //normal tilfellet
    node_t *prev = list_find (list, item);
    if (prev == NULL) { //hvis vi ikke fant noe så ser vi ingenting
        return;
    }
    node_t *node = prev->next;

    prev->next = node->next; //vi ser på det som er på sidene.
    free (node);

    list->size--; //gjør størrelsen mindre 
}

// Returnerer forrige node, som matchet item
node_t* list_find(list_t* list, void* item){ //søke funksjonen

    node_t *prev;
    for (node_t *node = list->head; node != NULL;) { //sjekker om noden ikke er lik 0, kun 0 da det ikke er noder igjen 
        if (node->data == item) {
            return (prev);
        }
//if the function was non linear, as in A to b then b to A then this would probably be better but that means more lag
        prev = node; //lagrer den noden vi er i
        node = node->next; //den noden vi kommer til
    }

    return (NULL); //hvis vi ikke finner noe så returnerer vi ingen ting
}


/*
 * Return the number of items in the list.
 */
int list_size(list_t *list){
 

    //
    return (list->size); //tells you the size from the memory address
}




/*
 * List iterator interface
 */
 

/*
 * Return a newly created list iterator for the given list.
 */
list_iterator_t *list_createiterator(list_t *list){ //lager funksjonen som flytter fram og tilbake
    // malloc for iter
    list_iterator_t *iter = malloc (sizeof(list_iterator_t));

    iter->list = list; //velger hvilket liste vi vil gå gjennom
    iter->node = list->head; //peker på hode noden 

    return (iter);
}

/*
 * Free the memory for the given list iterator.
 */
void list_destroyiterator(list_iterator_t *iter){
    if (iter != NULL){
        free(iter); //sletter iteratoren, eller det som ligger i typdef struct iterator
    }
}

/*
 * Move iterator to next item in list and return current.
 */
void *list_next(list_iterator_t *iter){
    //spesial tilfelle
    node_t *current = iter->node; //current blir brukt om på nytt , iter peker på noden som vi befinner seg i no
    if (current == NULL) { //hvis den ikke eksisterer
        return NULL; //ingen ting
    }

    iter->node = iter->node->next;  //noden vi er på nå, den peker på minneaddressen , den velger et ny node å peke på node

    return (current->data);
}

/*
 * Let iterator point to first item in list again.
 */
void list_resetiterator(list_iterator_t *iter){
    iter->node = iter->list->head; //går inni iter så liste så head noden som iteratoren er i og starter på nytt
}


// implement the functions from list.h here
