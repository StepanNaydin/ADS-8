// Copyright 2021 NNTU-CS
#include "train.h"

Train::Train() : countOp(0), first(nullptr) {}

void Train::addCage(const bool light) {
    Cage* elem = new Cage;
    elem->light = light;
    if (!first) {
        first = elem;
        first->next = first;
        first->prev = first;
    } else {
        Cage* p = first->next;
        elem->next = p;
        first->next = elem;
        elem->prev = first;
        p->prev = elem;
    }
}

int Train::getLength() {
    int a = 1;
    Cage* p = first;
    p = p->next;
    while (p != first) {
        p = p->next;
        a++;
    }
    return a;
}

int Train::getOpCount() {
    return countOp;
}
