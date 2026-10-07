#include <stdio.h>
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
    int size; 
};

typedef struct iterator{
    list_t *list;
    node_t *node;
} list_iterator_t;

//new_node er "head"

node_t *create_node(void *item) { //tom node som blir definert, 
    node_t *new_node = (node_t*)malloc(sizeof(node_t)); //allokert plass til ny node.
    if (new_node == NULL)
    {
        printf("Memory allocation error / Didnt Find node please try again:"); //didnt find node
        return;
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
        return;

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
    node_t *new_node =create_node(item);
    if (new_node ==NULL)
        return; //dersom malloc feiler
    
    new_node->next = list->head;
    list->head = new_node;

    list->size++;
}


/*
 * Adds an item last in the provided list.
 */
void list_addlast(list_t *list, void *item) {
    node_t *new_node =create_node(item);
    if (new_node ==NULL)
        return; //dersom malloc feiler
    
    list->tail->next = new_node;
    list->tail = new_node;

    list->size++;

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
    if (prev == NULL) {
        return;
    }
    node_t *node = prev->next;

    prev->next = node->next;
    free (node);

    list->size--;
}

// Returnerer forrige node, som matchet item
node_t* list_find(list_t* list, void* item){

    node_t *prev;
    for (node_t *node = list->head; node != NULL;) {
        if (node->data == item) {
            return (prev);
        }

        prev = node;
        node = node->next;
    }

    return (NULL);
}


/*
 * Return the number of items in the list.
 */
int list_size(list_t *list){
 

    //
    return (list->size);
}




/*
 * List iterator interface
 */
 

/*
 * Return a newly created list iterator for the given list.
 */
list_iterator_t *list_createiterator(list_t *list){
    // malloc for iter
    list_iterator_t *iter = malloc (sizeof(list_iterator_t));

    iter->list = list;
    iter = list->head;

    return (iter);
}

/*
 * Free the memory for the given list iterator.
 */
void list_destroyiterator(list_iterator_t *iter){
    if (iter != NULL){
        free(iter);
    }
}

/*
 * Move iterator to next item in list and return current.
 */
void *list_next(list_iterator_t *iter){
    //spesial tilfelle
    node_t *current = iter->node;
    if (current == NULL) {
        return NULL;
    }

    iter->node = iter->node->next;

    return (current);
}

/*
 * Let iterator point to first item in list again.
 */
void list_resetiterator(list_iterator_t *iter){
    iter->node = iter->list->head;
}


// implement the functions from list.h here
