#include "Doublylist.h"

void createList(List &L) {
    L.first = Nil;
    L.last = Nil;
}

address alokasi(infotype x) {
    address P = new ElmList;
    P->info = x;
    P->next = Nil;
    P->prev = Nil; // Inisialisasi prev dengan Nil
    return P;
}

void dealokasi(address &P) {
    delete P;
    P = Nil;
}

void insertFirst(List &L, address P) {
    if (L.first == Nil) {
        L.first = P;
        L.last = P;
    } else {
        P->next = L.first;
        L.first->prev = P; // Update prev dari node pertama lama
        L.first = P;
    }
}

void insertLast(List &L, address P) {
    if (L.first == Nil) {
        L.first = P;
        L.last = P;
    } else {
        P->prev = L.last;
        L.last->next = P; // Update next dari node terakhir lama
        L.last = P;
    }
}

void insertAfter(List &L, address P, address Prec) {
    if (Prec != Nil) {
        P->next = Prec->next;
        P->prev = Prec;
        
        if (Prec->next != Nil) {
            Prec->next->prev = P; // Update prev dari node setelah Prec
        } else {
            L.last = P; // Jika Prec adalah last, maka P menjadi last baru
        }
        Prec->next = P;
    }
}

void deleteFirst(List &L, address &P) {
    if (L.first != Nil) {
        P = L.first;
        if (L.first == L.last) { // Hanya ada 1 elemen
            L.first = Nil;
            L.last = Nil;
        } else {
            L.first = P->next;
            L.first->prev = Nil; // Putus hubungan prev
        }
        P->next = Nil;
        dealokasi(P);
    }
}

void deleteLast(List &L, address &P) {
    if (L.first != Nil) {
        P = L.last;
        if (L.first == L.last) { // Hanya ada 1 elemen
            L.first = Nil;
            L.last = Nil;
        } else {
            L.last = P->prev;
            L.last->next = Nil; // Putus hubungan next
        }
        P->prev = Nil;
        dealokasi(P);
    }
}

void deleteAfter(List &L, address &P, address Prec) {
    if (Prec != Nil && Prec->next != Nil) {
        P = Prec->next;
        Prec->next = P->next;
        
        if (P->next != Nil) {
            P->next->prev = Prec; // Update prev dari node setelah P
        } else {
            L.last = Prec; // Jika P adalah last, maka Prec menjadi last baru
        }
        P->prev = Nil;
        dealokasi(P);
    }
}

void printInfo(List L) {
    address P = L.first;
    cout << "Forward : ";
    while (P != Nil) {
        cout << P->info;
        if (P->next != Nil) cout << " <-> ";
        P = P->next;
    }
    cout << " -> Nil" << endl;
}

void printInfoReverse(List L) {
    address P = L.last;
    cout << "Reverse : ";
    while (P != Nil) {
        cout << P->info;
        if (P->prev != Nil) cout << " <-> ";
        P = P->prev;
    }
    cout << " -> Nil" << endl;
}
