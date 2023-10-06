//Alix Domange

#include "list.h"
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>


ListNode* create_listNode(data_t d){
    ListNode* newItem = (ListNode*) malloc(sizeof(Listnode));
    newItem->data = d;
    newItem->prev = newItem->next = NULL;
    return newItem;
}

// constructs a new (empty) list
List *list_create(void) {
    List *l = malloc(sizeof(List));
    l->first = l->last = NULL;
    return l;
}

// counts the items on a list
size_t list_count(const List *list) {
    size_t count = 0;

    ListNode *p=list->first;
    while(p!=NULL) {
        count++;
        p=p->next;
    }

    return count;
}

// inserts item_data at *end* of a list
void list_addlast(List *list, data_t item_data) {

    if(list->last==NULL){
        list->last->data = item_data;
    }
    else{
        List* newList = list_create();
        newList->first->data = item_data;
        newList->first->next = newList->last;
        list->last->next = newList->first;
    }
}


// removes the item from *end* of the list and returns its value
data_t list_rmlast(List *list) {
    if(list->last!=NULL){
        int value=list->last->data;
        list->last=NULL;
    }
    return -1;
}



int main(void) {

    List *l = list_create();

    assert(list_count(l)==0);

    list_addlast(l,10);
    list_addlast(l,20);
    list_addlast(l,30);
    list_addlast(l,40);

    assert(list_count(l)==4);

    list_print(l);

    data_t t =  list_rmlast(l);

    assert(t==40);
    list_print(l);

    return 0;
}