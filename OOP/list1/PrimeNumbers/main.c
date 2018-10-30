#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"

void findPrimes(unsigned long long min, unsigned long long max) {
    linkedList *list=NULL, *temp;

    unsigned long long i;
    int isPrime;
    for (i = 2; i <= max; ++i) {
        temp = list;
        isPrime = 1;
        while (temp != NULL) {
            if (i % temp->value == 0) {
                isPrime = 0;
                break;
            }
            temp = temp->next;
        }
        if (isPrime) {
            append(&list, i);
            if (i >= min) {
                printf("%llu,", i);
            }
        }
    }
    printf("\n");
}

int main(int argc, char* argv[]) {
    findPrimes(strtoull(argv[1], NULL, 10), strtoull(argv[2], NULL, 10));
    return 0;
}