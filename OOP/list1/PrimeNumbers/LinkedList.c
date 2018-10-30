//
// Created by pawel on 04.10.18.
//

#include <stdlib.h>
#include "LinkedList.h"


linkedList* initList(unsigned long long val){
    linkedList* list = malloc(sizeof(linkedList));
    list->next = NULL;
    list->value=val;
    list->tail=list;
    return list;
}

void append(linkedList** list, unsigned long long val) {
    if(*list == NULL){
        *list = initList(val);
    }
    linkedList* newElem = malloc(sizeof(linkedList));
    (*list)->tail->next = newElem;
    (*list)->tail = newElem;
    newElem->value=val;
    newElem->next=NULL;
}