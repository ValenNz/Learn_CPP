#include "Singlylist.h"

void createList(List &L) {
    L.first = Nil;
}

address alokasi(infotype x) {
    address P = new ElmList;
    if (P != Nil) {
        P->info = x;
        P->next = Nil;
    }
    return P;
}

void dealokasi(address &P) {
    delete P;
    P = Nil;
}

void insertFirst(List &L, address P) {
    if (P != Nil) {
        P->next = L.first;
        L.first = P;
    }
}

void insertLast(List &L, address P) {
    if (P != Nil) {
        if (L.first == Nil) {
            L.first = P;
        } else {
            address last = L.first;
            while (last->next != Nil) {
                last = last->next;
            }
            last->next = P;
        }
    }
}

void insertAfter(List &L, address P, address Prec) {
    if (P != Nil && Prec != Nil) {
        P->next = Prec->next;
        Prec->next = P;
    }
}

void deleteFirst(List &L, address &P) {
    if (L.first != Nil) {
        P = L.first;
        L.first = P->next;
        P->next = Nil;
        dealokasi(P);
    } else {
        P = Nil;
    }
}

void deleteLast(List &L, address &P) {
    if (L.first != Nil) {
        address prec = Nil;
        address last = L.first;

        while (last->next != Nil) {
            prec = last;
            last = last->next;
        }

        if (prec == Nil) {
            // Hanya terdapat 1 elemen di dalam list
            L.first = Nil;
        } else {
            prec->next = Nil;
        }

        P = last;
        dealokasi(P);
    } else {
        P = Nil;
    }
}

void deleteAfter(List &L, address &P, address Prec) {
    if (Prec != Nil && Prec->next != Nil) {
        P = Prec->next;
        Prec->next = P->next;
        P->next = Nil;
        dealokasi(P);
    } else {
        P = Nil;
    }
}

void printInfo(List L) {
    address P = L.first;
    while (P != Nil) {
        cout << P->info << " -> ";
        P = P->next;
    }
    cout << "Nil" << endl;
}