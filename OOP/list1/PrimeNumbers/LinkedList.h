//
// Created by pawel on 04.10.18.
//

#ifndef PRIMENUMBERS_LINKEDLIST_H
#define PRIMENUMBERS_LINKEDLIST_H

typedef struct linkedList{
    unsigned long long value;
    struct linkedList *next;
    struct linkedList *tail;
} linkedList;


void append(linkedList** list, unsigned long long val);
linkedList* initList(unsigned long long val);
#endif //PRIMENUMBERS_LINKEDLIST_H